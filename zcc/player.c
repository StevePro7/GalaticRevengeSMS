#include "includes.h"

void DiePlayer()
{
	// Explosion
	InitSpawnedExplosion(playerx-16,playery-28,32,40,1);
	
	// Status
	playerstatus=PLAYER_DIE;
	playerdiecounter=0;
	
	// Speed
	playerspeedx=0;
	playerspeedy=0;
}

void DamagePlayer()
{
	#ifndef PLAYERINMUNE
	if(numplayers==0)
		DiePlayer();
	else
	#else
	numplayers++;
	#endif
	{
		// Rest energy
		if(numplayers<MAX_LIFES)
		numplayers--;
		
		// Status
		playerstatus=PLAYER_DAMAGED;
		playerspeedx=damagevelx[playerside];
		playerspeedy=damagevely[playerside];
		playerspeedz=DAMAGEVELZ;
		
		// Sound
		PlaySound(damage_psg,damage_psg_bank,1,SFX_CHANNEL3);
		
		// Barrom
		DoBarrom(16);
	}
}

void FallPlayer()
{
	// Status
	playerstatus=PLAYER_FALL;
	playerdiecounter=0;
	
	// Fix
	playerx+=8-(playerx%16);
	playery+=8-(playery%16);
	
	// Speed
	playerspeedx=0;
	playerspeedy=0;
	
	// This can happen
	playerinmunecounter=0;
	
	// The music
	PlaySound(fall_psg,fall_psg_bank,1,SFX_CHANNEL2);
}

// Check damage with one enemy
void CheckPlayerDamageEnemy(enemy *en)
{
	enemydef *ed=en->ed;
	
	// If this enemy can damage us
	if(!en->ed->dangerous)return;

	// Check Z
	if(playerz>en->posz+32)return;
	if(playerz+32<en->posz)return;
	
	//Check if out... more easy!
	if(playerx>=en->posx+(ed->width>>1))return;
	if(playerx<=en->posx-(ed->width>>1))return;
	if(playery<=en->posy-16)return;
	if(playery>=en->posy+8)return;

	// Custom damage
	if(ed->ecf!=0)
		(*(ed->ecf))(en);
	else
		// Damage!
		DamagePlayer();	
}

// Check damage of player with enemies
void CheckPlayerDamage()
{
	signed char a;
	
	if(playerstatus!=PLAYER_DIE && playerstatus!=PLAYER_FALL && playerstatus!=PLAYER_DAMAGED && playerstatus!=PLAYER_DAMAGEDB)
	{
		if(playerinmunecounter==0)
		{
			{
				// Check all enemies
				if(numenemies>0)
					for(a=numenemies-1;a>=0;a--)
						CheckPlayerDamageEnemy(&enemies[a]);
			}
		}
		else 
		{
			playerinmunecounter--;
			CheckPlayerTiling();
		}
	}
}

// Draw fall player
void DrawFallPlayer()
{
	unsigned char a;
	
	// IF fall, We know
	if(playerstatus==PLAYER_FALL)
	{
		// Falling, timered sprite
		a=playerdiecounter>>3;a<<=2;
		DrawInMapSpriteArray(PLAYERFALLBASE+a,playerx-8,playery-8,16,16);
	}	
}

// Draw player
void DrawPlayer()
{
	unsigned char a;

	// Filter drawing
	if(!drawplayer)return;
	
	// If die, does not draw nothing
	if(playerstatus==PLAYER_DIE || playerstatus==PLAYER_FALL)return;

	// Player standard modes
	if(playerinmunecounter%2==0)
	{
		// Get the player base
		a=playerbases[playerside];

		if(playerstatus==PLAYER_WALK)
		{
			// Draw entire player
			if(!playerkeymoved)
				DrawInMapSpriteArray(a,playerx-8,playery-20,16,24);
			else
			{
				// Draw head
				DrawInMapSpriteArray(a,playerx-8,playery-20,16,8);
				
				// Draw foots
				DrawInMapSpriteArray(a+footanim[stageframe8div%4],playerx-8,playery-20+8,16,16);
			}
		}
		else
		{
			// Jump, damage... entire player
			DrawInMapSpriteArray(a,playerx-8,playery-20-(playerz>>1),16,24);
		}
		
		// Shadow
		DrawInMapSprite(SHADOWBASE,playerx-4,playery);
	}
}

// Hearts
void UpdatePlayerIndicators()
{
	// Hearts
	for(unsigned char a=0;a<numplayers;a++)
		SMS_addSprite(244-a*8,4,PLAYERINDICATORBASE);
	
	// Coin
	SMS_addSprite(244-16,16,PLAYERCOINBASE);
	
	// Number of coins
	SMS_addSprite(244-8,16,NUMBERSBASE+(playercoins/10));
	SMS_addSprite(244,16,NUMBERSBASE+(playercoins%10));
}

// Init a player
void InitPlayer(unsigned int x, unsigned int y, unsigned char side)
{
	// Set draw to on
	drawplayer=1;
	
	// Set position
	playerx=x;
	playery=y;
	playerz=0;
	
	// Fixing some errors i do not have now :)
	playerspeedx=0;
	playerspeedy=0;
	playerspeedz=0;
	
	// Side
	playerside=side;
	
	// Keymoved
	playerkeymoved=0;
	
	// Counters and so on
	playerdiecounter=0;
	playerinmunecounter=0;
	
	#ifdef USEPLAYERSHOOTCOUNTER
		playershootcounter=0;
	#endif
	
	// Status
	playerstatus=PLAYER_WALK;
	
	// Always have to be floor
	playertile=TILE_FLOOR;
	
	// Misc sprites
	if((numstage<2)&&(playertype==3))
		LoadSprite(playersprites[4], PLAYERBASE,playerspritesbank[4]);
	else
		LoadSprite(playersprites[playertype], PLAYERBASE,playerspritesbank[playertype]);
	LoadSprite(playerfallsprites[playertype], PLAYERFALLBASE,playerfallspritesbank[playertype]);	

	// Indicators
	LoadSprite(playerindicator_zx7, PLAYERINDICATORBASE,playerindicator_zx7_bank);	
	LoadSprite(coin_zx7, PLAYERCOINBASE,coin_zx7_bank);	
	LoadSprite(numbers_zx7, NUMBERSBASE,numbers_zx7_bank);
}

unsigned char UpdatePlayerDie()
{
	return (playerdiecounter++>=64?2:0);
}

unsigned char UpdatePlayerWalk()
{
	if(playertile==TILE_FLOOR)
	{
		// Save last position
		lastplayerx=playerx;
		lastplayery=playery;
		lastplayerside=playerside;
	}
	
	// Same as walk
	UpdatePlayerDirection();
	
	// Check for jump
	if((keystatus&button1)&&(playerjumpreleased==0)&&(cannotjump==0))
	{
		playerstatus=PLAYER_JUMP;
		playerspeedz=PLAYERJUMPFORCE;
		playerjumpreleased=1;
		PlaySound(jump_psg,jump_psg_bank,1,SFX_CHANNEL3);
	}	
	else
	{
		if(playertile==TILE_EMPTY)
			if(CheckPlayerPlatforms()==0)
				FallPlayer();
	}
			
	// OK
	return 0;
}

void UpdatePlayerDirection()
{
	unsigned char a;
	
	// Default speed
	playerspeedx=0;
	playerspeedy=0;

	// Keymoved
	playerkeymoved=0;

	// Save player orientation
	a=0;

	// If its shooting
	#ifdef USEPLAYERSHOOTCOUNTER
	if(!playershootcounter)
	{
	#endif
		// Check movement
		if(keystatus&PORT_A_KEY_LEFT)
		{
			playerspeedx=-PLAYERWALKSPEED;
			a=PLAYER_LEFT;
		}
		else if(keystatus&PORT_A_KEY_RIGHT)
		{
			playerspeedx=PLAYERWALKSPEED;
			a=PLAYER_RIGHT;
		}
		if(keystatus&PORT_A_KEY_UP)
		{
			playerspeedy=-PLAYERWALKSPEED;
			a+=PLAYER_UP;
		}
		else if(keystatus&PORT_A_KEY_DOWN)
		{
			playerspeedy=PLAYERWALKSPEED;
			a+=PLAYER_DOWN;
		}

		// Update side
		if(a!=0)
		{
			playerside=a;
			playerkeymoved=1;
		}

		// Player shoot
		if((keystatus&button2)&&(playershootreleased==0))
		{
			#ifdef USEPLAYERSHOOTCOUNTER
				// Default time to player shoot
				playershootcounter=PLAYERSHOOTCOUNTERDEFAULT;
			#endif
			
			// Mark this
			playershootreleased=1;
			
			// Create player shoot
			CreatePlayerShoot();
		}
	#ifdef USEPLAYERSHOOTCOUNTER		
	}
	else
	{
		// Decrease player shoot counter
		if(playershootcounter>0)playershootcounter--;
	}
	#endif
}

void UpdatePlayerFall()
{
	if(playerdiecounter++>=23)
	{
		#ifndef PLAYERINMUNE
		if(numplayers==0)
		{
			playerstatus=PLAYER_DIE;
			playerdiecounter=0;
		}
		else
		#else
		numplayers++;
		#endif
		{
			if(numplayers<MAX_LIFES)
				numplayers--;
			playerx=lastplayerx;
			playery=lastplayery;
			playerz=0;
			playerside=lastplayerside;
			playerstatus=PLAYER_WALK;
			playertile=TILE_FLOOR;
			playerinmunecounter=PLAYERINMUNITYTIME;
		}
	}
}

void CheckPlayerTiling()
{
	if(playerstatus==PLAYER_WALK)
	{
		// Check for dead
		if(playerinmunecounter==0)
		{
			if(playertile==TILE_DEAD)
				DamagePlayer();
		}
	
		// Fall
		if(playertile==TILE_EMPTY)
			if(CheckPlayerPlatforms()==0)
				FallPlayer();
	}
}

void UpdatePlayerDamaged(unsigned char phase)
{
	playerspeedz-=GRAVITY;
	playerz+=playerspeedz;
	if(playerz>230)
	{
		playerz=0;
		
		if(phase==0)
		{
			// Back to walk
			playerstatus=PLAYER_WALK;
			CheckPlayerTiling();
		}
		else if(phase==1)
		{
			// Second jump
			playerspeedz=DAMAGEVELZB;
			playerstatus=PLAYER_DAMAGEDB;
		}
		else
		{
			// Back to walk
			playerstatus=PLAYER_WALK;
			playerinmunecounter=PLAYERINMUNITYTIME;
			CheckPlayerTiling();
		}
	}
}

void UpdatePlayerJump()
{
	// Same as walk
	UpdatePlayerDirection();
	
	// Update Z Position
	UpdatePlayerDamaged(0);
}

unsigned char UpdatePlayer()
{
	unsigned char a;

	// Update hearts
	UpdatePlayerIndicators();

	// Filter
	if(!drawplayer)return 0;
	
	// Check if release
	if(!(keystatus&button2))playershootreleased=0;

	// Check if release
	if(!(keystatus&button1))playerjumpreleased=0;

	switch(playerstatus)
	{
		case PLAYER_DAMAGED:
			UpdatePlayerDamaged(1);
		break;
		case PLAYER_DAMAGEDB:
			UpdatePlayerDamaged(2);
		break;
		case PLAYER_DIE:
			return UpdatePlayerDie();
		break;
		case PLAYER_WALK:
			UpdatePlayerWalk();
		break;
		case PLAYER_JUMP:
			UpdatePlayerJump();
		break;
		case PLAYER_FALL:
			UpdatePlayerFall();
		break;
	}
	
	// Floating tiles
	if(playerstatus==PLAYER_WALK)
		CheckTiling(&playerspeedx,&playerspeedy,playertile);
	
	// Add flying platform moves
	playerspeedx+=playerplatformx;
	playerspeedy+=playerplatformy;
	
	// Reset
	playerplatformx=0;
	playerplatformy=0;
	
	// Movement & update tile
	a=CheckMovement(&playerx,&playery,&playerspeedx,&playerspeedy);
	
	// Check if tile changed
	if(a!=0)
	{
		// Assign tile
		playertile=a;

		// Only for walk
		CheckPlayerTiling();

		// Check exit
		if(stageexitable==1)
			if(playertile==TILE_EXIT)
				return 1;
	}
	
	// Everything OK
	return 0;
}


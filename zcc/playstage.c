#include "includes.h"

void setstageexitable(unsigned char ss)
{
	stageexitable=ss;
	if(ss==0)
	{
		stagetiletypes=stagetiletypesa;
		if(numstage==0)
			LoadSprite(forbidtilesa_zx7,272,forbidtilesa_zx7_bank);
		else
			LoadSprite(forbidtilesb_zx7,298,forbidtilesb_zx7_bank);
	}
	else
	{
		stagetiletypes=stagetiletypesb;
		if(numstage==0)
			LoadSprite(exittilesa_zx7,272,exittilesa_zx7_bank);
		else
			LoadSprite(exittilesb_zx7,298,exittilesb_zx7_bank);
	}
}

void InitGameConfig(unsigned char iscontinue)
{
	// Default values
	numplayers=gamestock;	
	playercoins=0;
	
	// If it were continue...
	if(iscontinue==1)
	{
		numstage=laststage;
	}
	else
	{
		numstage=0;
		playertype=3;		
	}
}

void InitPlayStage()
{
	const stagedef *sd;
	
	// General init
	InitStage(0);

	// Do not Prevent dialogs cut
	ingame=1;

	// No puede saltar
	if(numstage==1)
		cannotjump=1;
	else 
		cannotjump=0;


	// For continues
	laststage=numstage;
	
	// By defect, no
	stagestopped=0;
	
	// By defect, yes
	stoppedstageexitonkey=1;
	
	// Get stage definition pointer
	sd=&stagesdefinition[numstage];

	// Cargamos los graficos a la pantalla
	LoadSprite(sd->stagetiles,256,sd->stagetilesbank);
	
	// Explosiones
	InitExplosions();

	// El map
	InitMap(sd->stagetilemap,sd->stagetilemapbank,sd->stagetilemappings,sd->stagewidth,sd->stageheight,sd->stageplayerinitx,sd->stageplayerinity,sd->stagetiletypesa,sd->stagetiletypesb);

	// GEt default exitable
	setstageexitable(sd->exitablestage);
	
	// El player
	InitPlayer(sd->stageplayerinitx<<4,sd->stageplayerinity<<4,sd->stageplayerside);

	// Enemies
	InitEnemies();
	
	// Platforms
	InitPlatforms(sd->numplatforms,sd->platforms);
	
	// Enemy Slots
	InitEnemySlots(sd->enemies,sd->numenemies,sd->enemysprites,sd->numenemysprites);

	// Enemys/NPC?
	UpdateEnemySlots();

	// Load shadow
	LoadSprite(shadow_zx7, SHADOWBASE,shadow_zx7_bank);	
	
	// Init coins & hearts
	InitGoodies();
	
	// Init player shoots
	InitPlayerShoots();
	
	// Init enemy shoots
	InitEnemyShoots();
	
	// Music
	if((sd->stagemusic!=lastplayedmusic)||(sd->stagemusicbank!=lastplayedmusicbank))
		PlayMusic(sd->stagemusic,sd->stagemusicbank,1);
	
	// Save stage custom func
	stageupdatecustomfunc=sd->stageupdatecustomfunc;
	
	// Load palette
	DoFadeIn(sd->stagepalette,sd->stagepalettebank);

	// Bucle
	while(1)
	{
		// Check for pause
		checkgamepause();

		// Scroll
		if(gamepause==0)
		{
			// Update stage
			UpdateStage();

			// Update side cols and rows
			if(stageframe2mod==0)
			{
				// Move map
				if(!stagestopped)
				{
					// Update Scroll
					SMS_setBGScrollX((-mapposx+barromposx)%256);
					SMS_setBGScrollY((mapposy+barromposy)%224);
					
					// Run init stage custom func
					if(stageupdatecustomfunc!=0)
						(*(stageupdatecustomfunc))();

					// Update cols
					UpdateSideMapX();
					UpdateSideMapY();

					// Update collisions
					if(stageframe8mod==2)
						CheckPlayerShootDamage();
					if(stageframe8mod==4)
						CheckEnemyShootDamage();
					if(stageframe8mod==6)
						CheckGoodieDamage();
					else
						CheckPlayerDamage();
						

					// Wall collisions on shoots
					if(stageframe4mod==2)
						CheckShootWalls(playershoots,&numplayershoots);
					else
						CheckShootWalls(enemyshoots,&numenemyshoots);
					
					// Move map
					MoveMapX(playerx-MAPOFFSETX-mapposx);
					MoveMapY(playery-MAPOFFSETY-mapposy);
					
					// Enemies
					UpdateEnemies();	

					// Enemy shoots					
					UpdateEnemyShoots();
					
					// Explosions
					if(stageframe4mod==0)
						UpdateExplosions();
					
					// Barrom
					UpdateBarrom();	
				
					// Update player
					switch(UpdatePlayer())
					{
						case 1:
							numstage++;
							return;
						break;
						case 2:
							numstage=GAMEOVER_STAGE;
							return;
						break;
					}

					// Player shoot
					UpdatePlayerShoots();
				}
				else UpdateStoppedStage();

				// Enemies upper
				DrawEnemiesB();

				// Player
				DrawPlayer();				

				// Enemies below
				DrawEnemiesA();
				
			}
			else
			{
				// Goodies
				UpdateGoodies();
				
				// Update rows
				if(!stagestopped)
				{
					// Platforms
					UpdatePlatforms();
					
					// Player falling
					DrawFallPlayer();
				}
			}
		}
		else
		{
			// Sound, keyboard
			keystatus=SMS_getKeysStatus(); 	

			// Wait for vblank
			SMS_waitForVBlank();
		}
		//WriteNumber(numplayershoots,2,1,1);
	}
}

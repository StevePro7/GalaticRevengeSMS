#include "includes.h"

void modifybalouty(unsigned char py)
{
	if(abs(baloutbally-py)<6)return;
	if(baloutbally<py)
		baloutvely--;
	else
		baloutvely++;
	
	if(baloutvely<-baloutvel)baloutvely=-baloutvel;
	if(baloutvely>baloutvel)baloutvely=baloutvel;
}


void baloutmoveplayer()
{
	if((keystatus&PORT_A_KEY_UP)&&(baloutposy>52))baloutposy-=2;
	if((keystatus&PORT_A_KEY_DOWN)&&(baloutposy<116))baloutposy+=2;
}

void baloutmoveenemy()
{
	if((baloutbally<baloutbposy-12)&&baloutbposy>52)baloutbposy--;
	if((baloutbally>baloutbposy+12)&&baloutbposy<116)baloutbposy++;
}

void baloutmoveball()
{
	// Move
	baloutballx+=baloutvelx;
	baloutbally+=baloutvely;
	
	// Up collision
	if(baloutbally<=44)
	{
		baloutbally=44;
		baloutvely=-baloutvely;
	}
	
	// Down collision
	if(baloutbally>=124)
	{
		baloutbally=124;
		baloutvely=-baloutvely;
	}
	
	// Left ending
	if(baloutballx<76)
	{
		if(abs(baloutbally-baloutposy)<16)
		{
			modifybalouty(baloutposy);
			baloutvelx=abs(baloutvelx);
		}
	}
	
	// Left collision
	if(baloutballx<68)
	{
		ClearBackground(445);
		baloutstage=3;
	}
	
	// Right ending
	if(baloutballx>196)
	{
		ClearBackground(445);
		baloutlevel++;
		baloutstage=1;
	}
	
	// Right collision
	if(baloutballx>184)
	{
		if(abs(baloutbally-baloutbposy)<16)
		{
			baloutvelx=-abs(baloutvelx);
			modifybalouty(baloutbposy);
		}
	}
}

void FillBalout(unsigned char *m,unsigned char b)
{
	const unsigned int ballouttiles[]={445,443,324};
	
	// Our bank
	changeBank(b);
	
	// Jump line
	m+=(17*2);
	
	// Fill
	for(unsigned char y=0;y<13;y++)
	{
		// Init row
		SMS_setNextTileatXY (8,y+4);
		for(unsigned char x=0;x<17;x++)
		{
			// Set tile
			SMS_setTile(ballouttiles[m[0]]);
			m+=2;
		}
	}

	// Change bank
	changeBank(FIXEDBANKSLOT);
}


void baloutloadtitle()
{
	// Stop music
	StopSound();

	// Fill title
	FillBalout(balouttitle_bin,balouttitle_bin_bank);
	
	// Our label
	WriteText(baloutpressanykey,10,17);

	// See if jump to game
	if(keystatus&button1)
	{
		ClearBackground(445);
		baloutlevel=1;
		baloutstage++;
	}
}

void baloutshowstage()
{
	// Stop music
	StopSound();

	// Write stage label
	WriteText(baloutstagelabel,12,10);	
	WriteNumber(baloutlevel,2,18,10);	

	// See if jump to game
	if(keystatus&button2)
	{
		// The stage
		FillBalout(baloutfield_bin,baloutfield_bin_bank);
		baloutstage++;
		
		// Player
		baloutposy=11*8;
		baloutbposy=11*8;
		baloutframe=0;	

		// ball
		baloutballx=15*8;
		baloutbally=11*8;
		
		// Velocity
		baloutvel=(2+(baloutlevel>>2));
		if(baloutvel>5)baloutvel=5;
		
		// The angle
		baloutvelx=baloutvel;
		baloutvely=myRand()%2==0?baloutvel:-baloutvel;
		
		// Music
		PlayMusic(baloutbso_psg,baloutbso_psg_bank,1);
	}
}

void baloutupdatemap()
{
	// Frame
	baloutframe++;
	
	// Move things
	baloutmoveplayer();
	baloutmoveenemy();
	baloutmoveball();
	
	// Drawing
	DrawSpriteArray(ENEMYBASE+16,8*8,baloutposy-12,8,24,0);
	DrawSpriteArray(ENEMYBASE+19,24*8,baloutbposy-12,8,24,0);
	SMS_addSprite_callee(baloutballx-4,baloutbally-4,ENEMYBASE+22);
}

void baloutgameover()
{
	// Stop music
	StopSound();

	// Write stage label
	WriteText(baloutgameoverlabel,12,10);	

	// See if jump to game
	if(keystatus&button2)
		baloutstage++;
}

void PlayBalloid()
{
	// Reset position
	SMS_setBGScrollX(0);
	SMS_setBGScrollY(0);	
	
	// Fill background
	ClearBackground(445);
	
	// Cargamos los sprites de las paletas y la bola y el enemigo
	LoadSprite(balout_zx7, ENEMYBASE+16,balout_zx7_bank);
	
	// Los sprites
	ClearSprites();
	
	// Init vars
	baloutstage=0;
		
	// Loop
	while (baloutstage!=4)
	{
		// Update Function
		(*(baloutupdatefunctions[baloutstage]))();
		
		// Los sprites
		SMS_finalizeSprites(); 
		
		// Wait
		SMS_waitForVBlank();

		// Copy sprites
		UNSAFE_SMS_copySpritestoSAT();

		// Los sprites
		SMS_initSprites(); 
		
		// Get keys
		keystatus=SMS_getKeysStatus();
	}
	
	// Return to stage
	PlayMusic(stage3_psg,stage3_psg_bank,1);
		
	// Update position
	SMS_setBGScrollX(-mapposx%256);
	SMS_setBGScrollY(mapposy%224);
	
	// Redraw map
	DrawMap(25);
}

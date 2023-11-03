#include "includes.h"

///////////////////////////////////////////////////////////////////

// Intro functions

void AnimateStars(signed char f)
{
	unsigned char a;
	unsigned int b=48;
	
	for(a=0;a<10;a++)
		SMS_addSprite((introstarsx[a]-(f<<introstarsv[a]))%256,b+=8,INTROSTAR_BASE);
}

void IntroUpdateExplosions()
{
	if(stageframe4mod==0)
		UpdateExplosions();
}
	
void DrawLittleShips()
{
	// We draw here the planet slide to hide the ships
	DrawSpriteArray(INTROPLANETSLIDE_BASE,128,88,16,16,0);

	// Explosions update
	IntroUpdateExplosions();
	
	// The ships
	SMS_addTwoAdjoiningSprites_callee(stageframe-300,88,INTROLITTLESHIP_BASE);
}

void DrawShips(unsigned char move)
{
	unsigned char a;
	unsigned char ax;
	unsigned char ay;
	unsigned char bx;
	unsigned char by;
	unsigned char bs;

	// Explosions update
	IntroUpdateExplosions();
	
	// Our counter
	a=stageframe4div%3;
	
	// Ships params
	ax=(move==7)?68+introwaves[stageframe2div%128]:(move==8)?68+(stageframe<<1)-7500:68;
	ay=(move==0||move==7)?72+(introwaves[stageframe%128]>>1):72+16;
	bx=move==2?172+myRand()%8:176;
	by=move==0?100-(introwaves[stageframe%128]>>1):(move==2||move==5)?72+12+myRand()%8:72+12;
	bs=move==5?INTROBOSS_BASE+45:(move==3||move==4)?INTROBOSS_BASE+36:move==2?INTROBOSS_BASE+27:INTROBOSS_BASE+a*9;

	// My sprites
	DrawSpriteArray(INTROSHIP_BASE+a*6,ax,ay,24,16,0);
	if(move<6)DrawSpriteArray(bs,bx,by,24,24,0);
}

void introfunction0()
{
	// Fit screen
	LoadGraphics(intropalette1,FIXEDBANKSLOT,introtiles1_zx7,introtiles1_zx7_bank,introtilemap1_zx7,introtilemap1_zx7_bank,32*17);
}

void introfunction2()
{
	PlayMusic(littleships_psg,littleships_psg_bank,0);
	DrawLittleShips();
}

void introfunction3()
{
	DrawLittleShips();
}

void introfunction4()
{
	unsigned char a;
	
	if(stageframe%8==0)
	{
		InitExplosion(stageframe+96-384,88,0);
		a=((stageframe-384)/8);
		SMS_setNextTileatXY (12+a,11);
		SMS_setTile(BROKENPLANET_BASE+a);
	}
	DrawLittleShips();
}

void introfunction6()
{
	DrawLittleShips();
	PlayMusic(intro_psg,intro_psg_bank,0);
}

void introfunction9()
{
	DoFadeOut();
}

void introfunction10()
{
	// Fit screen
	LoadGraphics(intropalette2,FIXEDBANKSLOT,introtiles2_zx7,introtiles2_zx7_bank,introtilemap2_zx7,introtilemap2_zx7_bank,32*17);
}

void introfunction11()
{
	
	AnimateStars(stageframe);	
	DrawShips(0);
}

void introfunction12()
{
	AnimateStars(stageframe);	
	DrawShips(1);	
}

void introfunction13()
{
	PlayMusic(introlaser_psg,introlaser_psg_bank,0);	

	AnimateStars(stageframe);	
	DrawShips(2);		
}

void introfunction14()
{
	unsigned char a;
	
	AnimateStars(stageframe4div);	
	DrawShips(2);	
	
	if(stageframe%32==0)
		InitSpawnedExplosion(172,78,24,24,1);	
	
	// Laser
	for(a=0;a<3;a++)
		SMS_setBGPaletteColor(12+a,introlasercolors[(a+stageframe4div)%3]);
}

void introfunction15()
{
	unsigned char a;
	
	AnimateStars(stageframe);	
	DrawShips(3);	
	
	// Quit laser
	for(a=12;a<15;a++)
		SMS_setBGPaletteColor(a,intropalette2[a]);
}

void introfunction16()
{
	AnimateStars(stageframe);	
	DrawShips(4);	
}

void introfunction17()
{
	AnimateStars(stageframe);	
	DrawShips(4);

	// Final music
	PlayMusic(intro2_psg,intro2_psg_bank,0);
}

void introfunction18()
{
	AnimateStars(stageframe);	
	DrawShips(4);

	//Astronauta entra dentro
	SMS_addSprite(76+stageframe2div-1825,72+8+introastro[stageframe2div%16],INTROFLYINGMAN_BASE);
}

void endingfunction2()
{
	AnimateStars(stageframe);	
	DrawShips(4);

	//Astronauta sale fuera
	SMS_addSprite(191-stageframe2div+12,72+24-introastro[stageframe2div%16],INTROFLYINGMANB_BASE);
}


void endingfunction14()
{
	unsigned char a;
	
	AnimateStars(stageframe4div);	
	DrawShips(5);	
	
	if(stageframe%32==0)
		InitSpawnedExplosion(172,78,24,24,1);	
	
	// Laser
	for(a=0;a<3;a++)
		SMS_setBGPaletteColor(12+a,introlasercolors[(a+stageframe4div)%3]);
}

void endingfunction15()
{
	unsigned char a;
	
	AnimateStars(stageframe);	
	DrawShips(6);	
	
	// Quit laser
	for(a=12;a<15;a++)
		SMS_setBGPaletteColor(a,intropalette2[a]);
}

void endingfunction16()
{
	AnimateStars(stageframe);	
	DrawShips(6);	
	
	// The music
	PlayMusic(ending_psg,ending_psg_bank,0);	

}

void endingfunction17()
{
	AnimateStars(stageframe);	
	DrawShips(7);	
}

void endingfunction18()
{
	AnimateStars(stageframe);	
	DrawShips(8);	
	PlayMusic(warp_psg,warp_psg_bank,0);	
}

void endingfunction19()
{
	AnimateStars(stageframe);	
	DrawShips(8);	
}

void endingfunction20()
{
	AnimateStars(stageframe);	

	// The end
	DrawSpriteArray(INTROTHEEND_BASE,100,84,56,24,0);	
}

///////////////////////////////////////////////////////////////////

void LoadCommonIntroSprites()
{
	LoadSprite(introship_zx7,INTROSHIP_BASE,introship_zx7_bank);
	LoadSprite(introboss_zx7,INTROBOSS_BASE,introboss_zx7_bank);
	LoadSprite(introstar_zx7,INTROSTAR_BASE,introstar_zx7_bank);
	LoadSprite(introflyingman_zx7,INTROFLYINGMAN_BASE,introflyingman_zx7_bank);
	LoadSprite(introflyingmanb_zx7,INTROFLYINGMANB_BASE,introflyingmanb_zx7_bank);
	LoadSprite(introlittleship_zx7,INTROLITTLESHIP_BASE,introlittleship_zx7_bank);
	LoadSprite(planetslide_zx7,INTROPLANETSLIDE_BASE,planetslide_zx7_bank);
	LoadSprite(introtheend_zx7,INTROTHEEND_BASE,introtheend_zx7_bank);
}

void InitIntroStage(introdef *idef)
{
	// Reset
	stagestate=0;
	labelstate=0;

	// Prevent dialogs cut
	ingame=0;
	
	// Prevent gameover after ending
	numstage=EXIT_STAGE;
	
	// Reset stopped stage values
	stagestopped=0;
	stoppedstageexitonkey=0;
	
	// Reset map values
	mapposx=0;
	mapposy=0;
	
	// General init
	InitStage(1);

	// Cargamos los graficos a la pantalla
	LoadCommonIntroSprites();

	// Init explosions
	InitExplosions();
	
	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// Play?
		if((keystatus&button2)&&(idef!=&endingdefinition))
			return;
		
		// Our loop
		if(stageframe2mod==0)
		{
			// Call our function
			if(idef->functions[stagestate]!=0)
				(*(idef->functions[stagestate]))();
			
			// Jump state
			if(stageframe>=idef->statetime[stagestate])
			{
				stagestate++;
				
				// If we can exit
				if(stagestate==idef->exitstate)
					return;
			}
		}

		// Labels update
		UpdateStoppedStage();
	
		// New labels
		if(labelstate<idef->numlabels)
		if(stageframe==idef->labelstime[labelstate])
		{
			InitStoppedStage(&idef->labels[labelstate]);
			labelstate++;
		}
	}
}



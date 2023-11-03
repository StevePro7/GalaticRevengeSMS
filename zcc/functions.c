#include "includes.h"

// Set buttons	
void SetButtons(unsigned char inverse)
{
	buttoninverse=inverse;
	if(inverse==1)
	{
		button1=PORT_A_KEY_2;
		button2=PORT_A_KEY_1;
	}
	else
	{
		button1=PORT_A_KEY_1;
		button2=PORT_A_KEY_2;
	}
}
	
// Draw an array of chars
void PutChars(unsigned char x, unsigned char y,unsigned char w, unsigned char h,unsigned int l)
{
	unsigned char a;
	unsigned char b;
	
	// The array
	for(b=0;b<h;b++)
	{
		SMS_setNextTileatXY (x,y+b);
		for(a=0;a<w;a++)
		{
			SMS_setTile (l);
			l++;
		}
	}
}

// Dibuja un array de sprites
void DrawSpriteArray(unsigned char s,unsigned char px,unsigned char py,unsigned char tx, unsigned char ty,unsigned char t)
{
	unsigned char x;
	
	for(unsigned char y=0;y<ty;y+=8)
	{
		for(x=0;x<=tx-16;x+=16)
		{
			SMS_addTwoAdjoiningSprites_callee(px+x,py+y,s);
			s+=2;
		}
		if(tx-x==8)
		{
			SMS_addSprite_callee(px+x,py+y,s);
			s+=1;
		}
		s+=t;
	}
}

// Limpia los sprites
void ClearSprites()
{
	SMS_initSprites(); 
	SMS_finalizeSprites(); 
	SMS_copySpritestoSAT(); 
}

// Resetea las frames
void ResetStageFrames()
{
	stageframe=0;
}

// Inicia las interrupciones
void InitInterrupts(void)
{
	numinterrupts=0;
}

// Update del scroll
void UpdateScroll(unsigned char sx,unsigned char sy)
{
	SMS_setBGScrollX(sx);
	SMS_setBGScrollY(sy);
}

// Update del scroll
void ResetScroll()
{
	SMS_setBGScrollX(0);
	SMS_setBGScrollY(0);
}

// Change bank
void changeBank(unsigned char b)
{
	if(b!=lastbank)
	{
		SMS_mapROMBank(b);
		lastbank=b;
	}
}

// Mascaras del fading
const unsigned char palettefadeblack[]={0x3f,0x3b,0x37,0x33,0x23,0x13,0x03,0x02,0x01,0x00};
	
// Hacemos un fade
void DoPaletteFade(unsigned char a,const unsigned char *c, unsigned char b)
{
	unsigned char d;
	
	// Cambiamos el banco
	changeBank(b);
	
	// Apagamos las paletas
	for(d=0;d<16;d++)
		SMS_setBGPaletteColor(d,c[d]&palettefadeblack[a]);
	
	// Volvemos a palete_bin
	changeBank(FIXEDBANKSLOT);

	// Los sprites
	for(d=0;d<16;d++)
		SMS_setSpritePaletteColor(d,palette_bin[d]&palettefadeblack[a]);
}

// Fade out
void DoFadeOut()
{
	signed char a;
	
	if(usedlastpalette==1)
	{
		usedlastpalette=0;
		
		for(a=0;a<10;a++)
		{
			SMS_waitForVBlank();
			SMS_waitForVBlank();
			DoPaletteFade(a,lastpalette,lastpalettebank);	
		}
	}
}

// Fade in
void DoFadeIn(const unsigned char *palettefadepalette,unsigned char palettefadebank)
{
	signed char a;
	
	for(a=9;a>=0;a--)
	{
		SMS_waitForVBlank();
		SMS_waitForVBlank();
		DoPaletteFade(a,palettefadepalette,palettefadebank);
	}
	lastpalette=palettefadepalette;
	lastpalettebank=palettefadebank;
	usedlastpalette=1;
}

// Handler de interrupciones
void InterruptHandler(void)
{
	unsigned char oldbank=lastbank;
	
	// Update music
	if(musicbank)
	{
		changeBank(musicbank);
		PSGFrame();
	}

	// Update sounds
	if(PSGSFXGetStatus())
	{
		changeBank(soundbank);
		PSGSFXFrame();
	}

	SMS_mapROMBank(oldbank);

	numinterrupts++;
}

// Inicia la consola
void InitConsole()
{
	// La consola
	SMS_init();
	
	// We need this
	SMS_getKeysStatus();
	
	// Advanced frameskipping
	SMS_setLineInterruptHandler(&InterruptHandler);
	SMS_setLineCounter (180);
	SMS_enableLineInterrupt();
	
	// Kagesan asked for this ;)
	SMS_VDPturnOnFeature(VDPFEATURE_LEFTCOLBLANK);
//	SMS_VDPturnOnFeature(VDPFEATURE_LOCKHSCROLL);	
//	SMS_VDPturnOnFeature(VDPFEATURE_USETALLSPRITES);
	
	// More sprites for this game
	SMS_useFirstHalfTilesforSprites(1);
	
	// Turn on SMS VDP
	SMS_displayOn();
}

// Inicia una stage
void InitStage(unsigned char resetsound)
{
	// Do fadeout
	DoFadeOut();
	
	// Sonido quitado
	if(resetsound==1)
		StopSound();

	// Clear screen
	ClearScreen();

	// The font
	LoadSprite(font_zx7,448-48,font_zx7_bank);
	
	// Reseteamos el estado de pausa
	SMS_resetPauseRequest();

	// El valor del scroll
	UpdateScroll(0,0);

	// Init interrupts
	InitInterrupts();
	
	// Iniciamos las frames
	ResetStageFrames();
}

// Limpia la pantalla
void ClearScreen()
{
	// Los sprites
	ClearSprites();
	
	// Fill background
	ClearBackground(445);
	
	// El background
	SMS_setBackdropColor(0);
}

// Clear background
void ClearBackground(unsigned int b)
{
	unsigned int a;
	
	SMS_setNextTileatXY (0,0);
	for(a=0;a<(32*28);a++)
		SMS_setTile (b);
}

// Carga graficos background
void LoadGraphics(unsigned char *pal, unsigned char palbank,char *psg,unsigned char psgbank,char *bin, unsigned char binbank, unsigned int size)
{
	// The tiles
	LoadSprite(psg,256,psgbank);

	// The graphics bank
	changeBank(binbank);

	// Everything
	dzx7_standard(bin,tempbuffer);
	SMS_loadTileMap(0,0,tempbuffer,size<<1);
	
	// Change to default bank
	changeBank(FIXEDBANKSLOT);

	// Load bg palette
	DoFadeIn(pal,palbank);
}

// Carga un sprite
void LoadSprite(const unsigned char *psg,unsigned int base,unsigned char bank)
{
	// Rom bank
	changeBank(bank);

	// Decompress
	sms_dzx7_standard_vram(psg,(base<<5));
	
	// Change to default bank
	changeBank(FIXEDBANKSLOT);
}

// Update stage and frames
void UpdateStage()
{
	// Increase frames
	stageframe++;
	
	// Caching calcs
	stageframe2mod=stageframe%2;
	stageframe4mod=stageframe%4;
	stageframe8mod=stageframe%8;
	stageframe2div=stageframe>>1;
	stageframe4div=stageframe2div>>1;
	stageframe8div=stageframe4div>>1;

	// Just before wait vblank
	keystatus=SMS_getKeysStatus(); 	

	// Two frames updating
	if(stageframe2mod==0)
	{
		// Los sprites
		SMS_finalizeSprites(); 
		
		// Wait
		SMS_waitForVBlank();

		// Copy sprites
		UNSAFE_SMS_copySpritestoSAT();

		// Los sprites
		SMS_initSprites(); 

		// Reset
		numinterrupts=0;
	}
	else
	{
		// Interrupts
		if(numinterrupts==0)
			SMS_waitForVBlank();
	}
}

// Para el sonido
void StopSound()
{
	PSGStop();
	PSGSFXStop();
	
	// Resetting pause
	lastplayedmusic=0;
	lastplayedmusicbank=0;
	lastplayedmusiclooped=0;
}


// Retorna el caracter exacto
unsigned char putCharacter(unsigned char a,unsigned char x, unsigned char y)
{
	
	SMS_setNextTileatXY (x%32,y%28);
	
	if(a==32)
	{
		SMS_setTile (445);
		return 0;
	}
	else 
	{
		SMS_setTile (a+352); 
		return 1;
	}
}

// Dibujamos un texto
void WriteText(const unsigned char *text,unsigned char x, unsigned char y)
{
	unsigned char a;

	a=0;
	while(text[a]!=0)
		putCharacter(text[a++],x++,y);
}


// Prepare stage for music!!!
void PlayMusic(const unsigned char *music,unsigned char mbank,unsigned char looped)
{
	// Maybe it could be on other site
	//PSGSetMusicVolumeAttenuation(4);
	
	// Save banks
	musicbank=mbank;

	// Init Music
	changeBank(musicbank);
	
	// Loop???
	if(looped==1)
		PSGPlay (music);
	else
		PSGPlayNoRepeat(music);
	
	if((music!=pause_psg)||(mbank!=pause_psg_bank))
	{
		lastplayedmusic=music;
		lastplayedmusicbank=mbank;
		lastplayedmusiclooped=looped;
	}
	
	// Change to default bank
	changeBank(FIXEDBANKSLOT);
}

// Dibujamos un texto
void WriteNumber(unsigned int i,unsigned char d,unsigned char x, unsigned char y)
{
	// Añadimos a x
	x+=d;
	
	// Ponemos todos los dígitos
    while(d--)
	{ 
		putCharacter((i%10)+48,x--,y);
        i/=10;
    }
}

// Un sonido
void PlaySound(char *sound,unsigned char sbank, unsigned char priority,unsigned char channel)
{
	if((priority==1)||(!PSGSFXGetStatus()))
	{
		// Save banks
		soundbank=sbank;
	
		// Play the sound
		changeBank(sbank);
		PSGSFXPlay (sound,channel);

		// Change to default bank
		changeBank(FIXEDBANKSLOT);
	}
}

// Check for pause
void checkgamepause()
{
	if(SMS_queryPauseRequested())
	{
		SMS_resetPauseRequest();
		gamepause=1-gamepause;
		if(gamepause==1)
			PlayMusic(pause_psg,pause_psg_bank,0);
		else
			PlayMusic(lastplayedmusic,lastplayedmusicbank,lastplayedmusiclooped);
	}
}

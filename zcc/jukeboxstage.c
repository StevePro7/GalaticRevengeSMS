#include "includes.h"

unsigned char UpdateJukeboxInfo()
{
	// Cursors
	SMS_addSprite(40,(10+(jukeboxselectedline<<1))<<3,CURSORSBASE);
	
	// Music Name
	WriteText(jukebox_names[jukeboxselectedsong],17,16);
	
	// Stock
	if(gamestock==MAX_LIFES)
		WriteText("UNLIMITED",17,14);
	else
		WriteNumber(gamestock,2,16,14);

	// Buttons
	WriteText(jukebox_buttons[buttoninverse],17,10);

	// Difficult
	WriteText(jukebox_levels[gamelevel],17,12);
	
	// Action?
	if(jukeboxcheckkey==1)
	{
		// Reset
		jukeboxcheckkey=0;
		
		// Musica nombre
		if(jukeboxselectedline==3)
		{
			if(keystatus&PORT_A_KEY_LEFT)if(jukeboxselectedsong>0)jukeboxselectedsong--;
			if(keystatus&PORT_A_KEY_RIGHT)if(jukeboxselectedsong<JUKEBOX_SONGS-1)jukeboxselectedsong++;
		}
		
		// Cursors
		if(keystatus&PORT_A_KEY_UP)if(jukeboxselectedline>0)(jukeboxselectedline)--;
		if(keystatus&PORT_A_KEY_DOWN)if(jukeboxselectedline<4)(jukeboxselectedline)++;

		// Pushed
		if(keystatus&button2)
		{
			switch(jukeboxselectedline)
			{
				case 0:
					SetButtons(1-buttoninverse);
				break;
				case 1:
					gamelevel=1-gamelevel;
				break;
				case 2:
					gamestock=1+(gamestock%MAX_LIFES);
					WriteText("         ",17,14);
				break;
				case 3:
					PlayMusic(jukebox_songs[jukeboxselectedsong],jukebox_banks[jukeboxselectedsong],jukebox_repeat[jukeboxselectedsong]);
				break;
				case 4: 
					return 1;
				break;
			}
		}
	}
	
	// Reset key status
	if(keystatus==0)jukeboxcheckkey=1;

	// Exit
	return 0;
}

void InitJukeboxStage()
{
	unsigned char a;
	
	// Line
	jukeboxselectedline=0;
	
	// Set current song
	jukeboxselectedsong=0;

	// Set init stage
	numstage=0;
	
	// To avoid troubles with keys
	jukeboxcheckkey=0;
	
	// General init
	InitStage(1);

	// Load palette
	DoFadeIn(palette_bin,palette_bin_bank);
	
	// Cursors, sprites, blah blah blah...
	LoadSprite(cursors_zx7, CURSORSBASE,cursors_zx7_bank);
	
	// Los textos
	for(a=0;a<7;a++)
		WriteText(jukebox_labels[a],7,6+(a<<1));

	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// Update info
		a=UpdateJukeboxInfo();

		// Exit?
		if(a==1)
		{
			InitGameConfig(0);
			return;
		}
	}
}


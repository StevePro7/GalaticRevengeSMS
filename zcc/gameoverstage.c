#include "includes.h"

void InitGameoverStage()
{
	// General init
	InitStage(1);

	// Load palette
	DoFadeIn(palette_bin,palette_bin_bank);
	
	// Labels
	WriteText(gameover_label_a,11,11);
	WriteText(gameover_label_b,5,13);
	
	// Rom bank
	PlayMusic(gameover_psg,gameover_psg_bank,0);
	
	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// Play?
		if(keystatus&button2)
		{
			// Init game config
			InitGameConfig(1);			
			
			// Exit
			return;
		}
		
		// Exit if done
		if(!PSGGetStatus())
		{
			// Set an numstage to exit gameover_psg
			numstage=EXIT_STAGE;
			
			// Fueri
			return;
		}
	}
}
#include "includes.h"

void InitAboutStage()
{
	unsigned char a;
	
	// General init
	InitStage(1);
	
	// Scroll
	SMS_setBGScrollY(0);

	// Palette to 0
	for(a=0;a<16;a++)
		SMS_setBGPaletteColor(a,0);
	
	// Load graphics
	LoadGraphics(aboutpalette_bin,aboutpalette_bin_bank,abouttiles_zx7,abouttiles_zx7_bank,abouttilemap_zx7,abouttilemap_zx7_bank,32*24);
	
	/*
	// Clear
	ClearBackground(445);
	
	// Cargamos los graficos a la pantalla
	for(a=0;a<22;a++)
		WriteText(abouttext[a],0,1+a);

	// Load bg palette
	DoFadeIn(aboutpalette_bin,aboutpalette_bin_bank);
	*/
	
	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// Play?
		if(keystatus&button2)
			return;
	}
}

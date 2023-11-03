#include "includes.h"

void InitMikGamesStage()
{
	// General init
	InitStage(1);
	
	// Custom background here
	ClearBackground(256);

	// Scroll
	SMS_setBGScrollY(136);

	// Cargamos los graficos a la pantalla
	LoadGraphics(palette_bin,palette_bin_bank,mikgamestiles_zx7,mikgamestiles_zx7_bank,mikgamestilemap_zx7,mikgamestilemap_zx7_bank,32*2);
	
	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// Play?
		if(keystatus&button2)
			return;
		
		// Done?
		if(stageframe>120)return;
	}
}

#include "includes.h"

// Inicio del juego
void main()
{
	// Iniciamos la consola
	InitConsole();

	// Game values at init
	gamestock=DEFAULT_LIFES;

	// Lo ponemos solo aquí
	gamelevel=0;

	// Botones
	SetButtons(0);
	
	// Mikgames stage
	InitAboutStage();

	// Forever bucle
	while(1)
	{
		// Mikgames stage
		InitMikGamesStage();
	
		// Intro
		InitIntroStage(&introdefinition);

		// Title stage, and options stage if needed
		if (InitTitleStage()==1)
			InitJukeboxStage();
		
		// Playing
		while(numstage<EXIT_STAGE)
		{
			// Inside game?
			if(numstage<TOTAL_STAGES)
				InitPlayStage();
			
			// Game ending?
			if(numstage==ENDING_STAGE)
				InitIntroStage(&endingdefinition);

			// Game over?
			if(numstage==GAMEOVER_STAGE)
				InitGameoverStage();
		}
	}
}



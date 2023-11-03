#include "includes.h"

void AnimateTitleStars(signed char f)
{
	unsigned char a;
	unsigned int b=48;
	
	for(a=0;a<10;a++)
		SMS_addSprite((introstarsx[a]-(f<<introstarsv[a]))%256,titlestarsy[a],INTROSTAR_BASE);
}

unsigned char InitTitleStage()
{
	unsigned char a;
	
	// General init
	InitStage(1);

	// Cargamos los graficos a la pantalla
	LoadGraphics(titlepalette,FIXEDBANKSLOT,logotiles_zx7,logotiles_zx7_bank,logotilemap_zx7,logotilemap_zx7_bank,32*24);
		
	// Music
	PlayMusic(shop_psg,shop_psg_bank,1);

	// Text
	for(a=0;a<3;a++)
		WriteText(title_labels[a],7,a+18);

	// Bucle
	while(1)
	{
		// Update stage
		UpdateStage();

		// palette
		for(a=0;a<9;a++)
			SMS_setBGPaletteColor(titlecolors[a],titlecolorsp[(a+stageframe2div)%9]);
		
		// Play?
		if(keystatus&button2)
		{
			InitGameConfig(0);
			return 0;
		}

		// Jukebox
		if(keystatus&button1)
			return 1;

		// Text
		if(stageframe8div%2==0)
			WriteText(title_press_key,7,14);
		else
			WriteText(title_press_key_empty,7,14);
		
		AnimateTitleStars(stageframe);
	}
}

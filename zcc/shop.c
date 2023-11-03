#include "includes.h"

void DrawCharArray(unsigned char max, unsigned char *x, unsigned char *y, unsigned int *p)
{
	for(unsigned char c=0;c<max;c++)
	{
		SMS_setNextTileatXY ((stoppedstagex+x[c])%32,(stoppedstagey+y[c])%28);
		SMS_setTile (p[c]);
	}	
}

void DeselectShop()
{
	DrawCharArray(4,shopcornersx[shopoption],shopcornersy,shopcornersempty);
}

void SelectShop()
{
	DrawCharArray(4,shopcornersx[shopoption],shopcornersy,shopcorners);	
	
	if(playertype<shopoption+1)
		WriteText(shoplabels[shopoption],stoppedstagex+5,stoppedstagey+7);
	else
		WriteText(shoplabelssold[shopoption],stoppedstagex+5,stoppedstagey+7);
}

void InitShop(enemy *en)
{
	// Stop everything
	en->param++;
	
	// Draw shop quad
	stoppedstagex=maptileposx%32;
	stoppedstagey=maptileposy%28;
		
	// The clothes
	LoadSprite(clothes_zx7,BASELABELSIMAGE,clothes_zx7_bank);

	// Draw shop quad
	for(unsigned char b=0;b<8;b++)
		WriteText(marklabelsshop[b],stoppedstagex+3,baselabelsy[1]+b+stoppedstagey);

	// Clothes
	DrawCharArray(16,clothesx,clothesy,clothesz);
	
	// Music
	PlayMusic(shop_psg,shop_psg_bank,1);
	
	// The shop option
	shopoption=0;
	SelectShop();
	
}

void ExitShop(enemy *en)
{
	// Refill map
	DrawMap(9);
	
	// Put everything to work
	en->param++;
	
	// Music
	PlayMusic(stagesdefinition[numstage].stagemusic,stagesdefinition[numstage].stagemusicbank,1);
}

void UpdateShop(enemy *en)
{
	if(keystatus&button1)
	{
		if(!jukeboxcheckkey)
		{
			// Set key
			jukeboxcheckkey=1;
			
			// Exit
			if(shopoption==3)
			{
				ExitShop(en);
				return;
			}
			
			//Try to buy
			if((playercoins>=clothesprice[shopoption])&&(playertype<shopoption+1))
			{
				playercoins-=clothesprice[shopoption];
				playertype=shopoption+1;
				PlaySound(coin_psg,coin_psg_bank,1,SFX_CHANNEL2);
				ExitShop(en);
			}
			else
			{
				PlaySound(damage_psg,damage_psg_bank,1,SFX_CHANNEL3);
			}
			return;
		}
	}

	// Directions
	else if(keystatus&PORT_A_KEY_LEFT)
	{
		if(!jukeboxcheckkey)
		{
			jukeboxcheckkey=1;
			if(shopoption>0)
			{
				DeselectShop();
				shopoption--;
				SelectShop();
			}
		}
	}else 
	if(keystatus&PORT_A_KEY_RIGHT)
	{
		if(!jukeboxcheckkey)
		{
			jukeboxcheckkey=1;
			if(shopoption<3)
			{
				DeselectShop();
				shopoption++;
				SelectShop();
			}
		}
	}else jukeboxcheckkey=0;
}



#include "includes.h"

// Do multiple coins
void DoMultipleCoins(enemy *en)
{
	for(unsigned char a=0;a<3+myRand()%3;a++)
		CreateGoodie(PLAYERCOINBASE,en->posx-24+(myRand()%48),en->posy-16+(myRand()%32),en->posz);
}


// Init all goodies
void InitGoodies()
{
	numgoodies=0;
}

void RemoveGoodie(unsigned char a)
{
	// Bajamos el numero de explosions
	numgoodies--;
	
	// Remove list of sprites
	if(a!=numgoodies)
		memcpy(&goodies[a],&goodies[numgoodies],sizeof(goodie));
}

void CreateGoodie(unsigned char sp,unsigned int x,unsigned int y,unsigned char z)
{
	goodie *gd;
	
	if(numgoodies<MAXGOODIES)
	{
		// Create the goodie
		gd=&goodies[numgoodies];
		
		// The values
		gd->posx=x;
		gd->posy=y;
		gd->posz=z;
		gd->velz=8;
		gd->state=0;
		gd->goodie=sp;

		// Increase counter
		numgoodies++;
	}
}

// Update goodies
void UpdateGoodies()
{
	// Each of the goodies
	for(signed char a=numgoodies-1;a>=0;a--)
	{
		// Get the shoot
		goodie *gd=&goodies[a];

		// The speed
		if(gd->state<3)
		{
			gd->velz-=GRAVITY;
			gd->posz+=gd->velz;
			if(gd->posz>230)
			{
				gd->state++;
				gd->posz=0;
				gd->velz=-gd->velz-4;
			}
		}
				
		// Draw and check for out of screen
		if(!DrawInMapSprite(gd->goodie,gd->posx-4,gd->posy-(gd->posz>>1)))
			RemoveGoodie(a);
	}
}

// Check collision of goodie with player
void CheckGoodieDamage()
{
	signed char a;

	// Check
	if(numgoodies>0)
	{
		for(a=numgoodies-1;a>=0;a--)
		{
			goodie *gd=&(goodies[a]);

			if((playerx<gd->posx+8)&&(playerx>gd->posx-8)&&(playery<gd->posy+8)&&(playery>gd->posy-8))
			{
				if(gd->goodie==PLAYERCOINBASE)
				{
					PlaySound(coin_psg,coin_psg_bank,1,SFX_CHANNEL2);
					if(playercoins<99)playercoins++;
					RemoveGoodie(a);
				}
				else
				{
					PlaySound(heart_psg,heart_psg_bank,1,SFX_CHANNEL2);
					if(numplayers<MAX_LIFES-1)numplayers++;
					RemoveGoodie(a);
				}
			}
		}
	}
}


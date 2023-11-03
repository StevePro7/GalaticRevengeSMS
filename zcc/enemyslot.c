#include "includes.h"

unsigned char enemyslotinsidescreen(enemyslot *en)
{
	enemydef *ed=en->ed;
	
	if(en->posx>=mapposx+256+MAPMARGIN)return 0;
	if(en->posx+MAPMARGIN<=mapposx)return 0;
	if(en->posy>=mapposy+192+MAPMARGIN)return 0;
	if(en->posy+MAPMARGIN<=mapposy)return 0;
	return 1;
}

unsigned char enemyzoneinsidescreen(enemyzone *zn)
{
	if(zn->zoneleft>=mapposx+256+MAPMARGIN)return 0;
	if(zn->zoneright+MAPMARGIN<=mapposx)return 0;
	if(zn->zonetop>=mapposy+192+MAPMARGIN)return 0;
	if(zn->zonebottom+MAPMARGIN<=mapposy)return 0;
	return 1;
}

// Init all enemys
void InitEnemySlots(enemyslot *ens, unsigned char nens,enemyspritebase *enemysprites,unsigned char nesp)
{
	unsigned char a;
	
	// Enemy slots
	numenemyslots=nens;
	
	// Maybe not needed
	changeBank(FIXEDBANKSLOT);
	
	// Copy
	for(a=0;a<numenemyslots;a++)
		memcpy(&enemyslots[a],&ens[a],sizeof(enemyslot));
	
	// Clear slots
	for(a=0;a<nens;a++)
		usedenemyslots[a]=0;

	// Sprites que usaremos
	enemyslotsprites=enemysprites;
	numenemyslotsprites=nesp;
	
	// Load sprite
	for(a=0;a<nesp;a++)
		if(enemyslotsprites[a].spritebank!=0)
			LoadSprite(enemyslotsprites[a].sprite, enemyslotsprites[a].base,enemyslotsprites[a].spritebank);
}

void UpdateEnemySlots()
{
	unsigned char a,b;
	unsigned char inside;
	enemyslot *en;
	
	for(a=0;a<numenemyslots;a++)
	{
		if(numenemies>=MAXENEMIES)return;
		
		if(usedenemyslots[a]==0)
		{
			en=&enemyslots[a];
			
			// Veamos si tenemos que meterlo o no
			inside=0;
			
			// Chequeamos ambos
			if(!en->usezone)
			{
				if(enemyslotinsidescreen(en))
					inside=1;
			}
			else
			{
				if(enemyzoneinsidescreen(&en->zone))
					inside=1;
			}
			
			// Veamos
			if(inside)
			{
				if(usedenemyslots[a]==0)
				for(b=0;b<numenemyslotsprites;b++)
				{
					if(enemyslotsprites[b].ed==en->ed)
					{
						usedenemyslots[a]=1;
						InitEnemy(en->posx,en->posy,en->ed,en->param,a,enemyslotsprites[b].base);
					}
				}
			}
			//else if(usedenemyslots[a]==2)usedenemyslots[a]=0;
		}
	}
}


enemy *InitEnemyByType(unsigned int x, unsigned int y, enemydef *ed)
{
	for(unsigned char b=0;b<numenemyslotsprites;b++)
		if(enemyslotsprites[b].ed==ed)
			return InitEnemy(x,y,ed,0,-1,enemyslotsprites[b].base);
	return 0;
}

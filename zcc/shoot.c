#include "includes.h"

void CheckShootWalls(shoot *shoots,unsigned char *numshoots)
{
	// Each of the explosions
	for(signed char a=(*numshoots)-1;a>=0;a--)
	{
		// Get the shoot
		shoot *sh=&shoots[a];

		// Check for wall
		if((sh->maxduration--==1)||(getTileAt(sh->posx,sh->posy)==TILE_SOLID))
		{
			InitExplosion(sh->posx-mapposx-4,sh->posy-mapposy-(sh->posz>>1),0);
			RemoveShoot(a,shoots,numshoots);
		}
	}	
}

void RemoveShoot(unsigned char a,shoot *shoots,unsigned char *numshoots)
{
//	shoot *sha,*shb;

	// Bajamos el numero de explosions
	(*numshoots)--;
	
	// Remove list of sprites
	if(a!=(*numshoots))
	{
	//	sha=&shoots[a];
	//	shb=&shoots[*numshoots];
		memcpy(&shoots[a],&shoots[*numshoots],sizeof(shoot));
	/*
		sha->posx=shb->posx;
		sha->posy=shb->posy;
		sha->posz=shb->posz;
		sha->velx=shb->velx;
		sha->vely=shb->vely;
		sha->sprite=shb->sprite;
		sha->maxsprite=shb->maxsprite;
		sha->maxduration=shb->maxduration;
	*/		
	}
}

void CreateShoot(shoot *shoots,unsigned char *numshoots,unsigned int sx,unsigned int sy,unsigned char sz,signed char svx,signed char svy,unsigned char ssprite,unsigned char smaxsprite,unsigned char smaxduration)
{
	shoot *sh;
	
	// Create the shoot
	sh=&shoots[(*numshoots)];
	
	// The values
	sh->posx=sx;
	sh->posy=sy;
	sh->posz=sz;
	sh->velx=svx;
	sh->vely=svy;
	sh->sprite=ssprite;
	sh->maxsprite=smaxsprite;
	sh->maxduration=smaxduration;

	// Increase counter
	(*numshoots)++;
}

void UpdateShoots(shoot *shoots,unsigned char *numshoots)
{
	// Each of the shoots
	for(signed char a=(*numshoots)-1;a>=0;a--)
	{
		// Get the shoot
		shoot *sh=&shoots[a];

		// The speed
		sh->posx+=sh->velx;
		sh->posy+=sh->vely;
		
		// Draw and check for out of screen
		if(!DrawInMapSprite(sh->sprite+(sh->maxsprite==0?0:(stageframe8div%sh->maxsprite)),sh->posx-4,sh->posy-(sh->posz>>1)))
			RemoveShoot(a,shoots,numshoots);
	}
}
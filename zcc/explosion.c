#include "includes.h"

// Remove explosion
void RemoveExplosion(unsigned char a)
{
	explosion *exa,*exb;
	
	// Remove list of sprites
	if(a<numexplosions-1)
	{
		exa=&explosions[a];
		exb=&explosions[numexplosions-1];
	
		exa->posx=exb->posx;
		exa->posy=exb->posy;
		exa->sprite=exb->sprite;
		exa->extype=exb->extype;
	}
	
	// Bajamos el numero de explosions
	numexplosions--;
}

// Update explosion
void UpdateExplosion(unsigned int a)
{
	explosion *ex=&explosions[a];
	
	if(ex->extype==1)
	{
		if(ex->sprite>=12)
			RemoveExplosion(a);
		else
		{
			DrawInMapSpriteArray(ex->sprite+BIGEXPLOSIONBASE,ex->posx,ex->posy,16,16);
			ex->sprite+=4;
		}
	}
	else
	{
		if(ex->sprite>=3)
			RemoveExplosion(a);
		else
		{
			SMS_addSprite_callee(ex->posx,ex->posy,ex->sprite+LITTLEEXPLOSIONBASE);
			ex->sprite++;
		}
	}
}

// Create a explosion
void InitExplosion(unsigned int x, unsigned int y,unsigned char t)
{
	explosion *ex;
	
	if(numexplosions<MAXEXPLOSIONS)
	{
		// Get
		ex=&explosions[numexplosions];
		
		// Data
		ex->posx=x;
		ex->posy=y;
		ex->extype=t;
		ex->sprite=0;
		
		// Increase
		numexplosions++;

		// Sound
		PlaySound(explosion_psg,explosion_psg_bank,1,SFX_CHANNEL3);
	}		
}

// Update all explosions
void UpdateExplosions()
{
	// Each of the explosions
	if(numexplosions>0)
		for(signed char a=numexplosions-1;a>=0;a--)
			UpdateExplosion(a);
		
	// Spawn of explosions
	if(spawnedexplosiontime>0)
	{
		if(spawnedexplosiontime%2==0)
		{
			// Barrom
			if(spawnedexplosionbarrom)DoBarrom(0);

			// Explosion
			InitExplosion(spawnedexplosionposx+(myRand()%spawnedexplosionwidth),spawnedexplosionposy+(myRand()%spawnedexplosionheight),1);
		}
		spawnedexplosiontime--;		
	}
}

// Init all explosions
void InitExplosions()
{
	// Sprites
	LoadSprite(bigexplosion_zx7, BIGEXPLOSIONBASE,bigexplosion_zx7_bank);
	LoadSprite(littleexplosion_zx7, LITTLEEXPLOSIONBASE,littleexplosion_zx7_bank);
	
	// Counters
	numexplosions=0;
	spawnedexplosiontime=0;
}


void InitSpawnedExplosion(unsigned int x, unsigned int y, unsigned char w, unsigned char h,unsigned char e)
{
	spawnedexplosionposx=x;
	spawnedexplosionposy=y;
	spawnedexplosionwidth=w-16;
	spawnedexplosionheight=h-16;
	spawnedexplosiontime=(w+h)>>2;
	spawnedexplosionbarrom=e;
}



#include "includes.h"
#include <math.h>

/*
void CreateEnemyShootGroup(unsigned int x, unsigned int y, signed char z)
{
}
*/

// Remove explosion
void RemoveEnemyShoot(unsigned char a)
{
	RemoveShoot(a,enemyshoots,&numenemyshoots);
}

void CreateEnemyShootToPlayer(unsigned int x, unsigned int y,signed char z)
{
	signed int dx;
	signed int dy;
	unsigned int dm;
	
	if(numenemyshoots<MAXENEMYSHOOTS-1)
	{
		// Better granularity although faster enemy shoots on pure horizontal&vertical shoots
		dx=abs(playerx-x);
		dy=abs(playery-y);
		dm=sqrt((dx*dx)+(dy*dy));//abs(dx)+abs(dy);
				
		// Ahora solo dispara si está relativamente lejos
		if(dm>ENEMYSHOOTMINDIST)
		{
			// Speed
			dx*=(ENEMYSHOOTSPEED+gamelevel);
			dx/=dm;
			dy*=(ENEMYSHOOTSPEED+gamelevel);
			dy/=dm;
			
			// Create the shoot
			CreateShoot(enemyshoots,&numenemyshoots,x,y,z,(playerx<x?-dx:dx),(playery<y?-dy:dy),ENEMYSHOOTBASE,ENEMYSHOOTMAXSPRITES,ENEMYSHOOTDURATION);
		}
	}
}

// Create an enemyshoot_bin_zx7
void CreateEnemyShoot(unsigned int posx, unsigned int posy,signed char posz,signed char velx, signed char vely)
{
	if(numenemyshoots<MAXENEMYSHOOTS-1)
		CreateShoot(enemyshoots,&numenemyshoots,posx,posy,posz,velx,vely,ENEMYSHOOTBASE,ENEMYSHOOTMAXSPRITES,ENEMYSHOOTDURATION);
}

// Init all enemyshoots
void InitEnemyShoots()
{
	// Reset to none
	numenemyshoots=0;
	
	// The sprites
	LoadSprite(enemyshoot_zx7,ENEMYSHOOTBASE,enemyshoot_zx7_bank);	
}

// Update enemyshoots
void UpdateEnemyShoots()
{
	UpdateShoots(enemyshoots,&numenemyshoots);
}

// Check collision of enemy shoot with player
void CheckEnemyShootDamage()
{
	signed char a;

	// Check
	if(numenemyshoots>0)
	{
		// Check the player
		if(playerstatus!=PLAYER_DIE && playerstatus!=PLAYER_FALL && playerstatus!=PLAYER_DAMAGED && playerstatus!=PLAYER_DAMAGEDB && playerinmunecounter==0)
		
		// Get the shoots
		for(a=numenemyshoots-1;a>=0;a--)
		{
			shoot *sh=&(enemyshoots[a]);

			if((playerx<sh->posx+8)&&(playerx>sh->posx-8)&&(playery<sh->posy+12)&&(playery>sh->posy-12)&&(playerz<sh->posz+16))
			{
				DamagePlayer();
			}
		}
	}
}

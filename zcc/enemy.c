#include "includes.h"

unsigned char enemyinsidescreen(enemy *en)
{
	enemydef *ed=en->ed;
	
	if(en->posx>=mapposx+256+MAPMARGIN)return 0;
	if(en->posx+ed->width+MAPMARGIN<=mapposx)return 0;
	if(en->posy>=mapposy+192+MAPMARGIN)return 0;
	if(en->posy+MAPMARGIN<=mapposy)return 0;
	return 1;
}

// Kill enemy
void KillEnemy(enemy *en,unsigned char doexplosion)
{
	enemydef *ed=en->ed;
	
	// Type of explosion
	if(doexplosion)
		InitSpawnedExplosion(en->posx-(ed->width>>1)-4,en->posy-ed->height-(en->posz>>1)+8,ed->width+8,ed->height+8,0);

	// Custom remove
	if(ed->ekf!=0)
		(*(ed->ekf))(en);
	
	// Put heart or coin(only on small enemies)
	if(ed->energy<32)
		if(myRand()%2)
			CreateGoodie((myRand()%4)?PLAYERCOINBASE:PLAYERINDICATORBASE,en->posx,en->posy,en->posz);
	
	// Remove
	RemoveEnemy(en);	
}	

// Kill all enemies
void KillEnemies(enemy *en)
{
	signed char a;
	
	if(numenemies>0)
		for(a=numenemies-1;a>=0;a--)
			if((void *)&enemies[a]!=(void *)en)
				KillEnemy(&enemies[a],0);
}


// Remove enemy
void RemoveEnemy(enemy *ea)
{
	//enemy *eb;

	// Remove list of sprites
	if(ea!=&enemies[numenemies-1])
	{
		memcpy(ea,&enemies[numenemies-1],sizeof(enemy));
	}
	
	// Bajamos el numero de enemys
	if(numenemies>0)numenemies--;
}

void damageenemy(enemy *en)
{
	// Rest energy
	en->energy--;

	// Kill?
	if(!en->energy)
		KillEnemy(en,1);
	else
		if(en->state==PLAYER_WALK & en->ed->gravity==1)
		{
			en->velz=6;
			en->state=PLAYER_JUMP;
		}
}

// Damage enemy
void DamageEnemy(enemy *en)
{
	enemydef *ed=en->ed;
	
	// If is damageable
	// Check if damage function
	if(ed->edf!=0)
		(*(ed->edf))(en);
}


// Draw enemies A
void DrawEnemiesA()
{
	enemy *en;
	enemydef *ed;
	
	for(unsigned char a=0;a<numenemies;a++)
	{
		en=&enemies[a];
		if(en->posy<playery)
			if(en->sprite>=0)
			{
				ed=en->ed;				
				DrawInMapSpriteArray(en->base+en->sprite,en->posx-(ed->width>>1),en->posy-ed->height-(en->posz>>1),ed->width,ed->height);
				if(en->posz>0)
					DrawInMapSprite(SHADOWBASE,en->posx-4,en->posy);
			}
		
	}
}

// Draw enemies B
void DrawEnemiesB()
{
	enemy *en;
	enemydef *ed;
	
	for(unsigned char a=0;a<numenemies;a++)
	{
		en=&enemies[a];
		if(en->posy>=playery)
			if(en->sprite>=0)
			{
				ed=en->ed;
				DrawInMapSpriteArray(en->base+en->sprite,en->posx-(ed->width>>1),en->posy-ed->height-(en->posz>>1),ed->width,ed->height);
				if(en->posz>0)
					DrawInMapSprite(SHADOWBASE,en->posx-4,en->posy);
			}
	}
}
	
// Update enemy
void UpdateEnemy(enemy *en)
{
	unsigned char a;
	unsigned char remove;
	enemydef *ed=en->ed;
	
	// If we have to exit
	remove=0;
	
	// Check both cases
	if(en->slot<0)
	{
		if(!enemyinsidescreen(en))
			remove=1;
	}
	else if(!enemyslots[en->slot].usezone)
	{
		if(!enemyinsidescreen(en))
			remove=1;
	}
	else
	{
		if(!enemyzoneinsidescreen(&enemyslots[en->slot].zone))
			remove=1;
	}
		
	// If we have to remove
	if(remove)
	{
		if(en->slot>=0)
		{
			enemyslots[en->slot].posx=en->posx;
			enemyslots[en->slot].posy=en->posy;
			usedenemyslots[en->slot]=0;
		}
		RemoveEnemy(en);
		return;
	}

	// Check status of enemy
	if(en->state!=PLAYER_DAMAGED)
	{
		// Update
		if(ed->euf!=0)
		{
			if(!(*(ed->euf))(en))
			{
				RemoveEnemy(en);
				return;
			}
		}
	}

	// Check for gravity
	if(ed->gravity==1)
	{
		en->velz-=GRAVITY;
		en->posz+=en->velz;
		if(en->posz>230)
		{
			en->velz=0;
			en->posz=0;
			en->state=PLAYER_WALK;
		}
	}
	
	// Movement & update tile
	if(en->ed->collideable==1)
	{
		// Check movement
		a=CheckMovement(&en->posx,&en->posy,&en->velx,&en->vely);
	
		// Check if tile changed
		if(a!=0)en->tile=a;
	}
	else
	{
		en->posx+=en->velx;
		en->posy+=en->vely;
	}

	// Increase frame
	if(en->state!=PLAYER_DAMAGED)
		en->frame++;	
}

// Update all enemys
void UpdateEnemies()
{
	signed char a;
	
	// For each enemy
	if(numenemies>0)
	{
		for(a=numenemies-1;a>=0;a--)
		{
			if(a<numenemies)UpdateEnemy(&enemies[a]);
		}
	}
}

// Create a enemy
enemy *InitEnemy(unsigned int x, unsigned int y,enemydef *ed,signed char p, signed char s,unsigned char b)
{
	enemy *en;
	
	if(numenemies<MAXENEMIES)
	{
		// Get enemy
		en=&enemies[numenemies];

		// Data
		en->ed=ed;
		en->posx=x;
		en->posy=y;
		en->posz=0;
		en->velx=0;
		en->vely=0;
		en->velz=0;
		en->frame=0;
		en->state=PLAYER_WALK;
		en->energy=ed->energy+gamelevel+gamelevel;
		en->param=p;
		en->slot=s;
		en->base=b;
		en->side=(playerx<x?-1:1);
		en->tile=TILE_FLOOR;
		en->sprite=0;
		en->centerx=en->posx;
		en->centery=en->posy;
		
		// Init function?
		if(ed->eif!=0)
			(*(ed->eif))(en);
	
		// Increase
		numenemies++;
		
		// Return
		return en;
	}		
	return 0;
}

// Init all enemys
void InitEnemies()
{
	numenemies=0;
}

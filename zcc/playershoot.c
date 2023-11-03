#include "includes.h"

// Remove explosion
void RemovePlayerShoot(unsigned char a)
{
	RemoveShoot(a,playershoots,&numplayershoots);
}

// Update playershoots
void UpdatePlayerShoots()
{
	UpdateShoots(playershoots,&numplayershoots);
}

// Init all playershoots
void InitPlayerShoots()
{
	// The sprites
	LoadSprite(playershootsprites[playertype],PLAYERSHOOTBASE,playershootspritesbank[playertype]);	
	
	// Number of player shoots
	numplayershoots=0;
}

void CreatePlayerShoot()
{
	switch(playertype)
	{
		case 0:
			if(!numplayershoots)
			{
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootavelx[playerside],playershootavely[playerside],PLAYERSHOOTBASE,PLAYERSHOOTAMAXSPRITES,PLAYERSHOOTADURATION);
				PlaySound(shoot_psg,shoot_psg_bank,0,SFX_CHANNEL3);
			}
		break;
		case 1:
			if(!numplayershoots)
			{
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootbavelx[playerside],playershootbavely[playerside],playershootbabases[playerside],PLAYERSHOOTBMAXSPRITES,PLAYERSHOOTBDURATION);
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootbbvelx[playerside],playershootbbvely[playerside],playershootbbbases[playerside],PLAYERSHOOTBMAXSPRITES,PLAYERSHOOTBDURATION);
				PlaySound(shoot_psg,shoot_psg_bank,0,SFX_CHANNEL3);
			}
		break;
		case 2:
			if(!numplayershoots)
			{
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootavelx[playerside],playershootavely[playerside],playershootdbases[playerside],PLAYERSHOOTCMAXSPRITES,PLAYERSHOOTCDURATION);
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootcbvelx[playerside],playershootcbvely[playerside],playershootcbbases[playerside],PLAYERSHOOTCMAXSPRITES,PLAYERSHOOTCDURATION);
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootccvelx[playerside],playershootccvely[playerside],playershootccbases[playerside],PLAYERSHOOTCMAXSPRITES,PLAYERSHOOTCDURATION);
				PlaySound(shoot_psg,shoot_psg_bank,0,SFX_CHANNEL3);
			}
		break;
		case 3:
			// Create the shoot
			if(numplayershoots<PLAYERSHOOTDQUANTITY)
			{
				CreateShoot(playershoots,&numplayershoots,playerx+playershootrefx[playerside],playery+playershootrefy[playerside],playerz+8,playershootavelx[playerside],playershootavely[playerside],playershootdbases[playerside],PLAYERSHOOTDMAXSPRITES,PLAYERSHOOTDDURATION);
				PlaySound(shoot_psg,shoot_psg_bank,0,SFX_CHANNEL3);
			}
		break;
	}
}

unsigned char CheckPlayerShootDamageEnemy(enemy *en,unsigned char a)
{
	enemydef *ed=en->ed;
	shoot *p=&playershoots[a];
	
	// Check damageable
	if(!en->ed->damageable)return 0;

	// Check Z
	if(p->posz>en->posz+32)return 0;
	
	//Check if out... more easy!
	if(p->posx>=en->posx+(ed->width>>1)+8)return 0;
	if(p->posx+8<=en->posx-(ed->width>>1))return 0;
	if(p->posy<=en->posy-24)return 0;
	if(p->posy>=en->posy+8)return 0;
	
	// Quit shot
	InitExplosion(p->posx-mapposx-4,p->posy-mapposy-(p->posz>>1),0);
	RemoveShoot(a,playershoots,&numplayershoots);
				
	// Damage!
	DamageEnemy(en);
	
	// Quit 
	return 1;
}

// Check collision of player shoot with enemies
void CheckPlayerShootDamage()
{
	signed char a,b;

	// Check
	if(numplayershoots>0)
	{
		// Check all enemies
		if(numenemies>0)
		{
			for(b=numplayershoots-1;b>=0;b--)
				for(a=numenemies-1;a>=0;a--)
					if(CheckPlayerShootDamageEnemy(&enemies[a],b)==1)a=-1;
		}
	}
}

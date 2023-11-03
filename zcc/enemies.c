#include "includes.h"

// In game labels
const labelscr ingamelabels[]=
{                     
	{"MY SUIT IS HEAVY TO ","JUMP WITH GRAVITY_  ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"I NEED LIGHTER      ","CLOTHES TO CONTINUE_",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"OH GOOD_ I FORGOT TO","BRING SPARE CLOTHES_",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"LUCKILY I HAVE MY   ","DEADLY SHURIKENS[[[ ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"WHAT I SEE_ A HUMAN_","YOU ARE NOT WELCOMED",facebigblob_zx7,facebigblob_zx7_bank,1},
	{"THE MASTER IS MINE_ ","I WONT RETREAT NOW_ ",faceplayerright_zx7,faceplayerright_zx7_bank,0},
	{"YOU TALK TOO MUCH_  ","NOW DIE LIKE A DOG_ ",facebigblob_zx7,facebigblob_zx7_bank,1},
	{"I WONT LET YOU STOLE","OUR SUPER CONSOLE_  ",facebigboss_zx7,facebigboss_zx7_bank,1},
	{"I AM PLAYING WONDER ","GIRL AND WONT STOP_ ",facebigboss_zx7,facebigboss_zx7_bank,1},
	{"BETTER FIND AN EMU  ","OR PREPARE TO DIE_  ",faceplayerright_zx7,faceplayerright_zx7_bank,0},
	{"MAYBE YOU THINK TWO ","ROBOTS IS UNFAIR[[[ ",facebigdouble_zx7,facebigdouble_zx7_bank,1},
	{"WE LOVE RAGE STREETS","AND THIS IS OUR WAY_",facebigdouble_zx7,facebigdouble_zx7_bank,1},
	{"I LOVE STREET KICKER","AND KNOW ALL COMBOS_",faceplayerright_zx7,faceplayerright_zx7_bank,0},
	{"I GOT MY CONSOLE SO ","NOW CAN RETURN HOME_",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"ALERT_ ALERT_ ALERT_","INTRUDER DETECTED_  ",facegusan_zx7,facegusan_zx7_bank,1},
	{"I KNEW I WOULD FIND ","HERE A SHITTY SWORM_",faceplayerright_zx7,faceplayerright_zx7_bank,0},
	{"I WILL MAKE TRASH   ","WITH YOUR HEAD___   ",faceplayerright_zx7,faceplayerright_zx7_bank,0},
	{"ANOTHER LIFT_ GOOD_ ","I WAS SO TIRED[[[   ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"NOW FOR THE BOSS[[[ ","I WANT MY CONSOLE_  ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"A SWITCH_ MAYBE ITS ","A TRAP SO BE CAREFUL",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"NEXT TIME I WILL    ","TAKE THE LADDERS[[[ ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},
	{"WHAT MY EYES SEE_   ","AN ARCADE MACHINE_  ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},	
	{"MAYBE I SHOULD BE   ","FRIEND OF ALIENS[[[ ",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},	
	{"DEFINITELY I NEED TO","RECOVER MY MASTER[[[",faceplayerleft_zx7,faceplayerleft_zx7_bank,1},	
};

///////////////////////////////////////////////// MOVE ORTHO TO PLAYER
void MoveOrthoToPlayer(enemy *en)
{
	signed int vx,vy;
	
	if(en->frame%16==0)
	{
		vx=playerx-en->posx;
		vy=playery-en->posy;

		if(abs(vx)>abs(vy))
		{
			en->vely=0;
			en->velx=(vx>0)?1:-1;
			en->centerx=(vx>0)?48:72;
			
		}
		else
		{
			en->velx=0;
			en->vely=(vy>0)?1:-1;
			en->centerx=(vy>0)?0:24;
		}
	}
}

///////////////////////////////////////////////// MOVE TO PLAYER

void MoveToPlayer(enemy *en,unsigned char v)
{
	en->velx=0;
	if(playerx<en->posx-16)en->velx=-v;
	if(playerx>en->posx+16)en->velx=v;

	en->vely=0;
	if(playery<en->posy-16)en->vely=-v;
	if(playery>en->posy+16)en->vely=v;
}
		
///////////////////////////////////////////////// DO INTERVAL PLAYER

void DoIntervalPlayerShoot(enemy *en, signed char dx, signed char dy,unsigned char interval)
{
	if(en->frame%interval==0)
		CreateEnemyShootToPlayer(en->posx+dx,en->posy+dy,en->posz);
}

///////////////////////////////////////////////// DO PING PONG

void DoPingPong(unsigned int pos,signed char *vlx,unsigned int minx, unsigned maxx, signed char vel)
{
	if(*vlx>0)
	{
		*vlx=vel;
		if(pos>maxx)
			*vlx=-*vlx;
	}
	else
	{
		*vlx=-vel;
		if(pos<minx)
			*vlx=-*vlx;
	}
}
		
///////////////////////////////////////////////// BIG BOSS OPEN EXIT

void enableexit(enemy *en)
{
	// Multiple coins
	DoMultipleCoins(en);

	// Barrom
	DoBarrom(0);
	
	// Enable exit!
	setstageexitable(1);
}

void enableexitbigboss(enemy *en)
{
	PlayMusic(silence_psg,silence_psg_bank,0);
	enableexit(en);
}

///////////////////////////////////////////////// NEEDCHANGE

void initneedchange(enemy *en)
{
	en->sprite=-1;
}

void collideneedchange(enemy *en)
{
	if(en->param==2)
		RemoveEnemy(en);
	else
	{
		InitStoppedStage(&ingamelabels[en->param]);
		en->posy-=48;
		en->param++;
	}
}

//////////////////////////////////////////////// CHANGE

void collidechange(enemy *en)
{
	if(en->param==0)
	{
		en->param++;
		drawplayer=0;
	}
}

unsigned char updatechange(enemy *en)
{
	if(en->param>0)
	{
		if(en->param<16)
		{
			// Close courtain
			LoadSprite(courtainframes[en->param>>1],en->base,courtainframesbank[en->param>>1]);
			en->param++;
		}
		else if(en->param==16)
		{
			if(numstage==1)
			{
				InitStoppedStage(&ingamelabels[2]);
				en->param++;
				playertype=0;
			}
			else
			{
				InitShop(en);
			}
		}
		else if(en->param==17)
		{
			if(numstage==1)
			{
				InitStoppedStage(&ingamelabels[3]);
				en->param++;
			}
			else
			{
				UpdateShop(en);
			}
		}
		else if(en->param<33)
		{
			// Open courtain
			LoadSprite(courtainframes[(33-en->param)>>1],en->base,courtainframesbank[(33-en->param)>>1]);
			en->param++;
		}
		else if(en->param==33)
		{
			en->posy+=2;
			PlaySound(damage_psg,damage_psg_bank,1,SFX_CHANNEL3);
			LoadSprite(courtainframes[8],en->base,courtainframesbank[8]);
			InitPlayer(playerx,playery,PLAYER_DOWN);
			InitPlayerShoots();
			en->param++;
			cannotjump=0;
			if(numstage==1)
				setstageexitable(1);
		}
	}
	return 1;
}

//////////////////////////////////////////////// SOLDIER UP-DOWN

unsigned char updatesoldierupdown(enemy *en)
{
	// The sprite
	en->sprite=(stageframe4div%2)*6;
	
	// Sense
	if(en->tile!=TILE_FLOOR)en->param=1-en->param;
	
	// Movement
	if(en->param==0)
	{
		en->vely=2;
		
	}
	else 
	{
		en->vely=-2;
		en->sprite+=24;
	}
	return 1;
}

//////////////////////////////////////////////// ROLLING ROBOT

unsigned char updaterollingrobot(enemy *en)
{
	//en->vely=1;
	en->sprite=(stageframe8div%2)<<4;
	
	if(en->frame<32)
		DoIntervalPlayerShoot(en,0,-16,8);

	en->frame%=96;
	
	//en->vely=(!stageframe4mod)?1:0;
	
	return 1;
}

//////////////////////////////////////////////// FLYING BOSS

unsigned char updateflyingboss(enemy *en)
{
	unsigned char a;
	
	switch(en->param)
	{
		case 1:
			DoIntervalPlayerShoot(en,0,-24,8);
		case 0:
		case 2:
			en->posz=flyingbossz[stageframe2div%24];
			DoPingPong(en->posx,&(en->velx),5*16,13*16,2);
			if(en->frame>=32){en->frame=0;en->param++;}
		break;
		case 3:
		case 5:
			en->velx=0;
			if(en->frame>16){en->frame=0;en->param=(en->param+1)%6;}
		break;
		case 4:
			InitEnemyByType(en->posx,en->posy+32,&ENEMY_LASER);
			for(a=0;a<4;a++)
				CreateShoot(enemyshoots,&numenemyshoots,en->posx,en->posy-24,en->posz,flyingbossmultipleshootx[a],flyingbossmultipleshooty[a],ENEMYSHOOTBASE,ENEMYSHOOTMAXSPRITES,ENEMYSHOOTDURATION);	
			
			en->velx=myRand()%2?2:-2;
			en->param++;
			stageframe=0;
		break;
	}
	return 1;
}

//////////////////////////////////////////////// LASER

void initlaser(enemy *en)
{
	PlaySound(laser_psg,laser_psg_bank,1,SFX_CHANNEL2);
	en->vely=12;
}

//////////////////////////////////////////////// HORIZ BLOCK
extern unsigned char updatehorizblock(enemy *en)
{
	DoPingPong(en->posx,&(en->velx),enemyslots[en->slot].zone.zoneleft+8, enemyslots[en->slot].zone.zoneright-8, 2);
	return 1;
}

//////////////////////////////////////////////// VERT BLOCK
extern unsigned char updatevertblock(enemy *en)
{
	DoPingPong(en->posy,&(en->vely),enemyslots[en->slot].zone.zonetop+8, enemyslots[en->slot].zone.zonebottom-8, 2);
	return 1;
}

//////////////////////////////////////////////// BLOB
extern unsigned char updateblob(enemy *en)
{
	unsigned char a;
	
	if(en->state==PLAYER_WALK)
	{
		a=myRand()%4;
		if(getTileAt(en->posx+blobrandvelqx[a],en->posy+blobrandvelqy[a])==TILE_FLOOR)
		{
			en->velx=blobrandvelx[a];
			en->vely=blobrandvely[a];
		}
		else
		{
			en->velx=0;
			en->vely=0;
		}
		en->velz=8;
		en->state=PLAYER_JUMP;
		en->param=a;
		en->sprite=4;
	}
	else en->sprite=(en->velz>0)?8:0;
	
	return 1;
}

//////////////////////////////////////////////// BLOBB
unsigned char updateblobb(enemy *en)
{
	DoIntervalPlayerShoot(en,0,-16,80);
	return updateblob(en);
}

//////////////////////////////////////////////// BLOBC
unsigned char updateblobc(enemy *en)
{
	DoIntervalPlayerShoot(en,0,-16,48);
	return updateblob(en);
}


//////////////////////////////////////////////// BIG BLOB
extern unsigned char updatebigblob(enemy *en)
{
	if(en->param<3)
	{
		InitStoppedStage(&ingamelabels[en->param+4]);
		en->param++;
		en->frame=0;
	}
	else if(en->param==26)
	{
		DoIntervalPlayerShoot(en, 0,-16,4);
		en->sprite=(stageframe8div%3)<<4;
		if(en->frame>128)en->param=3;
	}
	else if(en->param%3==0)
	{
		MoveToPlayer(en,2);
		
		en->velz=8;
		en->state=PLAYER_JUMP;
		en->param++;
		en->sprite=48;
	}
	else if(en->param%3==1)
	{
		if(en->state==PLAYER_WALK)
		{
			DoBarrom(12);
			en->param++;
			en->frame=0;
			en->velx=0;
			en->vely=0;
		}
	}
	else
	{
		en->sprite=64;
		if(en->frame>4)
		{
			en->param++;
			en->frame=0;
		}
	}
	return 1;
}

//////////////////////////////////////////////// SKULL

unsigned char updateskull(enemy *en)
{
	switch(en->param)
	{
		case 0:
			if(en->frame>=32)
			{
				en->param++;
				if(myRand()%3==1)
					CreateEnemyShootToPlayer(en->posx,en->posy-16,en->posz);					
			}
		break;
		case 1:
			MoveToPlayer(en,1);
		break;
	}
	en->posz=flyingbossz[stageframe2div%24]>>1;
	
	en->sprite=(stageframe8div%2)*6;
	
	return 1;
}

//////////////////////////////////////////////// WALKINGROBOT

unsigned char updatewalkingrobot(enemy *en)
{
	
	//MoveToPlayer(en,1);
	if(en->frame<32)
	{
		DoPingPong(en->posx,&(en->velx),enemyslots[en->slot].zone.zoneleft+8, enemyslots[en->slot].zone.zoneright-8, 1);
		en->sprite=(stageframe8div%3)<<4;
		DoIntervalPlayerShoot(en,0,-16,8);
	}
	else if(en->frame<48)
	{
		en->sprite=0;
		en->velx=0;
	}
	else 
	{
		InitEnemyByType(en->posx,en->posy+32,&ENEMY_LASER);
		en->frame=0;
		en->velx=playerx>en->posx?1:-1;
	}
	return 1;
}

//////////////////////////////////////////////// PIVOTS

unsigned char updatemediumpivot(enemy *en)
{
	en->posx=en->centerx+(farpivotx[en->frame%64]>>1);
	en->posy=en->centery+(farpivoty[en->frame%64]>>1);
	return 1;
}

unsigned char updatefarpivot(enemy *en)
{
	en->posx=en->centerx+farpivotx[en->frame%64];
	en->posy=en->centery+farpivoty[en->frame%64];
	return 1;
}

void initpivot(enemy *en)
{
	enemyslot *ens;
	ens=&enemyslots[en->slot];
	
	en->centerx=(ens->zone.zoneleft+ens->zone.zoneright)>>1;
	en->centery=(ens->zone.zonetop+ens->zone.zonebottom)>>1;
}

//////////////////////////////////////////////// BIG BOSS
extern unsigned char updatebigboss(enemy *en)
{
	if(en->param<3)
	{
		InitStoppedStage(&ingamelabels[en->param+7]);
		en->param++;
		en->frame=0;
	}
	else
	{
		en->posz=flyingbossz[stageframe2div%24];
		en->sprite=(stageframe8div%4);
		if(en->sprite==3)en->sprite=1;
		en->sprite*=36;

		switch(en->param)
		{
			case 3:
				DoPingPong(en->posx,&(en->velx),5*16,13*16,3);
				DoIntervalPlayerShoot(en,0,-16,8);
				if(en->frame>128)
				{
					en->frame=0;		
					en->param++;
				}
			break;
			case 4:
			case 6:
			case 8:
				en->velx=0;
				if(en->frame>32)
				{
					en->frame=0;		
					en->param++;
					if(en->param==9)en->param=3;
				}
			break;
			case 5:
			case 7:
				DoPingPong(en->posx,&(en->velx),5*16,13*16,1);
				if(en->frame%12==0)
				{
					if(en->param==5)
					{
						if(numenemies<3)
							InitEnemyByType(en->posx,en->posy,&ENEMY_HOMING);
					}
					else
						InitEnemyByType(en->posx,en->posy+32,&ENEMY_LASER);
					DoIntervalPlayerShoot(en,0,-16,24);
				}
				if(en->frame>128)
				{
					en->frame=0;
					en->param++;
				}
			break;
		}
	}
	return 1;
}

//////////////////////////////////////////////// MYMASTER
unsigned char updatemymaster(enemy *en)
{
	if(en->param==0)
		en->sprite=(stageframe8mod%3)*20;
	else if(en->param==1)
	{
		PlayMusic(gameover_psg,gameover_psg_bank,0);
		en->param++;
		en->centerx=playerx;
		en->centery=playery;
	}
	else if(en->param==61)
	{
		// Message
		InitStoppedStage(&ingamelabels[13]);
		en->param++;
		
		// Enable exit!
		setstageexitable(1);
	}
	else if(en->param==62)
	{
		// Heart sound
		PlaySound(heart_psg,heart_psg_bank,1,SFX_CHANNEL2);
		
		// Empty sprite
		en->sprite=60;
		
		// Exit
		en->param++;
	}
	else if(en->param<61)
	{
		en->param++;
		playerx=en->centerx;
		playery=en->centery;
	}
	return 1;
}

void collidemymaster(enemy *en)
{
	if(en->param==0)
		en->param=1;
}

//////////////////////////////////////////////// GUSAN

void initgusan(enemy *en)
{
	en->velx=-GUSANVELX;
	en->vely=GUSANVELY;
	
	// 0= left down
	// 1= left up
	// 2= right down
	// 3= right up
}

void updategusan(enemy *en)
{
	if(en->posx<24)
	{
		en->velx=GUSANVELX;
	}
	else if(en->posx>232)
	{
		en->velx=-GUSANVELX;
	}
	
	if(en->posy<48)
	{
		en->vely=GUSANVELY;
	}
	else if(en->posy>176)
	{
		en->vely=-GUSANVELY;
	}	
}

unsigned char updategusana(enemy *en)
{
	if(en->param<3)
	{
		InitStoppedStage(&ingamelabels[en->param+14]);
		en->param++;
	}
	else
	{
		updategusan(en);
		en->sprite=(stageframe8div%4)<<2;
	}
	return 1;
}
unsigned char updategusanb(enemy *en)
{
	if(stagestopped==0)
	{
		updategusan(en);
		en->sprite=(stageframe8div%4)<<2;
	}
	return 1;
}
unsigned char updategusanc(enemy *en)
{
	if(stagestopped==0)
	{
		updategusan(en);
		if(en->frame%120>70)
			DoIntervalPlayerShoot(en,0,-8,12);
	}
	return 1;
}

void killgusan(enemy *en)
{
	enableexitbigboss(en);
	numenemies=1;
}

//////////////////////////////////////////////// BIG DOUBLE

unsigned char updatebigdouble(enemy *en)
{
	en->posz=flyingbossz[stageframe2div%24];
	
	if(en->param<3)
	{
		InitStoppedStage(&ingamelabels[en->param+7]);
		en->param++;
		en->frame=0;
	}
	else if(en->param==26)
	{
		DoIntervalPlayerShoot(en, 0,-16,4);
		en->sprite=(stageframe8div%3)<<4;
		if(en->frame>128)en->param=3;
	}
	else if(en->param%3==0)
	{
		MoveToPlayer(en,3);
		
		en->velz=8;
		en->state=PLAYER_JUMP;
		en->param++;
		en->sprite=48;
	}
	else if(en->param%3==1)
	{
		if(en->state==PLAYER_WALK)
		{
			DoBarrom(12);
			en->param++;
			en->frame=0;
			en->velx=0;
			en->vely=0;
		}
	}
	else
	{
		en->sprite=64;
		if(en->frame>4)
		{
			en->param++;
			en->frame=0;
		}
	}
	return 1;
}

void killbigdouble(enemy *en)
{
	if(numenemies==1)
		enableexitbigboss(en);
}

//////////////////////////////////////////////// BIG DOUBLE A

unsigned char updatebigdoubleb(enemy *en)
{
	switch(en->param)
	{
		case 4:
			if(en->frame>=200)
			{
				enemies[0].param=4;
				enemies[0].frame=0;
				enemies[1].param=4;
				enemies[1].frame=0;				
				en->param++;
			}
			else
			{
				MoveOrthoToPlayer(en);
			}
			en->sprite=(stageframe8div%2)*12;
			en->sprite+=en->centerx;
		break;
		case 5:
			en->velx=0;
			en->vely=0;
			en->sprite=0;
			if(en->frame>32)
				DoIntervalPlayerShoot(en, 0,-16,12);		
			if(en->frame>=200)
			{
				enemies[0].param=5;
				enemies[0].frame=0;
				enemies[1].param=5;
				enemies[1].frame=0;				
				en->param=4;
			}
		break;
	}
	return 1;
}


unsigned char updatebigdoublea(enemy *en)
{
	if(en->param<3)
	{
		InitStoppedStage(&ingamelabels[en->param+10]);
		en->param++;
	}
	else if(en->param==3)
	{
		en->param++;
		enemies[1].param=5;
		en->frame=0;
		enemies[1].frame=0;
	}
	else updatebigdoubleb(en);
		
	return 1;
}

//////////////////////////////////////////////// HOMING

extern void inithoming(enemy *en)
{
	en->velx=(myRand()%2==0)?-GUSANVELX:GUSANVELX;
	en->vely=GUSANVELY;
}

extern unsigned char updatehoming(enemy *en)
{
	en->sprite=(stageframe4div%4)<<2;
	updategusan(en);
	return 1;
}

//////////////////////////////////////////////// FLYING BOSS B

unsigned char updateflyingbossb(enemy *en)
{
	if(en->frame%128<48)
		DoIntervalPlayerShoot(en,0,-24,12);
	
	en->posz=flyingbossz[stageframe2div%24];
	
	if(stageframe%12==0)
		MoveToPlayer(en,1);
	
	return 1;
}

//////////////////////////////////////////////// WALKINGROBOTB

unsigned char updatewalkingrobotb(enemy *en)
{
	MoveOrthoToPlayer(en);
	if(getTileAt(en->posx+en->velx,en->posy+en->vely)!=TILE_FLOOR)
	{
		en->velx=0;
		en->vely=0;
		en->sprite=0;
	}
	else en->sprite=(stageframe8div%2)*12;
	return 1;
}

//////////////////////////////////////////////// VAULT

extern unsigned char updatevault(enemy *en)
{
	enemy *ep;
	
	switch(en->param)
	{
		case 0:
			InitStoppedStage(numstage==18?&ingamelabels[17]:&ingamelabels[19]);
			en->param++;
		break;
		case 2:
			if(en->frame>512)
			{
				if((numenemies==1)&&(numexplosions==0))en->param++;
			}
			else
			if(en->frame%16==0)
				//if(numenemies<8)
				{
					if(myRand()%4==0)
						ep=InitEnemyByType(playerx,playery,&ENEMY_MISSILE);
					else
						ep=InitEnemyByType(48+myRand()%160,80+myRand()%108,&ENEMY_MISSILE);
					if(ep!=0)
						ep->posz=192;
				}
		break;
		case 3:
			en->sprite=0;
			InitStoppedStage(numstage==18?&ingamelabels[18]:&ingamelabels[20]);
			setstageexitable(1);
			en->param++;
		break;
	}
	return 1;
}

void damagevault(enemy *en)
{
	if(en->param==1)
	{
		en->frame=0;
		en->param++;
		en->sprite=4;
	}
}

//////////////////////////////////////////////// VAULT
unsigned char updatemissile(enemy *en)
{
	switch(en->param)
	{
		case 0:
			en->sprite=0;
			if(en->posz==0)
			{
				DoBarrom(20);
				en->param++;
				en->frame=0;
			}
		break;
		case 1:
			en->sprite=8;
			en->frame++;
			if(en->frame>=64)
				KillEnemy(en,1);
		break;
	}
	en->sprite+=((stageframe4div)%2)<<2;
	return 1;
}

//////////////////////////////////////////////// MAChINE
unsigned char updatemachine(enemy *en)
{
	switch(en->param)
	{
		case 0:
			if(playery<16*16)
			{
				InitStoppedStage(&ingamelabels[21]);		
				en->param++;
			}
		break;
		case 1:
			if(playery<11*16)
			{
				InitStoppedStage(&ingamelabels[22]);		
				en->param++;
			}
		break;
		case 2:
		case 4:
			en->sprite=((stageframe>>5)%2)*8;
		break;
		case 3:
			InitStoppedStage(&ingamelabels[23]);		
			en->param=2;
			playery+=16;
		break;
	}
	return 1;
}

void collidemachine(enemy *en)
{
	if(en->param==2)
	{
		PlayBalloid();
		en->param++;
	}
}


#include "includes.h"

unsigned char CheckPlayerPlatforms()
{
	unsigned char a;
	platform *p;
	
	for(a=0;a<numplatforms;a++)
	{
		// Cogemos la plataforma
		p=&platforms[a];
		
		// Está arriba?
		if(playerx+4>=p->posx&&playerx<p->posx+28&&playery+4>=p->posy&&playery<p->posy+20)
		{
			// La velocidad
			if(p->isvertical==1)
				playerplatformy=p->vel;
			else
				playerplatformx=p->vel;
			
			// Pues sí
			return 1;
		}
	}
	// Pues no
	return 0;
}
			
// Init all platforms
void InitPlatforms(unsigned char np, platformdef *p)
{
	unsigned char a;
	platform *q;
	platformdef *r;

	// Load platform sprite
	LoadSprite(platform_zx7, PLATFORMBASE,platform_zx7_bank);	
	
	// Number of platforms
	numplatforms=np;
	
	// Load platforms
	for(a=0;a<numplatforms;a++)
	{
		q=&platforms[a];
		r=&p[a];
	
		q->isvertical=r->isvertical;
		q->posx=r->posx;
		q->posy=r->posy;
		q->minval=r->minval;
		q->maxval=r->maxval;
		q->vel=1;
	}
}

// Update platforms
void UpdatePlatforms()
{
	unsigned char a;
	platform *p;
	
	for(a=0;a<numplatforms;a++)
	{
		p=&platforms[a];
		
		if(p->isvertical==1)
		{
			if(p->posx+24>=mapposx && p->posx<mapposx+256)
			{
				if(p->vel>0)
				{
					if(p->posy>=p->maxval-25)p->vel=-p->vel;
				}
				else
				{
					if(p->posy<=p->minval)p->vel=-p->vel;
				}
				p->posy+=p->vel;
				DrawInMapSpriteArray(PLATFORMBASE,p->posx,p->posy,24,24);
			}
		}
		else
		{
			if(p->posy+24>=mapposy && p->posy<mapposy+192)
			{
				if(p->vel>0)
				{
					if(p->posx>=p->maxval-25)p->vel=-p->vel;
				}
				else
				{
					if(p->posx<=p->minval)p->vel=-p->vel;
				}
				p->posx+=p->vel;
				DrawInMapSpriteArray(PLATFORMBASE,p->posx,p->posy,24,24);
			}
		}
	}
}




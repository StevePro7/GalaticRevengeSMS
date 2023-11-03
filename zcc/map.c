#include "includes.h"

void CheckTiling(signed char *vx,signed char *vy,unsigned char a)
{
	// Movement tiles
	if(a==TILE_UP)
		*vy-=1;

	// Movement tiles
	if(a==TILE_DOWN)
		*vy+=1;

	// Movement tiles
	if(a==TILE_LEFT)
		*vx-=1;

	// Movement tiles
	if(a==TILE_RIGHT)
		*vx+=1;
}

unsigned char CheckMovement(unsigned int *x,unsigned int *y, signed char *vvx, signed char *vvy)
{
	unsigned char a,b;
	unsigned int tx,ty;
	signed char vx,vy;
	
	// Cogemos los valores
	tx=*x;
	ty=*y;
	vx=*vvx;
	vy=*vvy;
	
	// Set to 0
	a=0;
	b=0;

	// Horizontal
	if(vx<0)
	{
		if(tx%16>=-vx)
			tx+=vx;
		else
		{
			a=getTileAt(tx+vx,ty);
			if (a!=TILE_SOLID)
				tx+=vx;
			else 
			{
				a=0;
				*vvx=0;
			}
		}
	}
	else if(vx>0)
	{
		if(tx%16<16-vx)
			tx+=vx;
		else
		{
			a=getTileAt(tx+vx,ty);
			if (a!=TILE_SOLID)
				tx+=vx;
			else 
			{
				a=0;
				*vvx=0;
			}
		}
	}

	// Vertical
	if(vy<0)
	{
		if(ty%16>=-vy)
			ty+=vy;
		else
		{
			b=getTileAt(tx,ty+vy);
			if (b!=TILE_SOLID)
				ty+=vy;
			else 
			{
				b=0;
				*vvy=0;
			}
		}
	}
	else if(vy>0)
	{
		if(ty%16<16-vy)
			ty+=vy;
		else
		{
			b=getTileAt(tx,ty+vy);
			if (b!=TILE_SOLID)
				ty+=vy;
			else 
			{
				b=0;
				*vvy=0;
			}
		}
	}
	
	// Assign values
	*x=tx;
	*y=ty;
	
	// Result
	return b==0?a:b;	
}



unsigned char DrawInMapSpriteArray(unsigned char s,unsigned int px,unsigned int py,unsigned char tx, unsigned char ty)
{
	signed int pmx=0,pmy=0,pms=0;
	
	// Check if out
	if((px>=mapposx+256)||(px+tx<=mapposx)||(py>=mapposy+192)||(py+ty<=mapposy))return 0;
		
	// Check if partial out(X)
	pmx=px-mapposx+barromposx;
	
	while(pmx<0)
	{
		pmx+=8;
		s++;
		pms++;
		tx-=8;
	}
	while(pmx+tx>=264)
	{
		tx-=8;
		pms++;
	}
	
	// Check if partial out(Y)
	pmy=py-mapposy+barromposy;
	while(pmy<-8)
	{
		pmy+=8;
		ty-=8;
		s+=(tx>>3);
	}
	while(pmy+ty>=240)
	{
		ty-=8;
	}

	// Draw!
	DrawSpriteArray(s,pmx,pmy,tx,ty,pms);
	
	// OK
	return 1;
}

unsigned char DrawInMapSprite(unsigned char s,unsigned int px,unsigned int py)
{
	// Check if out
	if((px>=mapposx+256)||(px<=mapposx)||(py>=mapposy+192)||(py+8<=mapposy))return 0;
	
	// Draw
	SMS_addSprite(px-mapposx+barromposx,py-mapposy+barromposy,s);
	
	// OK
	return 1;
}

void UpdateMapRow(unsigned char r)
{
	unsigned char a;
	unsigned int c;
	unsigned char e;
	unsigned char z;
	
	// Check trams
	z=maptileposx%32;
	
	// Needed
	c=((maptileposx>>1)+(((maptileposy+r)>>1)*maptilewidth));
	e=(maptileposx%((unsigned char)2))+((((unsigned int)(maptileposy+r))%((unsigned char)2))<<1);
	
	// First position
	SMS_setAddr(XYtoADDR(z,((unsigned int)(maptileposy+r))%((unsigned char)28)));
		
	// First tile
	//SMS_setTile((tempbuffer[c+16]<<2)+e+256);
	SMS_setTile(((unsigned int *)maptilemappings)[(tempbuffer[c+16]<<2)+e]+256);
	if(e%2==1)
	{
		c++;
		e--;
	}else e++;
	
	// Next ?
	if(z<31)
	for(a=0;a<31-z;a++)
	{
		//SMS_setTile((tempbuffer[c]<<2)+e+256);
		SMS_setTile(((unsigned int *)maptilemappings)[(tempbuffer[c]<<2)+e]+256);
		if(e%2==1)
		{
			c++;
			e--;
		}else e++;
	}	
	
	// Finish row
	if(z>0)
	{
		SMS_setAddr(XYtoADDR(0,((unsigned int)(maptileposy+r))%((unsigned char)28)));
		for(a=0;a<z;a++)
		{
			//SMS_setTile((tempbuffer[c]<<2)+e+256);
			SMS_setTile(((unsigned int *)maptilemappings)[(tempbuffer[c]<<2)+e]+256);
			if(e%2==1)
			{
				c++;
				e--;
			}else e++;
		}	
	}
}

void UpdateMapCol(unsigned char t,unsigned char r)
{
	unsigned char a;
	unsigned int d;
	unsigned int c;
	unsigned char e;
	
	// Needed
	c=(((maptileposx+r)>>1)+((maptileposy>>1)*maptilewidth));
	e=(((unsigned int)(maptileposx+r))%((unsigned char)2))+((maptileposy%((unsigned char)2))<<1);
	d=XYtoADDR(((unsigned int)(maptileposx+t))%((unsigned char)32),maptileposy%((unsigned char)28))-SMS_PNTAddress;

	// Draw all 28 tiles
	for(a=0;a<28;a++)
	{
		SMS_setAddr(d+SMS_PNTAddress);
		//SMS_setTile((tempbuffer[c]<<2)+e+256);
		SMS_setTile(((unsigned int *)maptilemappings)[(tempbuffer[c]<<2)+e]+256);
		e+=2;
		if(e>3)
		{
			c+=maptilewidth;
			e-=4;
		}
		d+=64;
		d%=(32*28*2);
	}
}

unsigned char getTileAt(unsigned int x,unsigned int y)
{
	return stagetiletypes[tempbuffer[((y>>4)*maptilewidth)+(x>>4)]];
}

void DrawMap(unsigned char nc)
{
	unsigned char b;
	
	// Draw all lines
	for(b=0;b<nc;b++)
		UpdateMapRow(b);
	
	// Left col fix
	UpdateMapCol(0,32);
}

void InitMap(const unsigned char *mt,unsigned char mb,const unsigned char *stm,unsigned char mw,unsigned char mh,unsigned char initx,unsigned char inity,const unsigned char *stta,const unsigned char *sttb)
{
	// Tiles and banks
	maptiles=mt;
	mapbank=mb;

	// Mappings
	maptilemappings=stm;

	// Caching
	stagetiletypesa=stta;
	stagetiletypesb=sttb;
	
	// Map size in tiles
	maptilewidth=mw;
	maptileheight=mh;

	// Map size
	mapwidth=maptilewidth;
	mapwidth<<=4;
	mapheight=maptileheight;
	mapheight<<=4;

	// Absolute positions and size
	mapposx=initx;
	mapposx<<=4;
	if (mapposx>=MAPOFFSETX)
		mapposx-=MAPOFFSETX;
	else
		mapposx=0;
	if(mapposx>mapwidth-256)
		mapposx=mapwidth-256;
	
	mapposy=inity;
	mapposy<<=4;
	if (mapposy>=MAPOFFSETY)
		mapposy-=MAPOFFSETY;
	else
		mapposy=0;

	if(mapposy>mapheight-224)
		mapposy=mapheight-224;
		
	// Adjust init X
	maptileposx=mapposx>>3;
	maptileposy=mapposy>>3;
	
	// Update Scroll
	SMS_setBGScrollX(-mapposx%256);
	SMS_setBGScrollY(mapposy%224);

	// Reset Barrom
	InitBarrom();
	
	// Decompress
	changeBank(mapbank);
	
	// Uncompress the tilemap
	dzx7_standard(maptiles,tempbuffer);
		
	// Change to default bank
	changeBank(FIXEDBANKSLOT);
	
	// First drawing of map
	DrawMap(28);
}

void MoveMapX(signed int mvx)
{
	// Check if we have not to do nothing
	if(mvx!=0)
	{
		// Move
		if(mvx<0)
		{
			if(mvx<-MAXMAPSPEED)mvx=-MAXMAPSPEED;
			if(mapposx<-mvx)mapposx=0;else mapposx+=mvx;
		}
		else
		{
			if(mvx>MAXMAPSPEED)mvx=MAXMAPSPEED;
			mapposx+=mvx;
			if(mapposx>mapwidth-256)mapposx=mapwidth-256;
		}
	}
}
	
void MoveMapY(signed int mvy)
{
	// Check if we have not to do nothing
	if(mvy!=0)
	{
		// Move
		if(mvy<0)
		{
			if(mvy<-MAXMAPSPEED)mvy=-MAXMAPSPEED;
			if(mapposy<-mvy)mapposy=0;else mapposy+=mvy;
		}
		else // if(maptilewidth!=16)  // Forbide to go back on vertical stages
		{
			if(mvy>MAXMAPSPEED)mvy=MAXMAPSPEED;
			mapposy+=mvy;
			if(mapposy>mapheight-224)mapposy=mapheight-224;
		}
	}
}

void UpdateSideMapX()
{
	unsigned int mtpx;
	
	// Check
	mtpx=mapposx>>3;
	
	// Column right?
	if(mtpx>maptileposx)
	{
		maptileposx=mtpx;
		UpdateMapCol(0,32);
		UpdateEnemySlots();
	}
 
	// Column left
	if(mtpx<maptileposx)
	{
		maptileposx=mtpx;
		UpdateMapCol(1,1);
		UpdateEnemySlots();
	}
}

void UpdateSideMapY()
{
	unsigned int mtpy;
	
	// View if we have to update rows
	mtpy=mapposy>>3;
		
	// Row down?
	if(mtpy>maptileposy)
	{
		maptileposy=mtpy;
		UpdateMapRow(24);
		UpdateEnemySlots();
	}
	
	// Row up?
	if(mtpy<maptileposy)
	{
		maptileposy=mtpy;
		UpdateMapRow(0);
		UpdateEnemySlots();
	}
}
	

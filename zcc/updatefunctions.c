#include "includes.h"

void UpdateParallaxScroll(unsigned char *tiles,unsigned char tilesbank,unsigned int base)
{
	base<<=5;
	
	changeBank(tilesbank);
	for(unsigned char a=0;a<4;a++)
	{
		UNSAFE_SMS_VRAMmemcpy32(base,tiles);
		base+=64;
		tiles+=32;
	}
	changeBank(FIXEDBANKSLOT);
}

void updatespace()
{	
	UpdateParallaxScroll(stage3animtilesa_bin+(((-stageframe2div-(mapposy>>2))%32)<<2),stage3animtilesa_bin_bank,286);
	UpdateParallaxScroll(stage3animtilesb_bin+(((-stageframe2div-(mapposy>>2))%32)<<2),stage3animtilesb_bin_bank,287);
	SMS_setBGPaletteColor(3,lumenanimation[stageframe2div%12]);
}

void updatespmachine()
{
	SMS_setBGPaletteColor(15,lumenanimation[stageframe2div%12]);
}

void updatesliders()
{
	const unsigned char *tiles;
	
	changeBank(stage1animtiles_bin_bank);
	tiles=stage1animtiles_bin+((stageframe2div%8)*(10*32));
	UNSAFE_SMS_VRAMmemcpy64(259<<5,tiles);
	tiles+=(2*32);
	UNSAFE_SMS_VRAMmemcpy64(261<<5,tiles);
	tiles+=(2*32);
	UNSAFE_SMS_VRAMmemcpy64(263<<5,tiles);
	changeBank(FIXEDBANKSLOT);
	
	SMS_setBGPaletteColor(15,lumenanimation[stageframe2div%12]);
}

void updateslidersb()
{
	const unsigned char *tiles;
	
	changeBank(stage1animtiles_bin_bank);
	tiles=stage1animtiles_bin+32+((stageframe2div%8)*(10*32));
	UNSAFE_SMS_VRAMmemcpy64(260<<5,tiles);
	UNSAFE_SMS_VRAMmemcpy32(385<<5,tiles+160);
	UNSAFE_SMS_VRAMmemcpy32(388<<5,tiles+192);
	changeBank(FIXEDBANKSLOT);
		
	SMS_setBGPaletteColor(15,lumenanimation[stageframe2div%12]);
}

void updateslidersc()
{
	const unsigned char *tiles;
	
	changeBank(stage1animtiles_bin_bank);
	tiles=stage1animtiles_bin+((stageframe2div%8)*(10*32));
	UNSAFE_SMS_VRAMmemcpy32(259<<5,tiles);
	tiles+=(3*32);
	UNSAFE_SMS_VRAMmemcpy64(262<<5,tiles);
	tiles+=(2*32);
	UNSAFE_SMS_VRAMmemcpy32(264<<5,tiles);
	tiles+=(3*32);
	UNSAFE_SMS_VRAMmemcpy64(351<<5,tiles);
	
	changeBank(FIXEDBANKSLOT);
			
	SMS_setBGPaletteColor(15,lumenanimation[stageframe2div%12]);
}

void updatebosslighting()
{
	SMS_setBGPaletteColor(15,lumenanimation[stageframe2div%12]);
}

void updatelift()
{
	if(enemies[0].param==2)
	{
		changeBank(liftscroll_bin_bank);
		UNSAFE_SMS_VRAMmemcpy32(314<<5,&liftscroll_bin[(stageframe2div%4)<<5]);
		changeBank(FIXEDBANKSLOT);
		SMS_setBGPaletteColor(15,lumenanimation[stageframe4div%12]);
	}
	else SMS_setBGPaletteColor(15,lumenanimation[0]);
}


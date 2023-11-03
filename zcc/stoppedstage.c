#include "includes.h"

void InitStoppedStage(const labelscr *l)
{
	// Position
	if(stoppedstageexitonkey==1)
	{
		stoppedstagex=maptileposx%32;
		stoppedstagey=maptileposy%28;
	}
	else
	{
		stoppedstagex=0;
		stoppedstagey=0;
	}
	
	// Stop stage
	stagestopped=1;
	stoppedstageframe=0;
	stoppedstagelabel=l;

	// No shoots
	numplayershoots=0;
	
	#ifdef USEPLAYERSHOOTCOUNTER
		playershootcounter=0;	
	#endif
	
	// Background fill
	if (stoppedstageexitonkey==1)
	{
		for(unsigned char b=0;b<5;b++)
			WriteText(marklabels[b],stoppedstagex+2,baselabelsy[l->labelslot]+b+stoppedstagey);
		
		// Hide player if we need it
		if(stoppedstagelabel->labelslot==0)drawplayer=0;
	}
		
	// Image
	if((l->image!=0)&&(l->imagebank!=0))
	{
		LoadSprite(l->image,BASELABELSIMAGE,l->imagebank);
		PutChars(baselabelsimagex[l->labelslot],baselabelsy[l->labelslot]+1+stoppedstagey,3,3,BASELABELSIMAGE);
	}
}

// Update
void UpdateStoppedStage()
{
	unsigned char b;
	unsigned char c;
	const unsigned char *gl;
	
	// Stop player
	playerkeymoved=0;
	
	// If not
	if(stagestopped==0)return;
	
	// If yes
	if(stoppedstageframe<80)
	{
		// Get where we are
		b=(stoppedstageframe%40)>>1;
		
		// Where to put the char
		if(stoppedstageframe<40)
		{
			gl=stoppedstagelabel->labela;
			c=stoppedstagey+1;
		}
		else
		{
			gl=stoppedstagelabel->labelb;
			c=stoppedstagey+3;
		}

		// Put character
		if(putCharacter(gl[b],baselabelsx[stoppedstagelabel->labelslot]+stoppedstagex+b,baselabelsy[stoppedstagelabel->labelslot]+c)!=0)
			if(b%2)
				PlaySound(talk_psg,talk_psg_bank,1,SFX_CHANNEL3);
	}
	
	// Increase counter
	stoppedstageframe++;
	
	// Check for exit
	if((stoppedstageframe==190)||((keystatus&button1)&&(ingame==1)))
	{
		stagestopped=0;
		playerjumpreleased=1;
		
		if (stoppedstageexitonkey==1)
		{
			DrawMap(24);
			
			// Show player if we needed to hide it
			if(stoppedstagelabel->labelslot==0)drawplayer=1;
		}
		else
			for(unsigned char b=1;b<4;b++)
				WriteText(marklabels[5],2,baselabelsy[stoppedstagelabel->labelslot]+b);
	}
}


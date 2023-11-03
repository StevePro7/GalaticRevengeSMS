#include "includes.h"

void UpdateBarrom()
{
	if(barromtime<24)
	{
		// Update scroll
		barromposx=barromx[barromtime>>1];
		barromposy=barromy[barromtime>>1];
		barromtime++;
	}
	else
	{
		barromposx=0;
		barromposy=0;
	}
}

void DoBarrom(unsigned char n)
{
	barromtime=n;
}

void InitBarrom()
{
	barromtime=24;
}
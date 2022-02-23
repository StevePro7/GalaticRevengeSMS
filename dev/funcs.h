#ifndef _FUNCS_H_
#define _FUNCS_H_

//#include "banks/fixedbank.h"

// Eah que no existen en la libreria
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define sign(x) (x > 0) ? 1 : ((x < 0) ? -1 : 0)
#define sinus(x) (sinustable[(x)%256]-128)



#endif//_FUNCS_H_
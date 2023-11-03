#ifndef _SHOOT_H
#define _SHOOT_H

void CreateShoot(shoot *shoots,unsigned char *numshoots,unsigned int sx,unsigned int sy,unsigned char sz,signed char svx,signed char svy,unsigned char ssprite,unsigned char smaxsprite,unsigned char smaxduration);
void RemoveShoot(unsigned char a,shoot *shoots,unsigned char *numshoots);
void UpdateShoots(shoot *shoots,unsigned char *numshoots);
void CheckShootWalls(shoot *shoots,unsigned char *numshoots);

#endif

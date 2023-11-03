#ifndef MAP_H
#define MAP_H

unsigned char DrawInMapSpriteArray(unsigned char s,unsigned int px,unsigned int py,unsigned char tx, unsigned char ty);
unsigned char DrawInMapSprite(unsigned char s,unsigned int px,unsigned int py);
void UpdateMapRow(unsigned char r);
void UpdateMapCol(unsigned char t,unsigned char r);
unsigned char getTileAt(unsigned int x,unsigned int y);
void DrawMap(unsigned char nc);
void InitMap(const unsigned char *mt,unsigned char mb,const unsigned char *stm,unsigned char mw,unsigned char mh,unsigned char initx,unsigned char inity,const unsigned char *stta,const unsigned char *sttb);
void MoveMapX(signed int mvx);
void MoveMapY(signed int mvy);
void UpdateSideMapX();
void UpdateSideMapY();
unsigned char CheckMovement(unsigned int *x,unsigned int *y, signed char *vvx, signed char *vvy);
void CheckTiling(signed char *vx,signed char *vy,unsigned char a);

#endif


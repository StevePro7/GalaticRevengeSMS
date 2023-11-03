#ifndef EXPLOSION_H
#define EXPLOSION_H

void RemoveExplosion(unsigned char a);
void UpdateExplosion(unsigned int a);
void InitExplosion(unsigned int x, unsigned int y,unsigned char t);
void UpdateExplosions();
void InitExplosions();
void InitSpawnedExplosion(unsigned int x, unsigned int y, unsigned char w, unsigned char h,unsigned char e);

#endif


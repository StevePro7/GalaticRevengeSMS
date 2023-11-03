#ifndef PLAYERSHOOT_H
#define PLAYERSHOOT_H

void InitPlayerShoots();
void CheckPlayerShootDamage();
unsigned char CheckPlayerShootDamageEnemy(enemy *en,unsigned char a);
void CreatePlayerShoot();
void UpdatePlayerShoots();

#endif


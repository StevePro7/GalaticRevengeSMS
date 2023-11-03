#ifndef ENEMYSHOOT_H
#define ENEMYSHOOT_H

void InitEnemyShoots();
void CheckEnemyShootDamage();
void UpdateEnemyShoots();
void CreateEnemyShootToPlayer(unsigned int x, unsigned int y,signed char z);
void CreateEnemyShoot(unsigned int posx, unsigned int posy,signed char posz,signed char velx, signed char vely);

#endif


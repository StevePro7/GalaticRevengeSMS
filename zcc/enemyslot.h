#ifndef ENEMYSLOT_H
#define ENEMYSLOT_H

unsigned char enemyslotinsidescreen(enemyslot *en);
unsigned char enemyzoneinsidescreen(enemyzone *zn);
void InitEnemySlots(enemyslot *ens, unsigned char nens,enemyspritebase *enemysprites,unsigned char nesp);
void UpdateEnemySlots();
enemy *InitEnemyByType(unsigned int x, unsigned int y, enemydef *ed);

#endif

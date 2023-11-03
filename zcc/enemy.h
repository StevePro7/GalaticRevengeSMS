#ifndef ENEMY_H
#define ENEMY_H

void RemoveEnemy(enemy *ea);
void KillEnemy(enemy *en,unsigned char doexplosion);
void KillEnemies(enemy *en);
void DamageEnemy(enemy *en);
void UpdateEnemy(enemy *en);
void UpdateEnemies();
enemy *InitEnemy(unsigned int x, unsigned int y,enemydef *ed,signed char p, signed char s,unsigned char b);
void InitEnemies();
void DrawEnemiesA();
void DrawEnemiesB();
void damageenemy(enemy *en);
#endif


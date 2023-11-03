#ifndef PLAYER_H
#define PLAYER_H

void InitPlayer(unsigned int x, unsigned int y, unsigned char side);
unsigned char UpdatePlayerDie();
void UpdatePlayerDirection();
unsigned char UpdatePlayerWalk();
void UpdatePlayerDamaged(unsigned char phase);
void UpdatePlayerJump();
unsigned char UpdatePlayer();
void DrawPlayer();
void UpdatePlayerFall();
void FallPlayer();
void CheckPlayerDamage();
void CheckPlayerTiling();
void DrawFallPlayer();
void DamagePlayer();

/*
void DiePlayer();
void UpdatePlayerShoot();
void CheckPlayerShootDamageEnemy(enemy *e,unsigned int px, unsigned int py);
void CheckPlayerShootDamage();
void CheckPlayerDamageEnemy(enemy *en);
void UpdatePlayerIndicators();
*/

#endif

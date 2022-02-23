#ifndef _FIXEDBANK_H
#define _FIXEDBANK_H

#include "../defines.h"

// About
//extern const unsigned char *abouttext[];
//#define aboutpalette_bin_bank FIXEDBANKSLOT
//extern const unsigned char aboutpalette_bin[];

// BAlout
extern const MyBaloutUpdateFunction baloutupdatefunctions[];
extern const unsigned char baloutgameoverlabel[];

extern const unsigned char baloutpressanykey[];
extern const unsigned char baloutstagelabel[];
extern const unsigned char baloutgameoverlabel[];


// For blobs
extern const signed char blobrandvelx[];
extern const signed char blobrandvely[];
extern const signed char blobrandvelqx[];
extern const signed char blobrandvelqy[];

// Other lavels
extern const unsigned char *jukebox_levels[];
extern const unsigned char *jukebox_buttons[];

// Enemy definitions
extern const enemydef ENEMY_LASER;
extern const enemydef ENEMY_HOMING;
extern const enemydef ENEMY_WALKROBOT;
extern const enemydef ENEMY_MISSILE;

// Flying boss Z
extern const unsigned char flyingbossz[];

// Group of shoots for flyingboss
extern const signed char flyingbossmultipleshootx[];
extern const signed char flyingbossmultipleshooty[];

// Courtain
extern const unsigned char *courtainframes[];
extern const unsigned char courtainframesbank[];

// Bases for the player
extern const unsigned char playerbases[];

// Default palette
#define palette_bin_bank FIXEDBANKSLOT
extern const unsigned char palette_bin[];

// Paleta intro
extern const unsigned char intropalette1[];
extern const unsigned char intropalette2[];

// Game over labels
extern const unsigned char gameover_label_a[];
extern const unsigned char gameover_label_b[];

// Colors for title
extern const unsigned char titlepalette[];
extern const unsigned char titlecolors[];
extern const unsigned char titlecolorsp[];

// Pivots
extern const signed char farpivotx[];
extern const signed char farpivoty[];

// Title labels
extern const unsigned char *title_labels[];
extern const unsigned char title_press_key[];
extern const unsigned char title_press_key_empty[];

// Jukebox labels
extern const unsigned char *jukebox_labels[];
extern const unsigned char *jukebox_names[];

// Songs
extern const unsigned char *jukebox_songs[];
extern const unsigned char jukebox_banks[];
extern const unsigned char jukebox_repeat[];

// Movimientos de barrom
extern const unsigned char barromx[];
extern const unsigned char barromy[];

// Constantes de definicion de fases
extern stagedef stagesdefinition[];

// If damaged
extern const signed char damagevelx[];
extern const signed char damagevely[];

// Default playershoot vels
extern const signed char playershootavelx[];
extern const signed char playershootavely[];

extern const signed char playershootbavelx[];
extern const signed char playershootbavely[];
extern const signed char playershootbbvelx[];
extern const signed char playershootbbvely[];

extern const signed char playershootcbvelx[];
extern const signed char playershootcbvely[];
extern const signed char playershootccvelx[];
extern const signed char playershootccvely[];

// Max player shoots
extern const unsigned char playershootmax[];

// Sprites for player shoot
extern const void *playershootsprites[];
extern const unsigned char playershootspritesbank[];

// Sprites for player
extern const void *playersprites[];
extern const unsigned char playerspritesbank[];
extern const void *playerfallsprites[];
extern const unsigned char playerfallspritesbank[];

// Bases for the player shoot
extern const unsigned char playershootdbases[];
extern const unsigned char playershootbabases[];
extern const unsigned char playershootbbbases[];
extern const unsigned char playershootcbbases[];
extern const unsigned char playershootccbases[];

// References for shoots
extern const signed char playershootrefx[];
extern const signed char playershootrefy[];

// Foot anim
extern const unsigned char footanim[];

// Definitions
extern const introdef introdefinition;
extern const introdef endingdefinition;

// Stars
extern const unsigned int introstarsx[];
extern const unsigned int introstarsv[];
extern const unsigned int titlestarsy[];

// Clothes
extern const unsigned char clothesx[];
extern const unsigned char clothesy[];
extern const unsigned int clothesz[];

extern const unsigned char *shopcornersx[];
extern const unsigned char shopcornersy[];
extern const unsigned int shopcornersempty[];
extern const unsigned int shopcorners[];
extern const unsigned char *shoplabels[];
extern const unsigned char *shoplabelssold[];
extern const unsigned char clothesprice[];

// Mark labels
extern const unsigned char *marklabels[];
extern const unsigned char *marklabelsshop[];
extern const unsigned char baselabelsx[];
extern const unsigned char baselabelsy[];
extern const unsigned char baselabelsimagex[];

// Laser colors
extern const unsigned char introlasercolors[];

// Intro
extern const unsigned char introwaves[];
extern const unsigned char introastro[];

// Lumen animation
extern const unsigned char lumenanimation[];

#endif

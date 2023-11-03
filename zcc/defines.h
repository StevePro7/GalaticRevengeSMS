#ifndef _DEFINES_H
#define _DEFINES_H

// Truqui
#define PLAYERINMUNENO

// Balout
typedef void (*MyBaloutUpdateFunction)(void);

// Estados del player
#define PLAYER_DAMAGED 1
#define PLAYER_DAMAGEDB 2
#define PLAYER_DIE 3
#define PLAYER_JUMP 4
#define PLAYER_WALK 5
#define PLAYER_FALL 6
		
// Velocidades del player
#define PLAYERFALLMAX 4
#define PLAYERWALKSPEED 2
#define PLAYERJUMPFORCE 11

// Tiempo para disparar de nuevo
#define PLAYERSHOOTCOUNTERDEFAULT 4
#define NOUSEPLAYERSHOOTCOUNTER

// Damages
#define DAMAGEVEL 2
#define DAMAGEVELZ 7
#define DAMAGEVELZB 4

// Player shoot durations
#define PLAYERSHOOTADURATION 6
#define PLAYERSHOOTBDURATION 8
#define PLAYERSHOOTCDURATION 8
#define PLAYERSHOOTDDURATION 50

// Player shoot max quantities
#define PLAYERSHOOTAQUANTITY 1
#define PLAYERSHOOTBQUANTITY 2
#define PLAYERSHOOTCQUANTITY 3
#define PLAYERSHOOTDQUANTITY 3

// Max sprites for playershoots
#define PLAYERSHOOTAMAXSPRITES 4
#define PLAYERSHOOTBMAXSPRITES 0
#define PLAYERSHOOTCMAXSPRITES 0
#define PLAYERSHOOTDMAXSPRITES 0

// For enemy shoots
#define ENEMYSHOOTDURATION 100
#define ENEMYSHOOTMAXSPRITES 2
#define ENEMYSHOOTMINDIST 64
#define ENEMYSHOOTSPEED 4

// Time of inmunity
#define PLAYERINMUNITYTIME 32

// Gravedad
#define GRAVITY 1

// Hacia donde se mira
#define PLAYER_UP 1
#define PLAYER_RIGHT 2
#define PLAYER_DOWN 4
#define PLAYER_LEFT 8

// Tipo de tiles
#define TILE_EMPTY 1
#define TILE_SOLID 2
#define TILE_FLOOR 3
#define TILE_DEAD 4
#define TILE_EXIT 5
#define TILE_UP 6
#define TILE_LEFT 7
#define TILE_RIGHT 8
#define TILE_DOWN 9

// Enemigos
typedef struct _enemydef enemydef;
typedef struct enemy
{
	enemydef *ed;
	signed char side;
	signed char velx;
	signed char vely;	
	signed char velz;
	unsigned int posx;
	unsigned int posy;	
	unsigned char  posz;	
	unsigned char state;	
	unsigned char tile;
	unsigned char energy;
	unsigned int frame;
	signed char param;
	signed char slot;
	unsigned char base;
	signed char sprite;
	unsigned int centerx;
	unsigned int centery;
}enemy;

// Funcs
typedef void (*MyInitEnemyFunction)(enemy *);
typedef unsigned char (*MyUpdateEnemyFunction)(enemy *);
typedef void (*MyCollideEnemyFunction)(enemy *);
typedef void (*MyDamageEnemyFunction)(enemy *);
typedef void (*MyKillEnemyFunction)(enemy *);
typedef void (*MyStageUpdateFunction)(void);

typedef struct enemyzone
{
	unsigned int zoneleft;
	unsigned int zoneright;
	unsigned int zonetop;
	unsigned int zonebottom;
}enemyzone;

// Enemy definitions
struct _enemydef
{
	unsigned char energy;
	unsigned char damageable;
	unsigned char dangerous;
	unsigned char gravity;	
	unsigned char collideable;
	unsigned char width;
	unsigned char height;
	MyInitEnemyFunction eif;
	MyUpdateEnemyFunction euf;
	MyCollideEnemyFunction ecf;
	MyDamageEnemyFunction edf;
	MyKillEnemyFunction ekf;
};

// Enemy slot
typedef struct enemyslot
{
	unsigned int posx;
	unsigned int posy;	
	signed char param;
	enemydef *ed;	
	unsigned char usezone;	
	enemyzone zone;
}enemyslot;

// Enemy sprites
typedef struct enemyspritebase
{
	enemydef *ed;	
	unsigned char base;
	void *sprite;
	unsigned char spritebank;
}enemyspritebase;

typedef struct platformdef
{
	unsigned int posx;
	unsigned int posy;
	unsigned int minval;
	unsigned int maxval;
	unsigned char isvertical;
}platformdef;

// Stage definitions
typedef struct stagedef
{
	unsigned char exitablestage;
	unsigned char stageplayerinitx;
	unsigned char stageplayerinity;
	unsigned char stageplayerside;
	unsigned char *stagepalette;
	unsigned char stagepalettebank;
	unsigned char *stagetilemap;
	unsigned char stagetilemapbank;
	unsigned int stagewidth;
	unsigned int stageheight;
	unsigned char *stagetilemappings;
	unsigned char *stagetiles;
	unsigned char stagetilesbank;
	unsigned char *stagemusic;
	unsigned char stagemusicbank;
	MyStageUpdateFunction stageupdatecustomfunc;
	enemyslot *enemies;
	unsigned char numenemies;
	enemyspritebase *enemysprites;
	unsigned char numenemysprites;
	platformdef *platforms;
	unsigned char numplatforms;
	unsigned char *stagetiletypesa;
	unsigned char *stagetiletypesb;	
}stagedef;

// Shoots
typedef struct shoot
{
	unsigned int posx;
	unsigned int posy;
	unsigned char posz;
	signed char velx;
	signed char vely;
	unsigned char sprite;
	unsigned char maxsprite;
	unsigned char maxduration;
}shoot;

// Goodies
typedef struct goodie
{
	unsigned int posx;
	unsigned int posy;
	unsigned char posz;
	signed char velz;
	unsigned char goodie;
	unsigned char state;
}goodie;

// Default bank for fixed bank
#define FIXEDBANKSLOT 7

// Stages
#define TOTAL_STAGES 23
#define ENDING_STAGE TOTAL_STAGES
#define GAMEOVER_STAGE TOTAL_STAGES+1
#define EXIT_STAGE TOTAL_STAGES+2

// Game config
#define DEFAULT_LIFES 3
#define MAX_LIFES 6

// Cursors for jukebox
#define CURSORSBASE 0

// Number of songs in jukebox
#define JUKEBOX_SONGS 9

// Max explosions
#define MAXEXPLOSIONS 4

// Max enemies
#define MAXENEMIES 10

// Max enemyslots
#define MAXENEMYSLOTS 40

// Max shoots
#define MAXPLAYERSHOOTS PLAYERSHOOTDQUANTITY
#define MAXENEMYSHOOTS 6

// Goodies
#define MAXGOODIES 4

// Explosions
typedef struct explosion
{
	unsigned int posx;
	unsigned int posy;
	unsigned char extype;
	unsigned char sprite;
}explosion;

// Map
#define MAXMAPSPEED 4
#define MAPOFFSETX 120
#define MAPOFFSETY 112

// Margin
#define MAPMARGIN 16

// Sprite bases
#define PLAYERBASE 0
#define PLAYERUPBASE (PLAYERBASE+0)
#define PLAYERUPRIGHTBASE (PLAYERBASE+14)
#define PLAYERRIGHTBASE (PLAYERBASE+14)
#define PLAYERDOWNRIGHTBASE (PLAYERBASE+14)
#define PLAYERDOWNBASE (PLAYERBASE+28)
#define PLAYERDOWNLEFTBASE (PLAYERBASE+42)
#define PLAYERLEFTBASE (PLAYERBASE+42)
#define PLAYERUPLEFTBASE (PLAYERBASE+42)
#define PLAYERFALLBASE (PLAYERBASE+56)
#define PLAYERINDICATORBASE (PLAYERBASE+68)
#define PLAYERCOINBASE (PLAYERBASE+69)
#define PLAYERSHOOTBASE (PLAYERBASE+70)
#define SHADOWBASE (PLAYERBASE+78)
#define BIGEXPLOSIONBASE (PLAYERBASE+79)
#define LITTLEEXPLOSIONBASE (PLAYERBASE+91)
#define NUMBERSBASE (PLAYERBASE+94)
#define ENEMYSHOOTBASE (PLAYERBASE+104)
#define PLATFORMBASE (PLAYERBASE+106)
#define ENEMYBASE (PLAYERBASE+115)

// Player shoot bases
#define PLAYERSHOOTUPBASE (PLAYERSHOOTBASE+0)
#define PLAYERSHOOTRIGHTBASE (PLAYERSHOOTBASE+1)
#define PLAYERSHOOTDOWNBASE (PLAYERSHOOTBASE+2)
#define PLAYERSHOOTLEFTBASE (PLAYERSHOOTBASE+3)
#define PLAYERSHOOTUPRIGHTBASE (PLAYERSHOOTBASE+4)
#define PLAYERSHOOTDOWNRIGHTBASE (PLAYERSHOOTBASE+5)
#define PLAYERSHOOTDOWNLEFTBASE (PLAYERSHOOTBASE+6)
#define PLAYERSHOOTUPLEFTBASE (PLAYERSHOOTBASE+7)

// Intro bases
#define INTROSHIP_BASE (0)
#define INTROBOSS_BASE (18)
#define INTROSTAR_BASE (18+54)
#define INTROPLANETSLIDE_BASE (18+54+1)
#define INTROLITTLESHIP_BASE  (18+54+1+4)
#define INTROFLYINGMAN_BASE   (ENEMYBASE)
#define INTROFLYINGMANB_BASE  (ENEMYBASE+1)
#define INTROTHEEND_BASE      (ENEMYBASE+1+1)
#define BROKENPLANET_BASE     (37+256)

// Labels image
#define BASELABELSIMAGE 391

// Labels
typedef struct labelscr
{
	const unsigned char labela[21];
	const unsigned char labelb[21];
	const void *image;
	const unsigned char imagebank;
	const unsigned char labelslot;
}labelscr;

// Intro definition (common for init&ending)
typedef struct introdef
{
	const MyStageUpdateFunction *functions;
	const unsigned char exitstate;
	const unsigned char numlabels;
	const unsigned int *statetime;
	const unsigned int *labelstime;
	const labelscr *labels;
}introdef;

// Platform definition

#define MAXPLATFORMS 6
typedef struct platform
{
	unsigned char isvertical;
	unsigned int posx;
	unsigned int posy;
	unsigned int maxval;
	unsigned int minval;
	signed char vel;
}platform;

// Gusan velocities
#define GUSANVELX 3
#define GUSANVELY 2

#endif

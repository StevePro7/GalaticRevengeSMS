#include "bank7.c"
#include "../defines.h"
#include "../includes.h"
#include "stage3tilesmapping.bin.h"
#include "stage1tilesmapping.bin.h"

// Balout Functions
extern MyBaloutUpdateFunction baloutloadtitle;
extern MyBaloutUpdateFunction baloutshowstage;
extern MyBaloutUpdateFunction baloutupdatemap;
extern MyBaloutUpdateFunction baloutgameover;
	
const MyBaloutUpdateFunction baloutupdatefunctions[]=
{
	baloutloadtitle,
	baloutshowstage,
	baloutupdatemap,
	baloutgameover,
};

const unsigned char baloutpressanykey[]="PRESS ANY KEY";
const unsigned char baloutstagelabel[]="STAGE";
const unsigned char baloutgameoverlabel[]="GAME OVER";

// About 
/*
const unsigned char *abouttext[]=
{
	"        GALACTIC REVENGE        ",
	"    ADVENTURES OF OLIVIA GUN    ",
	"",
	"    SMSPOWER COMPETITION 2018   ",
	"",
	"           THANKS TO            ",
	"",
	"    SDCC AND Z88DK DEVELOPERS   ",
	" SVERX FOR HIS SMS AND PSG LIBS ",
	"  PSG2MOD MAPPY PAINT[NET DEVS  ",
	"",
	" RAY COMMEND FOR HIS BOX DESIGN ",
	"  AND A NICE NAME FOR THE GIRL  ",
	"",
	"      RICHARD MORGAN FOR HIS    ",
	"    AWESOME GAME ILLUSTRATION   ",
	"",
	"   ALEXANDER VORMBROCK FOR HIS  ",
	"     DEEP TESTING AND ADVICE    ",
	"",
	"   THIS GAME IS FREE TO PLAY    ",
	"    ALL OTHER RIGHTS RESERVED   ",
};
*/

// For blobs
const signed char blobrandvelx[]={1,0,0,-1};
const signed char blobrandvely[]={0,1,-1,0};
const signed char blobrandvelqx[]={16,0,0,-16};
const signed char blobrandvelqy[]={0,16,-16,0};


// Clothes
const unsigned char clothesx[]={7,8,7,8,11,12,11,12,15,16,15,16,21,22,21,22};
const unsigned char clothesy[]={4,4,5,5,4,4,5,5,4,4,5,5,4,4,5,5};
const unsigned int clothesz[]={391,391|0x0200,392,392|0x0200,393,393|0x0200,394,394|0x0200,395,395|0x0200,396,396|0x0200,397,397,397,397};

const unsigned char shopcornersxa[]={6,9,6,9};
const unsigned char shopcornersxb[]={10,13,10,13};
const unsigned char shopcornersxc[]={14,17,14,17};
const unsigned char shopcornersxd[]={20,23,20,23};
const unsigned char *shopcornersx[]={shopcornersxa,shopcornersxb,shopcornersxc,shopcornersxd};
const unsigned char *shoplabels[]=
{
	"FIRE SUIT   10 COINS",
	"SNAKE SUIT  20 COINS",
	"ASTRO SUIT  30 COINS",
	"   EXIT THE ROOM    "
};
const unsigned char *shoplabelssold[]=
{
	"FIRE SUIT       SOLD",
	"SNAKE SUIT      SOLD",
	"ASTRO SUIT      SOLD",
	"   EXIT THE ROOM    "
};

const unsigned char shopcornersy[]={3,3,6,6};
const unsigned int shopcornersempty[]={445,445,445,445};
const unsigned int shopcorners[]={398,398|0x0200,398|0x0400,398|0x0600};
const unsigned char clothesprice[]={10,20,30};

// Courtains
const unsigned char *courtainframes[]={change7_zx7,change6_zx7,change5_zx7,change4_zx7,change3_zx7,change2_zx7,change1_zx7,change0_zx7,changeclosed_zx7};
const unsigned char courtainframesbank[]={change7_zx7_bank,change6_zx7_bank,change5_zx7_bank,change4_zx7_bank,change3_zx7_bank,change2_zx7_bank,change1_zx7_bank,change0_zx7_bank,changeclosed_zx7_bank};

// Bases for the player
const unsigned char playerbases[]={0,PLAYERUPBASE,PLAYERRIGHTBASE,PLAYERUPRIGHTBASE,PLAYERDOWNBASE,0,PLAYERDOWNRIGHTBASE,0,PLAYERLEFTBASE,PLAYERUPLEFTBASE,0,0,PLAYERDOWNLEFTBASE,0,0,0};

// Movements on damage
const signed char damagevelx[]={0,0,-DAMAGEVEL,-DAMAGEVEL,0,0,-DAMAGEVEL,0,DAMAGEVEL,DAMAGEVEL,0,0,DAMAGEVEL,0,0,0};
const signed char damagevely[]={0,DAMAGEVEL,0,DAMAGEVEL,-DAMAGEVEL,0,-DAMAGEVEL,0,0,DAMAGEVEL,0,0,-DAMAGEVEL,0,0,0};

// Player shoot A&D Movements 
const signed char playershootavelx[]={0, 0,3*2, 2*2,0,0,2*2,0,-3*2,-2*2,0,0,-2*2,0,0,0};
const signed char playershootavely[]={0,-3*2,0,-2*2,3*2,0,2*2,0, 0,-2*2,0,0, 2*2,0,0,0};

// Bases for player shoot D
const unsigned char playershootdbases[]={0,PLAYERSHOOTUPBASE,PLAYERSHOOTRIGHTBASE,PLAYERSHOOTUPRIGHTBASE,PLAYERSHOOTDOWNBASE,0,PLAYERSHOOTDOWNRIGHTBASE,0,PLAYERSHOOTLEFTBASE,PLAYERSHOOTUPLEFTBASE,0,0,PLAYERSHOOTDOWNLEFTBASE,0,0,0};

// Movements for Player shoot B
const signed char playershootbavelx[]=   {0, 1, 5, 3, 1,0,4,0,-5,-4,0,0,-3,0,0,0};
const signed char playershootbavely[]=   {0,-5,-1,-4, 5,0,3,0, 1,-3,0,0, 4,0,0,0};
const signed char playershootbbvelx[]=   {0,-1, 5, 4,-1,0,3,0,-5,-3,0,0,-4,0,0,0};
const signed char playershootbbvely[]=   {0,-5, 1,-3, 5,0,4,0,-1,-4,0,0, 3,0,0,0};

// Bases for player shoot B
const unsigned char playershootbabases[]={0,PLAYERSHOOTBASE+0,PLAYERSHOOTBASE+1,PLAYERSHOOTBASE+0,PLAYERSHOOTBASE+3,0,PLAYERSHOOTBASE+2,0,PLAYERSHOOTBASE+5,PLAYERSHOOTBASE+6,0,0,PLAYERSHOOTBASE+4,0,0,0};
const unsigned char playershootbbbases[]={0,PLAYERSHOOTBASE+7,PLAYERSHOOTBASE+2,PLAYERSHOOTBASE+1,PLAYERSHOOTBASE+4,0,PLAYERSHOOTBASE+3,0,PLAYERSHOOTBASE+6,PLAYERSHOOTBASE+7,0,0,PLAYERSHOOTBASE+5,0,0,0};

// Movements for Player shoot C
const signed char playershootcbvelx[]={0,-2*2,   2*2,    0, 2*2, 0,    0,  0,  -2*2,     0, 0, 0, -3*2,0,0,0};
const signed char playershootcbvely[]={0,-2*2,  -2*2, -3*2, 2*2, 0,  3*2,  0,   2*2,  -3*2, 0, 0,    0,0,0,0};

const signed char playershootccvelx[]={0, 2*2,   2*2,  3*2,-2*2, 0,  3*2,  0,  -2*2,  -3*2, 0, 0,    0,0,0,0};
const signed char playershootccvely[]={0,-2*2,   2*2,    0, 2*2, 0,    0,  0,  -2*2,     0, 0, 0,  3*2,0,0,0};

// Bases for player shoot D
const unsigned char playershootcbbases[]={0,PLAYERSHOOTUPLEFTBASE,PLAYERSHOOTUPRIGHTBASE,PLAYERSHOOTUPBASE,PLAYERSHOOTDOWNRIGHTBASE,0,PLAYERSHOOTDOWNBASE,0,PLAYERSHOOTDOWNLEFTBASE,PLAYERSHOOTUPBASE,0,0,PLAYERSHOOTLEFTBASE,0,0,0};
const unsigned char playershootccbases[]={0,PLAYERSHOOTUPRIGHTBASE,PLAYERSHOOTDOWNRIGHTBASE,PLAYERSHOOTRIGHTBASE,PLAYERSHOOTDOWNLEFTBASE,0,PLAYERSHOOTRIGHTBASE,0,PLAYERSHOOTUPLEFTBASE,PLAYERSHOOTLEFTBASE,0,0,PLAYERSHOOTDOWNBASE,0,0,0};

// Refs for shoots
const signed char playershootrefx[]={0,  0, 6, 4, 0,0,4,0,-6,-4,0, 0,-4,0,0,0};
const signed char playershootrefy[]={0,-18,-8,-8, -8,0,0,0,-8,-8,0,0,  -8,0,0,0};

// Sprites for player shoot
const void *playershootsprites[]={playershoot_zx7,playershootb_zx7,playershootc_zx7,playershootd_zx7};
const unsigned char playershootspritesbank[]={playershoot_zx7_bank,playershootb_zx7_bank,playershootc_zx7_bank,playershootd_zx7_bank};

// Sprites for player
const void *playersprites[]={player_zx7,playerb_zx7,playerc_zx7,playerd_zx7,playerdb_zx7};
const unsigned char playerspritesbank[]={player_zx7_bank,playerb_zx7_bank,playerc_zx7_bank,playerd_zx7_bank,playerdb_zx7_bank};
const void *playerfallsprites[]={playerfall_zx7,playerfallb_zx7,playerfallc_zx7,playerfalld_zx7};
const unsigned char playerfallspritesbank[]={playerfall_zx7_bank,playerfallb_zx7_bank,playerfallc_zx7_bank,playerfalld_zx7_bank};

// Paleta por defecto
const unsigned char palette_bin[]={0x00,0x3F,0x00,0x11,0x3A,0x38,0x3E,0x0C,0x08,0x04,0x1F,0x2F,0x1B,0x07,0x02,0x16};
//const unsigned char aboutpalette_bin[]={0x00,0x3a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// Paleta intro
const unsigned char intropalette1[]={0x00,0x3f,0x3b,0x23,0x11,0x26,0x10,0x38,0x30,0x3c,0x1f,0x1f,0x07,0x11,0x11,0x00};
const unsigned char intropalette2[]={0x00,0x3f,0x3b,0x23,0x11,0x26,0x28,0x25,0x2b,0x20,0x2a,0x15,0x11,0x11,0x11,0x00};

// Title palette
const unsigned char titlepalette[]={0x11,0x3f,0x00,0x00,0x00,0x13,0x20,0x10,0x3a,0x2a,0x00,0x00,0x00,0x00,0x00,0x00};
const unsigned char titlecolors[]={15,12,9,13,14,4,3,2,11};
const unsigned char titlecolorsp[]={0x13,0x17,0x1b,0x1f,0x1b,0x17,0x13,0x12,0x12}; // Pinks

// Game overs
const unsigned char gameover_label_a[]="GAME  OVER";
const unsigned char gameover_label_b[]="PRESS FIRE TO CONTINUE";

// Title labels
const unsigned char *title_labels[]=
{
	"A GAME BY MIKE RUIZ",
	"RELEASE BY MIKGAMES",
	"SMSPOWER COMP[ 2018"
};
const unsigned char title_press_key[]=      "PRESS FIRE AND PLAY";
const unsigned char title_press_key_empty[]="                   ";

// Jukebox
const unsigned char *jukebox_labels[]={"   GAME OPTIONS","","BUTTONS","LEVEL","STOCK","MUSIC","INIT GAME"};
const unsigned char *jukebox_names[]=
{
	"THEY MADE IT  ",
	"IN THE OUTLET ",
	"OUTER SPACE   ",
	"BREAKING NEWS ",
	"SNAKE MAMBO   ",
	"FINAL THOUGHTS",
	"BIG BIG BOSS  ",
	"YOU MADE IT   ",
	"YOU FAILED    "
};

const unsigned char *jukebox_levels[]={"EASY","HARD"};
const unsigned char *jukebox_buttons[]={"NORMAL ","INVERSE"};

// Songs
const unsigned char *jukebox_songs[]=
{
	intro_psg,
	shop_psg,
	stage1_psg,
	stage2_psg,
	stage3_psg,
	stage4_psg,
	boss_psg,
	ending_psg,
	gameover_psg
};

// Song banks
const unsigned char jukebox_banks[]=
{
	intro_psg_bank,
	shop_psg_bank,
	stage1_psg_bank,
	stage2_psg_bank,
	stage3_psg_bank,
	stage4_psg_bank,
	boss_psg_bank,
	ending_psg_bank,
	gameover_psg_bank
};

// Repeat of songs
const unsigned char jukebox_repeat[]={0,1,1,1,1,1,1,0,0};
	
// Player foot anim
const unsigned char footanim[]={2,6,2,10};
	
// Movimientos de barrom
const unsigned char barromx[]={4,0,4,0,3,0,3,0,2,0,2,0};	// Patron X del barrom
const unsigned char barromy[]={8,0,7,0,6,0,5,0,4,0,3,0};	// Patron Y del barrom

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ending definitions
extern void endingfunction2(void);
extern void endingfunction14(void);
extern void endingfunction15(void);
extern void endingfunction16(void);
extern void endingfunction17(void);
extern void endingfunction18(void);
extern void endingfunction19(void);
extern void endingfunction20(void);

const MyStageUpdateFunction endingfunctions[]=
{
	introfunction10,
	introfunction17,
	introfunction16,
	endingfunction2,
	introfunction16,
	introfunction13,
	endingfunction14,
	endingfunction15,
	endingfunction16,
	endingfunction17,
	endingfunction15,
	endingfunction18,
	endingfunction19,
	endingfunction20,
};

const unsigned int endingstatestime[]={0,1,25,250,600,601,900,1215,1216,3520,3750,3751,3837,4200};
const unsigned int endinglabelstime[]={350,1000,1500,1725,1950,2175,2500,2725,3000,3200};

const labelscr endinglabels[]=
{                     
	{"NOW THAT I AM SAFE  ","LETS FINISH THE JOB_",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"MY REVENGE IS DONE_ ","LETS RETURN HOME_   ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	
	{"IT HAS BEEN A HARD  ","ADVENTURE FOR SURE_ ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"I WOULD NOT CAME SO ","FAR IF MY CONSOLE[[[",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"WERE A GRAY UGLY BOX","BORING LIKE HELL_   ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"BUT THAT IS         ","OTHER STORY[[[      ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	
	{"MESSAGE FROM THE DEV","    CONGRATULATIONS_",facemike_zx7,facemike_zx7_bank,1},
	{"     GLAD YOU PLAYED","   THIS LITTLE GAME_",facemike_zx7,facemike_zx7_bank,1},
	
	{"I HAVE OTHER KIND OF","NEW GAMES AT HOME[[[",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"SO I MUST RETURN NOW","SEE YOU SOON___     ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
};
	
const introdef endingdefinition=
{
	endingfunctions,
	14,10,
	endingstatestime,
	endinglabelstime,
	endinglabels
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Intro definitions

extern void introfunction0(void);
extern void introfunction2(void);
extern void introfunction3(void);
extern void introfunction4(void);
extern void introfunction6(void);
extern void introfunction9(void);
extern void introfunction10(void);
extern void introfunction11(void);
extern void introfunction12(void);
extern void introfunction13(void);
extern void introfunction14(void);
extern void introfunction15(void);
extern void introfunction16(void);
extern void introfunction17(void);
extern void introfunction18(void);
extern void introfunction19(void);

const MyStageUpdateFunction introfunctions[]=
{
	introfunction0,
	0,
	introfunction2,
	introfunction3,
	introfunction4,
	introfunction3,
	introfunction6,
	introfunction3,		
	0,	
	introfunction9,		
	introfunction10,	
	introfunction11,	
	introfunction12,	
	introfunction13,	
	introfunction14,	
	introfunction15,	
	introfunction16,	
	introfunction17,	
	introfunction18,	
};

const unsigned int introstatestime[]={0,300,301,383,432,540,541,550,700,750,751,2688,2800,2801,3100,3200,3650,3651,3880};
const unsigned int introlabelstime[]={50,800,1000,1200,1400,1600,1800,2000,2200,2400,3250,3450};

const labelscr introlabels[]=
{                     
	{"YEAR 33XXX IN A FAR ","AND DIRTY GALAXY[[[ ",0,0,0},
	{"YOU CANNOT SCAPE AND","WILL SUFFER MY ANGER",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"     YOU DO NOT HAVE"," NOTHING TO DO HUMAN",facerobot_zx7,facerobot_zx7_bank,1},
	{"FIRST YOU EMPTIED   ","MY REFRIGERATOR     ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"AND THEN YOU KILLED ","MY BOYFRIEND        ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"AND FINALLY THE     ","MOST SERIOUS[[[     ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"YOU STOLE MY LOVED  ","MASTER SYSTEM_      ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"     YOU GUESSED IT_","  THAT WAS THE PLAN_",facerobot_zx7,facerobot_zx7_bank,1},
	{"THIS IS THE FUNNIEST","  MACHINE EVER DONE_",facerobot_zx7,facerobot_zx7_bank,1},
	{"I WILL RECOVER IT   ","I PROMISE___        ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
	{"    OH MY ALIEN GOD_","   WE HAVE A BREACH_",facerobot_zx7,facerobot_zx7_bank,1},
	{"NOW I WILL ENTER_   ","PREPARE TO DIE_     ",faceplayerintro_zx7,faceplayerintro_zx7_bank,0},
};
	
const introdef introdefinition=
{
	introfunctions,
	19,12,
	introstatestime,
	introlabelstime,
	introlabels
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Stars
const unsigned int introstarsx[]={48,128,64,80,192,160,240,144,32,160,80};
const unsigned int introstarsv[]={0,1,0,2,1,2,0,1,0,2,1};
const unsigned int titlestarsy[]={0,8,16,88,96,120,128,184,176,168};

// Laser colors
const unsigned char introlasercolors[]={0x0f,0x0a,0x05};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

const unsigned char *marklabels[]=
{
	":;;;;;;;;;;;;;;;;;;;;;;;;;;<",
	"=                          >",
	"=                          >",
	"=                          >",
	"?@@@@@@@@@@@@@@@@@@@@@@@@@@\\",
	"                            "
};

const unsigned char *marklabelsshop[]=
{
	":;;;;;;;;;;;;;;;;;;;;;;<",
	"=    CLOTHES RESALE    >",
	"=                      >",
	"=                      >",
	"=                      >",
	"=                      >",
	"=                      >",
	"?@@@@@@@@@@@@@@@@@@@@@@\\",
	"                        "
};

const unsigned char baselabelsx[]={7,3};
const unsigned char baselabelsy[]={18,1};
const unsigned char baselabelsimagex[]={3,25};

const unsigned char introwaves[]={32,33,35,36,38,39,41,42,44,45,47,48,49,51,52,53,54,55,56,57,58,59,60,60,61,62,62,63,63,63,63,63,64,63,63,63,63,63,62,62,61,60,60,59,58,57,56,55,54,53,52,51,49,48,47,45,44,42,41,39,38,36,35,33,32,30,28,27,25,24,22,21,19,18,16,15,14,12,11,10,9,8,7,6,5,4,3,3,2,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,2,3,3,4,5,6,7,8,9,10,11,12,14,15,16,18,19,21,22,24,25,27,28,30};
const unsigned char introastro[]={8,9,9,10,10,10,9,9,8,7,7,6,6,6,7,7};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Tiles definition
const unsigned char stage3tiletypesa[]=
{
	TILE_EMPTY,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_EMPTY,TILE_EMPTY,TILE_DEAD,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_DEAD,TILE_DEAD,
	TILE_EMPTY,TILE_EMPTY
};

// Tiles definition
const unsigned char stage1tiletypesa[]=
{
	TILE_EMPTY,TILE_DEAD,TILE_DEAD,TILE_DEAD,TILE_LEFT,TILE_RIGHT,TILE_UP,TILE_DOWN,
	TILE_LEFT,TILE_LEFT,TILE_RIGHT,TILE_RIGHT,TILE_UP,TILE_UP,TILE_DOWN,TILE_DOWN,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_EMPTY,TILE_EMPTY,
	TILE_EMPTY,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_EMPTY,TILE_EMPTY,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_EMPTY,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_DEAD,TILE_DEAD,TILE_DEAD,
	TILE_DEAD,TILE_DEAD,TILE_DEAD,TILE_SOLID
};

// Tiles definition
const unsigned char stage3tiletypesb[]=
{
	TILE_EMPTY,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_SOLID,TILE_EXIT,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_EMPTY,TILE_EMPTY,TILE_DEAD,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_DEAD,TILE_DEAD,
	TILE_EMPTY,TILE_EMPTY
};

// Tiles definition
const unsigned char stage1tiletypesb[]=
{
	TILE_EMPTY,TILE_DEAD,TILE_DEAD,TILE_DEAD,TILE_LEFT,TILE_RIGHT,TILE_UP,TILE_DOWN,
	TILE_LEFT,TILE_LEFT,TILE_RIGHT,TILE_RIGHT,TILE_UP,TILE_UP,TILE_DOWN,TILE_DOWN,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,
	TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_EMPTY,TILE_EMPTY,
	TILE_EMPTY,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_EXIT,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_EMPTY,TILE_EMPTY,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_EMPTY,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_FLOOR,TILE_SOLID,TILE_SOLID,TILE_SOLID,
	TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_SOLID,TILE_DEAD,TILE_DEAD,TILE_DEAD,
	TILE_DEAD,TILE_DEAD,TILE_DEAD,TILE_SOLID
};


// Para todos los bichos
extern void damageenemy(enemy *en);

// Soldier up-down
extern unsigned char updatesoldierupdown(enemy *en);
const enemydef ENEMY_SOLDIERUPDOWN={2,1,1,1,1,16,24,0,updatesoldierupdown,0,damageenemy,0};
#define ENEMY_SOLDIERUPDOWN_NUMSPRITES 48

// Rolling robot
extern unsigned char updaterollingrobot(enemy *en);
const enemydef ENEMY_ROLLINGROBOT={8,1,1,1,1,32,32,0,updaterollingrobot,0,damageenemy,0};
#define ENEMY_ROLLINGROBOT_NUMSPRITES 32

// Walking robot
extern unsigned char updatewalkingrobot(enemy *en);
const enemydef ENEMY_WALKROBOT={10,1,1,1,1,32,32,0,updatewalkingrobot,0,damageenemy,0};
#define ENEMY_WALKROBOT_NUMSPRITES 48

// Walking robot B
extern unsigned char updatewalkingrobotb(enemy *en);
const enemydef ENEMY_WALKROBOTB={10,1,1,1,1,24,32,0,updatewalkingrobotb,0,damageenemy,0};
#define ENEMY_WALKROBOTB_NUMSPRITES 32

// Flying boss
const unsigned char flyingbossz[]={16,28,32,35,37,39,40,39,37,35,32,28,24,19,16,12,10,8,8,8,10,12,16,19};
const signed char flyingbossmultipleshootx[]={-4,-2,2,4};
const signed char flyingbossmultipleshooty[]={2,4,4,2};

extern unsigned char updateflyingboss(enemy *en);
extern void enableexit(enemy *en);
const enemydef ENEMY_FLYINGBOSS={20,1,1,0,0,32,32,16,updateflyingboss,0,damageenemy,enableexit};
#define ENEMY_FLYINGBOSS_NUMSPRITES 16

// Flying boss B
extern unsigned char updateflyingbossb(enemy *en);
const enemydef ENEMY_FLYINGBOSSB={12,1,1,0,0,32,32,16,updateflyingbossb,0,damageenemy,enableexit};
#define ENEMY_FLYINGBOSSB_NUMSPRITES 16

// VAULT
extern unsigned char updatevault(enemy *en);
extern void damagevault(enemy *en);
const enemydef ENEMY_VAULT={10,1,0,1,1,16,16,0,updatevault,0,damagevault,0};
#define ENEMY_VAULT_NUMSPRITES 8

// BIG BLOB
extern unsigned char updatebigblob(enemy *en);
extern void enableexitbigboss(enemy *en);
const enemydef ENEMY_BIGBLOB={24,1,1,1,1,32,32,0,updatebigblob,0,damageenemy,enableexitbigboss};
#define ENEMY_BIGBLOB_NUMSPRITES 80

// GUSAN
extern void initgusan(enemy *en);
extern unsigned char updategusana(enemy *en);
extern unsigned char updategusanb(enemy *en);
extern unsigned char updategusanc(enemy *en);
extern void killgusan(enemy *en);
const enemydef ENEMY_GUSANA={16,1,1,0,0,16,16,initgusan,updategusana,0,damageenemy,killgusan};
#define ENEMY_GUSANA_NUMSPRITES 16
const enemydef ENEMY_GUSANB={255,1,1,0,0,16,16,initgusan,updategusanb,0,0,0};
#define ENEMY_GUSANB_NUMSPRITES 16
const enemydef ENEMY_GUSANC={255,1,1,0,0,16,16,initgusan,updategusanc,0,0,0};
#define ENEMY_GUSANC_NUMSPRITES 16

// BIG DOUBLE
extern unsigned char updatebigdoublea(enemy *en);
extern unsigned char updatebigdoubleb(enemy *en);
extern void killbigdouble(enemy *en);
const enemydef ENEMY_BIGDOUBLEA={24,1,1,1,1,24,32,0,updatebigdoublea,0,damageenemy,killbigdouble};
#define ENEMY_BIGDOUBLEA_NUMSPRITES 96
const enemydef ENEMY_BIGDOUBLEB={24,1,1,1,1,24,32,0,updatebigdoubleb,0,damageenemy,killbigdouble};
#define ENEMY_BIGDOUBLEB_NUMSPRITES 96

// BIG BOSS
extern unsigned char updatebigboss(enemy *en);
extern void enableexitbigboss(enemy *en);
const enemydef ENEMY_BIGBOSS={48,1,1,0,0,48,48,0,updatebigboss,0,damageenemy,enableexitbigboss};
#define ENEMY_BIGBOSS_NUMSPRITES 108

// Horiz block
extern unsigned char updatehorizblock(enemy *en);
const enemydef ENEMY_HORIZBLOCK={255,1,1,0,0,16,16,0,updatehorizblock,0,0,0};
#define ENEMY_HORIZBLOCK_NUMSPRITES 4

// Vert block
extern unsigned char updatevertblock(enemy *en);
const enemydef ENEMY_VERTBLOCK={255,1,1,0,0,16,16,0,updatevertblock,0,0,0};
#define ENEMY_VERTBLOCK_NUMSPRITES 4

// Laser
extern void initlaser(enemy *en);
const enemydef ENEMY_LASER={0,0,1,0,0,8,48,initlaser,0,0,0,0};
#define ENEMY_LASER_NUMSPRITES 6

// Homing
extern void inithoming(enemy *en);
extern unsigned char updatehoming(enemy *en);
const enemydef ENEMY_HOMING={2,1,1,0,0,16,16,inithoming,updatehoming,0,damageenemy,0};
#define ENEMY_HOMING_NUMSPRITES 16

// Blob
extern unsigned char updateblob(enemy *en);
const enemydef ENEMY_BLOB={2,1,1,1,1,16,16,0,updateblob,0,damageenemy,0};
#define ENEMY_BLOB_NUMSPRITES 12

extern unsigned char updateblobb(enemy *en);
const enemydef ENEMY_BLOBB={3,1,1,1,1,16,16,0,updateblobb,0,damageenemy,0};
#define ENEMY_BLOBB_NUMSPRITES 12

extern unsigned char updateblobc(enemy *en);
const enemydef ENEMY_BLOBC={4,1,1,1,1,16,16,0,updateblobc,0,damageenemy,0};
#define ENEMY_BLOBC_NUMSPRITES 12

extern unsigned char updatemissile(enemy *en);
const enemydef ENEMY_MISSILE={128,1,1,1,1,16,16,0,updatemissile,0,0,0};
#define ENEMY_MISSILE_NUMSPRITES 16

// Need change
extern void collideneedchange(enemy *en);
extern void initneedchange(enemy *en);
const enemydef ENEMY_NEEDCHANGE={0,0,1,0,0,32,48,initneedchange,0,collideneedchange,0,0};
#define ENEMY_NEEDCHANGE_NUMSPRITES 0

// Change
extern void collidechange(enemy *en);
extern unsigned char updatechange(enemy *en);
const enemydef ENEMY_CHANGE={0,0,1,0,0,16,16,0,updatechange,collidechange,0,0};
#define ENEMY_CHANGE_NUMSPRITES 4

// Skull
extern unsigned char updateskull(enemy *en);
const enemydef ENEMY_SKULL={3,1,1,0,0,16,24,0,updateskull,0,damageenemy,0};
#define ENEMY_SKULL_NUMSPRITES 12

// My Master
extern unsigned char updatemymaster(enemy *en);
extern void collidemymaster(enemy *en);
const enemydef ENEMY_MYMASTER={3,1,1,0,0,32,40,0,updatemymaster,collidemymaster,0,0};
#define ENEMY_MYMASTER_NUMSPRITES 80

// Machine
extern unsigned char updatemachine(enemy *en);
extern void collidemachine(enemy *en);
const enemydef ENEMY_MACHINE={3,1,1,0,0,16,32,0,updatemachine,collidemachine,0,0};
#define ENEMY_MACHINE_NUMSPRITES 16

// Pivots
extern unsigned char updatemediumpivot(enemy *en);
extern unsigned char updatefarpivot(enemy *en);
extern void initpivot(enemy *en);
const enemydef ENEMY_CENTERPIVOT={255,1,1,0,0,16,16,0,0,0,0,0};
const enemydef ENEMY_MEDIUMPIVOT={255,1,1,0,0,8,8,initpivot,updatemediumpivot,0,0,0};
const enemydef ENEMY_FARPIVOT={255,1,1,0,0,16,16,initpivot,updatefarpivot,0,0,0};
#define ENEMY_CENTERPIVOT_NUMSPRITES 4
#define ENEMY_MEDIUMPIVOT_NUMSPRITES 1
#define ENEMY_FARPIVOT_NUMSPRITES 4

const signed char farpivotx[]={40,39,39,38,36,35,33,30,28,25,22,18,15,11,7,3,0,-4,-8,-12,-16,-19,-23,-26,-29,-31,-34,-36,-37,-39,-40,-40,-40,-40,-40,-39,-37,-36,-34,-31,-29,-26,-23,-19,-16,-12,-8,-4,-1,3,7,11,15,18,22,25,28,30,33,35,36,38,39,39};
const signed char farpivoty[]={0,3,7,11,15,18,22,25,28,30,33,35,36,38,39,39,40,39,39,38,36,35,33,30,28,25,22,18,15,11,7,3,0,-4,-8,-12,-16,-19,-23,-26,-29,-31,-34,-36,-37,-39,-40,-40,-40,-40,-40,-39,-37,-36,-34,-31,-29,-26,-23,-19,-16,-12,-8,-4};

////////////////////////////////////////////////////////////////////////////// Stage 0
#define stage3numenemies 30
const enemyslot stage3enemies[]=
{
	{8*16,78*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{6*16,77*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{10*16,77*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},

	{7*16,73*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{9*16,73*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},	
	
	
	{6*16,68*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},	
	{10*16,68*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{8*16,67*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	
	{8*16,45*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
		
	{6*16,49*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{10*16,49*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},

	{6*16,44*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{10*16,44*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},

	{5*16,47*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{11*16,47*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	
	{5*16,25*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	{11*16,23*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},

	{6*16,27*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{8*16,28*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{10*16,27*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
			
	{8*16,25*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	
	{8*16,20*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	
	
	{-8+7*16,18*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{8+9*16,18*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},

	{8*16,16*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
		
	{8*16,14*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	
	{-8+7*16,12*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	{8+9*16,12*16,0,&ENEMY_SOLDIERUPDOWN,0,{0,0,0,0}},
	
	{6*16,8+62*16,0,&ENEMY_HORIZBLOCK,1,{3*16,13*16,60*16,63*16}},

	{8*16,6*16,0,&ENEMY_FLYINGBOSS,0,{0,0,0,0}},
};
#define stage3numenemysprites 8
const enemyspritebase stage3enemysprites[]=
{
	{&ENEMY_SOLDIERUPDOWN,ENEMYBASE,soldierdown_zx7,soldierdown_zx7_bank},
	{&ENEMY_ROLLINGROBOT,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES,rollingrobot0_zx7,rollingrobot0_zx7_bank},
	{&ENEMY_FLYINGBOSS,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES,flyingrobot_zx7,flyingrobot_zx7_bank},
	{&ENEMY_LASER,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES,laser_zx7,laser_zx7_bank},
	{&ENEMY_HORIZBLOCK,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_LASER_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_VERTBLOCK,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_LASER_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_BLOB,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES,blob_zx7,blob_zx7_bank},
	{&ENEMY_CHANGE,ENEMYBASE+ENEMY_SOLDIERUPDOWN_NUMSPRITES+ENEMY_ROLLINGROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_BLOB_NUMSPRITES,change6_zx7,change6_zx7_bank},
};
#define stage3numplatforms 2
const platformdef stage3platforms[]=
{
	{5*16,36*16,35*16,43*16,1},
	{8+(9*16),40*16,35*16,43*16,1}
};

////////////////////////////////////////////////////////////////////////////// Stage 1
#define stage1numenemies 2
const enemyslot stage1enemies[]=
{
	{8*16,-2+8*16,0,&ENEMY_CHANGE,0,{0,0,0,0}},
	{8*16,26*16,0,&ENEMY_NEEDCHANGE,0,{0,0,0,0}},
};
#define stage1numenemysprites 2
const enemyspritebase stage1enemysprites[]=
{
	{&ENEMY_NEEDCHANGE,ENEMYBASE,0,0},
	{&ENEMY_CHANGE,ENEMYBASE,change6_zx7,change6_zx7_bank},
};

////////////////////////////////////////////////////////////////////////////// Stage 2
#define stage9numenemies 19
const enemyslot stage9enemies[]=
{
	{4*16,20*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{7*16,22*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{12*16,21*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{19*16,20*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{25*16,25*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{19*16,25*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{33*16,24*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{32*16,20*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{8+36*16,4*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},	
	{30*16,7*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{26*16,4*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{21*16,9*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{10*16,9*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{4*16,5*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{19*16,24*16,0,&ENEMY_BLOB,0,{0,0,0,0}},	
	{6*16,4*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},	
	{8+14*16,4*16,0,&ENEMY_VERTBLOCK,1,{13*16,16*16,3*16,11*16}},	
	{8+19*16,4*16,0,&ENEMY_VERTBLOCK,1,{18*16,21*16,3*16,11*16}},	
	{8+24*16,4*16,0,&ENEMY_VERTBLOCK,1,{23*16,26*16,3*16,11*16}},	
};
#define stage9numplatforms 1
const platformdef stage9platforms[]=
{
	{8+(32*16),14*16,12*16,18*16,1},
};

////////////////////////////////////////////////////////////////////////////// Stage 3
#define stage6numenemies 14
const enemyslot stage6enemies[]=
{
	{5*16,40*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{9*16,41*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	
	{8*16,25*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},

	{8*16,24*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{11*16,26*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	
	{8*16,28*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{11*16,31*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
		
	{6*16,8+19*16,0,&ENEMY_HORIZBLOCK,1,{4*16,12*16,14*16,17*17}},
	{10*16,8+15*16,0,&ENEMY_HORIZBLOCK,1,{4*16,13*16,18*16,20*16}},
	
	{8*16,6*16,0,&ENEMY_FLYINGBOSS,0,{0,0,0,0}},
	
	{3*16,6*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{6*16,8*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{8*16,10*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{12*16,7*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
};

////////////////////////////////////////////////////////////////////////////// Stage 4
#define stage8numenemies 19
const enemyslot stage8enemies[]=
{
	{29*16,-2+19*16,0,&ENEMY_CHANGE,0,{0,0,0,0}},
	{30*16,4*16,0,&ENEMY_VERTBLOCK,1,{29*16,31*16,3*16,10*16}},
	{25*16,6*16,0,&ENEMY_VERTBLOCK,1,{24*16,27*16,3*16,10*16}},	
	{21*16,6*16,0,&ENEMY_VERTBLOCK,1,{20*16,23*16,3*16,10*16}},
	{28*16,28*16,0,&ENEMY_VERTBLOCK,1,{27*16,30*16,27*16,34*16}},
	{19*16,30*16,0,&ENEMY_VERTBLOCK,1,{18*16,21*16,27*16,34*16}},
	{7*16,4*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	{12*16,22*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	{36*16,14*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{16*16,5*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{38*16,29*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{33*16,30*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{12*16,29*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{36*16,27*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{7*16,30*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{9*16,24*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{11*16,5*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{38*16,6*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
	{35*16,8*16,0,&ENEMY_BLOB,0,{0,0,0,0}},
};
#define stage8numplatforms 5
const platformdef stage8platforms[]=
{
	{8+(21*16),27*16,27*16,34*16,1},
	{(24*16),31*16,27*16,34*16,1},
	{12+(9*16),14*16,11*16,19*16,1},
	{12+(17*16),5*16,3*16,10*16,1},
	{12+(26*16),8*16,3*16,10*16,1},
};

////////////////////////////////////////////////////////////////////////////// Stage 5 - MONSTER
#define stage10numenemies 1
const enemyslot stage10enemies[]=
{
	{8*16,6*16,0,&ENEMY_BIGBLOB,0,{0,0,0,0}},
};
#define stage10numenemysprites 1
const enemyspritebase stage10enemysprites[]=
{
	{&ENEMY_BIGBLOB,ENEMYBASE,bigblob_zx7,bigblob_zx7_bank}
};

////////////////////////////////////////////////////////////////////////////// Stage 6
#define stage14numenemies 22
const enemyslot stage14enemies[]=
{
	{8*16,6*16,0,&ENEMY_FLYINGBOSS,0,{0,0,0,0}},
	
	{4*16,74*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{11*16,69*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{4*16,71*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{8*16,70*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{6*16,61*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{3*16,63*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{13*16,23*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{11*16,28*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{5*16,30*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{6*16,41*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{3*16,53*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{6*16,11*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{12*16,13*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{4*16,10*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{12*16,7*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{11*16,19*16,0,&ENEMY_WALKROBOT,0,{9*16,15*16,18*16,20*16}},
	{5*16,50*16,0,&ENEMY_WALKROBOT,0,{2*16,8*16,49*16,51*16}},
	{5*16,38*16,0,&ENEMY_WALKROBOT,0,{2*16,8*16,37*16,39*16}},
	
	{3*16,41*16,0,&ENEMY_HORIZBLOCK,1,{2*16,8*16,40*16,42*16}},
	{8+8*16,28*16,0,&ENEMY_VERTBLOCK,1,{7*16,9*16,27*16,32*16}},
	{5*16,65*16,0,&ENEMY_HORIZBLOCK,1,{2*16,8*16,64*16,66*16}},
};
#define stage14numenemysprites 11
const enemyspritebase stage14enemysprites[]=
{
	{&ENEMY_WALKROBOT,ENEMYBASE,bigrobot2_zx7,bigrobot2_zx7_bank},
	{&ENEMY_BLOBB,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES,blobb_zx7,blobb_zx7_bank},
	{&ENEMY_FLYINGBOSS,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,flyingrobot_zx7,flyingrobot_zx7_bank},
	{&ENEMY_LASER,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,laser_zx7,laser_zx7_bank},
	{&ENEMY_SKULL,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES,skull_zx7,skull_zx7_bank},
	{&ENEMY_HORIZBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_VERTBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_CHANGE,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES,change6_zx7,change6_zx7_bank},
	{&ENEMY_CENTERPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES,basepinch_zx7,basepinch_zx7_bank},
	{&ENEMY_MEDIUMPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES+ENEMY_CENTERPIVOT_NUMSPRITES,littlepinch_zx7,littlepinch_zx7_bank},
	{&ENEMY_FARPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
};

////////////////////////////////////////////////////////////////////////////// Stage 7
#define stage15numenemies 26
const enemyslot stage15enemies[]=
{
	{13*16,14*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{7*16,13*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{11*16,15*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{3*16,4*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{13*16,6*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{9*16,5*16,0,&ENEMY_WALKROBOT,0,{6*16,11*16,4*16,6*16}},
	
	{20*16,4*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{33*16,6*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{23*16,4*16,0,&ENEMY_VERTBLOCK,1,{22*16,24*16,3*16,9*16}},
	{29*16,6*16,0,&ENEMY_VERTBLOCK,1,{28*16,30*16,3*16,9*16}},
	{36*16,8*16,0,&ENEMY_VERTBLOCK,1,{35*16,37*16,3*16,9*16}},
	{8+42*16,4*16,0,&ENEMY_VERTBLOCK,1,{41*16,43*16,3*16,9*16}},
	{-8+47*16,4*16,0,&ENEMY_VERTBLOCK,1,{46*16,48*16,3*16,9*16}},
	
	{58*16,4*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{53*16,8*16,0,&ENEMY_SKULL,0,{0,0,0,0}},	
	{55*16,5*16,0,&ENEMY_SKULL,0,{0,0,0,0}},	
	{52*16,15*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{57*16,20*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{53*16,21*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{24*16,18*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{24*16,21*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{49*16,20*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{47*16,18*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{45*16,18*16,0,&ENEMY_VERTBLOCK,1,{44*16,46*16,17*16,23*16}},
	
	{41*16,20*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{35*16,19*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
};
#define stage15numplatforms 4
const platformdef stage15platforms[]=
{
	{38*16,19*16,17*16,23*16,1},
	{12+(38*16),3*16,3*16,9*16,1},
	{48*16,4*16,48*16,61*16,0},
	{52*16,6*16,52*16,61*16,0},
};

////////////////////////////////////////////////////////////////////////////// Stage 8
#define stage16numenemies 24
const enemyslot stage16enemies[]=
{
	{4*16,39*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{9*16,40*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{27*16,44*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{25*16,44*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{26*16,31*16,0,&ENEMY_WALKROBOT,0,{23*16,31*16,29*16,31*16}},
	{25*16,33*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{22*16,21*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{27*16,22*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{24*16,26*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{9*16,26*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{6*16,21*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{8*16,14*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{11*16,17*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{10*16,14*16,0,&ENEMY_WALKROBOT,0,{7*16,13*16,12*16,14*16}},
	
	{7*16,5*16,0,&ENEMY_FLYINGBOSS,0,{0,0,0,0}},
	
	{26*16,-2+10*16,0,&ENEMY_CHANGE,0,{0,0,0,0}},
	
	{16*16,42*16,0,&ENEMY_CENTERPIVOT,1,{16*16-48,16*16+48,42*16-48,42*16+48}},
	{16*16,42*16,0,&ENEMY_MEDIUMPIVOT,1,{16*16-48,16*16+48,42*16-48,42*16+48}},
	{16*16,42*16,0,&ENEMY_FARPIVOT,1,{16*16-48,16*16+48,42*16-48,42*16+48}},

	{18*16,24*16,0,&ENEMY_CENTERPIVOT,1,{18*16-48,18*16+48,24*16-48,24*16+48}},
	{18*16,24*16,0,&ENEMY_MEDIUMPIVOT,1,{18*16-48,18*16+48,24*16-48,24*16+48}},
	{18*16,24*16,0,&ENEMY_FARPIVOT,1,{18*16-48,18*16+48,24*16-48,24*16+48}},
	
};
#define stage13numplatforms 5
const platformdef stage13platforms[]=
{
	{15*16,21*16,15*16,21*16,0},
	{18*16,26*16,15*16,21*16,0},
	{13*16,39*16,13*16,19*16,0},
	{16*16,44*16,13*16,19*16,0},
	{23*16,14*16,23*16,29*16,0},
};

////////////////////////////////////////////////////////////////////////////// Stage 9 - MONSTER
#define stage11numenemies 2
const enemyslot stage11enemies[]=
{
	{3*16,5*16,0,&ENEMY_BIGDOUBLEA,0,{0,0,0,0}},
	{13*16,5*16,0,&ENEMY_BIGDOUBLEB,0,{0,0,0,0}},
};
#define stage11numenemysprites 2
const enemyspritebase stage11enemysprites[]=
{
	{&ENEMY_BIGDOUBLEA,ENEMYBASE,bigdouble_zx7,bigdouble_zx7_bank},
	{&ENEMY_BIGDOUBLEB,ENEMYBASE,bigdouble_zx7,bigdouble_zx7_bank}
};

////////////////////////////////////////////////////////////////////////////// Stage 10
#define stage18numenemies 21
const enemyslot stage18enemies[]=
{
	{20*16,8+12*16,0,&ENEMY_HORIZBLOCK,1,{19*16,25*16,11*16,13*16}},
	{23*16,8+15*16,0,&ENEMY_HORIZBLOCK,1,{19*16,25*16,14*16,16*16}},
	{36*16,8+4*16,0,&ENEMY_HORIZBLOCK,1,{35*16,43*16,3*16,5*16}},	
	{6*16,8+16*16,0,&ENEMY_HORIZBLOCK,1,{1*16,9*16,15*16,17*16}},	

	{42*16,4+21*16,0,&ENEMY_CENTERPIVOT,1,{42*16-48,42*16+48,21*16-48,21*16+48}},
	{42*16,4+21*16,0,&ENEMY_MEDIUMPIVOT,1,{42*16-48,42*16+48,21*16-48,21*16+48}},
	{42*16,4+21*16,0,&ENEMY_FARPIVOT,1,{42*16-48,42*16+48,21*16-48,21*16+48}},

	{22*16,4+6*16,0,&ENEMY_CENTERPIVOT,1,{22*16-48,22*16+48,6*16-48,6*16+48}},
	{22*16,4+6*16,0,&ENEMY_MEDIUMPIVOT,1,{22*16-48,22*16+48,6*16-48,6*16+48}},
	{22*16,4+6*16,0,&ENEMY_FARPIVOT,1,{22*16-48,22*16+48,6*16-48,6*16+48}},

	{30*16,4+22*16,0,&ENEMY_CENTERPIVOT,1,{30*16-48,30*16+48,22*16-48,22*16+48}},
	{30*16,4+22*16,0,&ENEMY_MEDIUMPIVOT,1,{30*16-48,30*16+48,22*16-48,22*16+48}},
	{30*16,4+22*16,0,&ENEMY_FARPIVOT,1,{30*16-48,30*16+48,22*16-48,22*16+48}},
	
	{24*16,9*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	
	{18*16,20*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{16*16,24*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	
	{3*16,10*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	
	{7*16,11*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{14*16,4*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{32*16,25*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	{38*16,13*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
};
#define stage10numplatforms 3
const platformdef stage10platforms[]=
{
	{4+(35*16),19*16,19*16,26*16,1},
	{35*16,9*16,35*16,43*16,0},
	{37*16,7*16,35*16,43*16,0},
};

////////////////////////////////////////////////////////////////////////////// Stage 11
#define stage17numenemies 23
const enemyslot stage17enemies[]=
{
	{19*16,-2+7*16,0,&ENEMY_CHANGE,0,{0,0,0,0}},
	
	{35*16,30*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	
	{26*16,4+33*16,0,&ENEMY_CENTERPIVOT,1,{26*16-48,26*16+48,33*16-48,33*16+48}},
	{26*16,4+33*16,0,&ENEMY_MEDIUMPIVOT,1,{26*16-48,26*16+48,33*16-48,33*16+48}},
	{26*16,4+33*16,0,&ENEMY_FARPIVOT,1,{26*16-48,26*16+48,33*16-48,33*16+48}},

	{6*16,4+30*16,0,&ENEMY_CENTERPIVOT,1,{6*16-48,6*16+48,30*16-48,30*16+48}},
	{6*16,4+30*16,0,&ENEMY_MEDIUMPIVOT,1,{6*16-48,6*16+48,30*16-48,30*16+48}},
	{6*16,4+30*16,0,&ENEMY_FARPIVOT,1,{6*16-48,6*16+48,30*16-48,30*16+48}},

	{5*16,13*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	
	{19*16,9*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},

	{40*16,4+13*16,0,&ENEMY_CENTERPIVOT,1,{40*16-48,40*16+48,13*16-48,13*16+48}},
	{40*16,4+13*16,0,&ENEMY_MEDIUMPIVOT,1,{40*16-48,40*16+48,13*16-48,13*16+48}},
	{40*16,4+13*16,0,&ENEMY_FARPIVOT,1,{40*16-48,40*16+48,13*16-48,13*16+48}},
	
	{38*16,8+4*16,0,&ENEMY_HORIZBLOCK,1,{35*16,43*16,3*16,5*16}},	
	
	{19*16,32*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{5*16,24*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{13*16,30*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{10*16,28*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{10*16,33*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{2*16,15*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{17*16,14*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{28*16,14*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{32*16,16*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
};
#define stage17numenemysprites 12
const enemyspritebase stage17enemysprites[]=
{
	{&ENEMY_WALKROBOTB,ENEMYBASE,bigdouble_zx7,bigdouble_zx7_bank},
	{&ENEMY_BLOBB,ENEMYBASE+ENEMY_WALKROBOTB_NUMSPRITES,blobb_zx7,blobb_zx7_bank},
	{&ENEMY_FLYINGBOSSB,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,flyingrobot_zx7,flyingrobot_zx7_bank},
	{&ENEMY_LASER,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,laser_zx7,laser_zx7_bank},
	{&ENEMY_SKULL,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES,skull_zx7,skull_zx7_bank},
	{&ENEMY_HORIZBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_VERTBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_CHANGE,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES,change6_zx7,change6_zx7_bank},
	{&ENEMY_CENTERPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES,basepinch_zx7,basepinch_zx7_bank},
	{&ENEMY_MEDIUMPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES+ENEMY_CENTERPIVOT_NUMSPRITES,littlepinch_zx7,littlepinch_zx7_bank},
	{&ENEMY_FARPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_ROLLINGROBOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES+ENEMY_CENTERPIVOT_NUMSPRITES+ENEMY_MEDIUMPIVOT_NUMSPRITES,rollingrobot0_zx7,rollingrobot0_zx7_bank},
};
#define stage14numplatforms 3
const platformdef stage14platforms[]=
{
	{1*16,-4+(20*16),1*16,9*16,0},
	{35*16,-4+(7*16),35*16,43*16,0},	
	{6*16,-12+(34*16),5*16,9*16,0},	
};

////////////////////////////////////////////////////////////////////////////// Stage 12
#define stage19numenemies 19
const enemyslot stage19enemies[]=
{
	{6*16,4+19*16,0,&ENEMY_CENTERPIVOT,1,{6*16-48,6*16+48,19*16-48,19*16+48}},
	{6*16,4+19*16,0,&ENEMY_MEDIUMPIVOT,1,{6*16-48,6*16+48,19*16-48,19*16+48}},
	{6*16,4+19*16,0,&ENEMY_FARPIVOT,1,{6*16-48,6*16+48,19*16-48,19*16+48}},
	
	{8+7*16,12+9*16,0,&ENEMY_CENTERPIVOT,1,{7*16-48,7*16+48,9*16-48,9*16+48}},
	{8+7*16,12+9*16,0,&ENEMY_MEDIUMPIVOT,1,{7*16-48,7*16+48,9*16-48,9*16+48}},
	{8+7*16,12+9*16,0,&ENEMY_FARPIVOT,1,{7*16-48,7*16+48,9*16-48,9*16+48}},
	
	{15*16,38*16,0,&ENEMY_VERTBLOCK,1,{14*16,16*16,37*16,41*16}},	
	
	{13*16,20*16,0,&ENEMY_VERTBLOCK,1,{12*16,14*16,19*16,23*16}},	
	{23*16,20*16,0,&ENEMY_VERTBLOCK,1,{22*16,21*16,17*16,25*16}},	
	
	{23*16,29*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{26*16,33*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{27*16,18*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{17*16,24*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{17*16,18*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{26*16,33*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	
	{5*16,14*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	
	{24*16,9*16,0,&ENEMY_BLOBB,0,{0,0,0,0}},
	{27*16,4*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
	
	{3*16,38*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
};
#define stage6numplatforms 6
const platformdef stage6platforms[]=
{
	{4+(5*16),4+(3*16),5*16,15*16,0},
	{2*16,8+(22*16),2*16,12*16,0},
	{8+(10*16),37*16,37*16,43*16,1},
	{8+(17*16),42*16,37*16,43*16,1},
	{8+(24*16),34*16,34*16,43*16,1},
	{19*16,41*16,19*16,25*16,0},
};

////////////////////////////////////////////////////////////////////////////// Stage 13 - MONSTER
#define stage13numenemies 5
const enemyslot stage13enemies[]=
{
	
	{(6*16),(7*16),0,&ENEMY_GUSANA,0,{0,0,0,0}},
	{(6*16)+(GUSANVELX*5),(7*16)-(GUSANVELY*5),0,&ENEMY_GUSANB,0,{0,0,0,0}},
	{(6*16)+(GUSANVELX*10),(7*16)-(GUSANVELY*10),0,&ENEMY_GUSANB,0,{0,0,0,0}},
	{(6*16)+(GUSANVELX*15),(7*16)-(GUSANVELY*15),0,&ENEMY_GUSANB,0,{0,0,0,0}},
	{(6*16)+(GUSANVELX*20),(7*16)-(GUSANVELY*20),0,&ENEMY_GUSANC,0,{0,0,0,0}},
};
#define stage13numenemysprites 3
const enemyspritebase stage13enemysprites[]=
{
	{&ENEMY_GUSANA,ENEMYBASE,gusana_zx7,gusana_zx7_bank},
	{&ENEMY_GUSANB,ENEMYBASE+ENEMY_GUSANA_NUMSPRITES,gusanb_zx7,gusanb_zx7_bank},
	{&ENEMY_GUSANC,ENEMYBASE+ENEMY_GUSANA_NUMSPRITES+ENEMY_GUSANB_NUMSPRITES,gusanc_zx7,gusanc_zx7_bank}
};


////////////////////////////////////////////////////////////////////////////// Stage 14
#define stage2numenemies 18
const enemyslot stage2enemies[]=
{
	{36*16,4+14*16,0,&ENEMY_CENTERPIVOT,1,{36*16-48,36*16+48,14*16-48,14*16+48}},
	{36*16,4+14*16,0,&ENEMY_MEDIUMPIVOT,1,{36*16-48,36*16+48,14*16-48,14*16+48}},
	{36*16,4+14*16,0,&ENEMY_FARPIVOT,1,{36*16-48,   36*16+48,14*16-48,14*16+48}},
	
	{40*16,4+18*16,0,&ENEMY_CENTERPIVOT,1,{40*16-48,40*16+48,18*16-48,18*16+48}},
	{40*16,4+18*16,0,&ENEMY_MEDIUMPIVOT,1,{40*16-48,40*16+48,18*16-48,18*16+48}},
	{40*16,4+18*16,0,&ENEMY_FARPIVOT,1,{40*16-48,40*16+48,18*16-48,18*16+48}},
	
	{26*16,4*16,0,&ENEMY_VERTBLOCK,1,{25*16,27*16,3*16,9*16}},	
	{5*16,18*16,0,&ENEMY_HORIZBLOCK,1,{1*16,13*16,16*16,18*16}},	

	{2*16,13*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{11*16,13*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{6*16,4*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{19*16,7*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{19*16,4*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{24*16,8*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{35*16,10*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{40*16,10*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{36*16,19*16,0,&ENEMY_WALKROBOTB,0,{0,0,0,0}},
};
#define stage2numenemysprites 13
const enemyspritebase stage2enemysprites[]=
{
	{&ENEMY_WALKROBOTB,ENEMYBASE,bigdouble_zx7,bigdouble_zx7_bank},
	{&ENEMY_BLOBC,ENEMYBASE+ENEMY_WALKROBOTB_NUMSPRITES,blobc_zx7,blobc_zx7_bank},
	{&ENEMY_FLYINGBOSSB,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,flyingrobot_zx7,flyingrobot_zx7_bank},
	{&ENEMY_FLYINGBOSS,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,flyingrobot_zx7,flyingrobot_zx7_bank},
	{&ENEMY_LASER,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES,laser_zx7,laser_zx7_bank},
	{&ENEMY_SKULL,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES,skull_zx7,skull_zx7_bank},
	{&ENEMY_HORIZBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_VERTBLOCK,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_CHANGE,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES,change6_zx7,change6_zx7_bank},
	{&ENEMY_CENTERPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES,basepinch_zx7,basepinch_zx7_bank},
	{&ENEMY_MEDIUMPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES+ENEMY_CENTERPIVOT_NUMSPRITES,littlepinch_zx7,littlepinch_zx7_bank},
	{&ENEMY_FARPIVOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES,pinch_zx7,pinch_zx7_bank},
	{&ENEMY_ROLLINGROBOT,ENEMYBASE+ENEMY_WALKROBOT_NUMSPRITES+ENEMY_FLYINGBOSS_NUMSPRITES+ENEMY_BLOBB_NUMSPRITES+ENEMY_LASER_NUMSPRITES+ENEMY_SKULL_NUMSPRITES+ENEMY_HORIZBLOCK_NUMSPRITES+ENEMY_CHANGE_NUMSPRITES+ENEMY_CENTERPIVOT_NUMSPRITES+ENEMY_MEDIUMPIVOT_NUMSPRITES,rollingrobot0_zx7,rollingrobot0_zx7_bank},
};

////////////////////////////////////////////////////////////////////////////// Stage 15
#define stage4numenemies 18
const enemyslot stage4enemies[]=
{
	{3*16,10*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{8+6*16,7*16,0,&ENEMY_CENTERPIVOT,1,{6*16-48,6*16+48,7*16-48,7*16+48}},
	{8+6*16,7*16,0,&ENEMY_MEDIUMPIVOT,1,{6*16-48,6*16+48,7*16-48,7*16+48}},
	{8+6*16,7*16,0,&ENEMY_FARPIVOT,1,{6*16-48,   6*16+48,7*16-48,7*16+48}},
	
	{44*16,7*16,0,&ENEMY_FLYINGBOSSB,0,{0,0,0,0}},
	
	{75*16,8*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{69*16,10*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{71*16,4*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{65*16,6*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{37*16,3*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{35*16,6*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{37*16,9*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{18*16,3*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{18*16,9*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{22*16,6*16,0,&ENEMY_SKULL,0,{0,0,0,0}},

	{52*16,4*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{52*16,10*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{55*16,7*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
};

////////////////////////////////////////////////////////////////////////////// Stage 16
#define stage5numenemies 39
const enemyslot stage5enemies[]=
{
	{7*16,6*16,0,&ENEMY_FLYINGBOSS,0,{0,0,0,0}},
	
	{12*16,85*16,0,&ENEMY_CENTERPIVOT,1,{12*16-48,12*16+48,85*16-48,85*16+48}},
	{12*16,85*16,0,&ENEMY_MEDIUMPIVOT,1,{12*16-48,12*16+48,85*16-48,85*16+48}},
	{12*16,85*16,0,&ENEMY_FARPIVOT,1,   {12*16-48,12*16+48,85*16-48,85*16+48}},

	{4*16,81*16,0,&ENEMY_CENTERPIVOT,1,{4*16-48,4*16+48,81*16-48,81*16+48}},
	{4*16,81*16,0,&ENEMY_MEDIUMPIVOT,1,{4*16-48,4*16+48,81*16-48,81*16+48}},
	{4*16,81*16,0,&ENEMY_FARPIVOT,1,   {4*16-48,4*16+48,81*16-48,81*16+48}},
	
	{5*16,66*16,0,&ENEMY_CENTERPIVOT,1,{5*16-48,5*16+48,66*16-48,66*16+48}},
	{5*16,66*16,0,&ENEMY_MEDIUMPIVOT,1,{5*16-48,5*16+48,66*16-48,66*16+48}},
	{5*16,66*16,0,&ENEMY_FARPIVOT,1,   {5*16-48,5*16+48,66*16-48,66*16+48}},
	
	{11*16,66*16,0,&ENEMY_CENTERPIVOT,1,{11*16-48,11*16+48,66*16-48,66*16+48}},
	{11*16,66*16,0,&ENEMY_MEDIUMPIVOT,1,{11*16-48,11*16+48,66*16-48,66*16+48}},
	{11*16,66*16,0,&ENEMY_FARPIVOT,1,   {11*16-48,11*16+48,66*16-48,66*16+48}},

	{4*16,22*16,0,&ENEMY_CENTERPIVOT,1,{4*16-48,4*16+48,22*16-48,22*16+48}},
	{4*16,22*16,0,&ENEMY_MEDIUMPIVOT,1,{4*16-48,4*16+48,22*16-48,22*16+48}},
	{4*16,22*16,0,&ENEMY_FARPIVOT,1,   {4*16-48,4*16+48,22*16-48,22*16+48}},

	{11*16,27*16,0,&ENEMY_CENTERPIVOT,1,{11*16-48,11*16+48,27*16-48,27*16+48}},
	{11*16,27*16,0,&ENEMY_MEDIUMPIVOT,1,{11*16-48,11*16+48,27*16-48,27*16+48}},
	{11*16,27*16,0,&ENEMY_FARPIVOT,1,   {11*16-48,11*16+48,27*16-48,27*16+48}},
	
	{4*16,107*16,0,&ENEMY_HORIZBLOCK,1,{1*16,15*16,106*16,108*16}},	
	
	{10*16,80*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{6*16,86*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{12*16,92*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{8*16,92*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{4*16,92*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{8*16,58*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{4*16,58*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{12*16,58*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{3*16,36*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{12*16,39*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{9*16,33*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	
	{6*16,46*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{12*16,52*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{10*16,23*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{3*16,18*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{3*16,7*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{12*16,7*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{3*16,100*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
	{12*16,100*16,0,&ENEMY_SKULL,0,{0,0,0,0}},
};
#define stage5numplatforms 5
const platformdef stage5platforms[]=
{
	{(3*16),4+(74*16),1*16,15*16,0},
	{(13*16),4+(42*16),1*16,15*16,0},
	{(8*16),4+(39*16),1*16,15*16,0},
	{(5*16),4+(36*16),1*16,15*16,0},
	{(3*16),4+(33*16),1*16,15*16,0},
};


////////////////////////////////////////////////////////////////////////////// Stage 17
#define stage7numenemies 23
const enemyslot stage7enemies[]=
{
	{6*16,25*16,0,&ENEMY_CENTERPIVOT,1,{6*16-48,6*16+48,25*16-48,25*16+48}},
	{6*16,25*16,0,&ENEMY_MEDIUMPIVOT,1,{6*16-48,6*16+48,25*16-48,25*16+48}},
	{6*16,25*16,0,&ENEMY_FARPIVOT,1,   {6*16-48,6*16+48,25*16-48,25*16+48}},

	{10*16,22*16,0,&ENEMY_CENTERPIVOT,1,{10*16-48,10*16+48,22*16-48,22*16+48}},
	{10*16,22*16,0,&ENEMY_MEDIUMPIVOT,1,{10*16-48,10*16+48,22*16-48,22*16+48}},
	{10*16,22*16,0,&ENEMY_FARPIVOT,1,   {10*16-48,10*16+48,22*16-48,22*16+48}},
	
	{34*16,8*16,0,&ENEMY_CENTERPIVOT,1,{34*16-48,34*16+48,8*16-48,8*16+48}},
	{34*16,8*16,0,&ENEMY_MEDIUMPIVOT,1,{34*16-48,34*16+48,8*16-48,8*16+48}},
	{34*16,8*16,0,&ENEMY_FARPIVOT,1,   {34*16-48,34*16+48,8*16-48,8*16+48}},
	
	{16*16,4*16,0,&ENEMY_VERTBLOCK,1,{15*16,17*16,3*16,8*16}},	
	{20*16,8*16,0,&ENEMY_VERTBLOCK,1,{19*16,21*16,5*16,10*16}},	
	{24*16,10*16,0,&ENEMY_VERTBLOCK,1,{23*16,25*16,7*16,12*16}},	
	
	{28*16,4*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{28*16,7*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{28*16,10*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{10*16,5*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	{38*16,22*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	{34*16,23*16,0,&ENEMY_ROLLINGROBOT,0,{0,0,0,0}},
	
	{8*16,7*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{10*16,8*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{14*16,22*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	{14*16,25*16,0,&ENEMY_BLOBC,0,{0,0,0,0}},
	
	{3*16,-2+7*16,0,&ENEMY_CHANGE,0,{0,0,0,0}},
	
};
#define stage7numplatforms 1
const platformdef stage7platforms[]=
{
	{32*16,10*16,29*16,38*16,0},
};

////////////////////////////////////////////////////////////////////////////// The lift!
#define stage33numenemies 1
const enemyslot stage33enemies[]=
{
	{8*16,7*16,0,&ENEMY_VAULT,0,{0,0,0,0}},
};
#define stage33numenemysprites 2
const enemyspritebase stage33enemysprites[]=
{
	{&ENEMY_VAULT,ENEMYBASE,vault_zx7,vault_zx7_bank},
	{&ENEMY_MISSILE,ENEMYBASE+ENEMY_VAULT_NUMSPRITES,missile_zx7,missile_zx7_bank}
};

////////////////////////////////////////////////////////////////////////////// The machine!
#define stage44numenemies 1
const enemyslot stage44enemies[]=
{
	{8*16,12+8*16,0,&ENEMY_MACHINE,0,{0,0,0,0}},
};
#define stage44numenemysprites 1
const enemyspritebase stage44enemysprites[]=
{
	{&ENEMY_MACHINE,ENEMYBASE,machine_zx7,machine_zx7_bank},
};

////////////////////////////////////////////////////////////////////////////// Stage 18 - MONSTER
#define stage12numenemies 1
const enemyslot stage12enemies[]=
{
	{8*16,6*16,0,&ENEMY_BIGBOSS,0,{0,0,0,0}},
};
#define stage12numenemysprites 3
const enemyspritebase stage12enemysprites[]=
{
	{&ENEMY_BIGBOSS,ENEMYBASE,bigboss_zx7,bigboss_zx7_bank},
	{&ENEMY_LASER,ENEMYBASE+ENEMY_BIGBOSS_NUMSPRITES,laser_zx7,laser_zx7_bank},
	{&ENEMY_HOMING,ENEMYBASE+ENEMY_BIGBOSS_NUMSPRITES+ENEMY_LASER_NUMSPRITES,gusanb_zx7,gusanb_zx7_bank},
};

////////////////////////////////////////////////////////////////////////////// Stage 19
#define stage23numenemies 1
const enemyslot stage23enemies[]=
{
	{8*16,-3+9*16,0,&ENEMY_MYMASTER,0,{0,0,0,0}},
};
#define stage23numenemysprites 1
const enemyspritebase stage23enemysprites[]=
{
	{&ENEMY_MYMASTER,ENEMYBASE,mymaster_zx7,mymaster_zx7_bank}
};
 
//////////////////////////////////////////////////////////////////////////////

// Stage palettes
const unsigned char stage3palette_bin[]={0x00,0x3F,0x11,0x3b,0x20,0x2a,0x15,0x00,0x03,0x0f,0x00,0x00,0x00,0x00,0x00}; // Out
const unsigned char stage1palette_bin[]={0x00,0x3F,0x23,0x11,0x30,0x20,0x35,0x18,0x04,0x0F,0x2B,0x07,0x1D,0x2A,0x15,0x3B}; // In 1 greeen
const unsigned char stage4palette_bin[]={0x00,0x3F,0x23,0x11,0x30,0x20,0x35,0x22,0x03,0x0F,0x2B,0x07,0x2a,0x2A,0x15,0x3B}; // In 1 pink
const unsigned char stage2palette_bin[]={0x00,0x3F,0x23,0x11,0x30,0x20,0x35,0x12,0x04,0x0F,0x2B,0x07,0x17,0x2A,0x15,0x3B}; // In 1 blue OK
const unsigned char stage5palette_bin[]={0x00,0x3F,0x23,0x11,0x30,0x20,0x35,0x25,0x03,0x0F,0x2B,0x07,0x3a,0x2A,0x15,0x3B}; // In 1 cream GOOD

// Lumen animation
const unsigned char lumenanimation[]={0x3f,0x2f,0x1f,0x0f,0x0b,0x07,0x03,0x07,0x0b,0x0f,0x1f,0x2f};

// Stages definition
stagedef stagesdefinition[]=
{ 
	/* 0 Out ship      */ {0,7,92,PLAYER_UP,stage3palette_bin,FIXEDBANKSLOT,stage3tilemap_zx7,stage3tilemap_zx7_bank,16,96,stage3tilesmapping_bin,stage3tiles_zx7,stage3tiles_zx7_bank,stage1_psg,stage1_psg_bank,updatespace,stage3enemies,stage3numenemies,stage3enemysprites,stage3numenemysprites,stage3platforms,stage3numplatforms,stage3tiletypesa,stage3tiletypesb},	

	/* 1 First Shop    */ {0,8,32,PLAYER_UP,stage1palette_bin,FIXEDBANKSLOT,stage1tilemap_zx7,stage1tilemap_zx7_bank,16,35,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage1_psg,stage1_psg_bank,updatesliders,stage1enemies,stage1numenemies,stage1enemysprites,stage1numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},
	
	/* 2 Easy 1        */ {1,6,27,PLAYER_UP,stage1palette_bin,FIXEDBANKSLOT,stage9tilemap_zx7,stage9tilemap_zx7_bank,41,31,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage1_psg,stage1_psg_bank,updatesliders,stage9enemies,stage9numenemies,stage3enemysprites,stage3numenemysprites,stage9platforms,stage9numplatforms,stage1tiletypesa,stage1tiletypesb},			
	/* 3 Corridor      */ {0,8,54,PLAYER_UP,stage1palette_bin,FIXEDBANKSLOT,stage6tilemap_zx7,stage6tilemap_zx7_bank,16,58,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage1_psg,stage1_psg_bank,updatesliders,stage6enemies,stage6numenemies,stage3enemysprites,stage3numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},			
	/* 4 Easy 2T       */ {1,36,34,PLAYER_UP,stage1palette_bin,FIXEDBANKSLOT,stage8tilemap_zx7,stage8tilemap_zx7_bank,42,38,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage1_psg,stage1_psg_bank,updatesliders,stage8enemies,stage8numenemies,stage3enemysprites,stage3numenemysprites,stage8platforms,stage8numplatforms,stage1tiletypesa,stage1tiletypesb},			

	/* 5 Monster 1     */ {0,8,11,PLAYER_UP,stage1palette_bin,FIXEDBANKSLOT,stage10tilemap_zx7,stage10tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,boss_psg,boss_psg_bank,updatebosslighting,stage10enemies,stage10numenemies,stage10enemysprites,stage10numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},			

	/* 6 Stretching    */ {0,8,76,PLAYER_UP,stage4palette_bin,FIXEDBANKSLOT,stage11tilemap_zx7,stage11tilemap_zx7_bank,16,80,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage2_psg,stage2_psg_bank,updateslidersb,stage14enemies,stage14numenemies,stage14enemysprites,stage14numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	/* 7 Stretching    */ {1,12,22,PLAYER_UP,stage4palette_bin,FIXEDBANKSLOT,stage12tilemap_zx7,stage12tilemap_zx7_bank,64,26,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage2_psg,stage2_psg_bank,updateslidersb,stage15enemies,stage15numenemies,stage14enemysprites,stage14numenemysprites,stage15platforms,stage15numplatforms,stage1tiletypesa,stage1tiletypesb},		

	/* 8 The lift     */ {0,8,10,PLAYER_UP,stage4palette_bin,FIXEDBANKSLOT,stage18tilemap_zx7,stage18tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage2_psg,stage2_psg_bank,updatelift,stage33enemies,stage33numenemies,stage33enemysprites,stage33numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	
	/* 9 StretchingT   */ {0,6,46,PLAYER_UP,stage4palette_bin,FIXEDBANKSLOT,stage13tilemap_zx7,stage13tilemap_zx7_bank,32,50,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage2_psg,stage2_psg_bank,updateslidersb,stage16enemies,stage16numenemies,stage14enemysprites,stage14numenemysprites,stage13platforms,stage13numplatforms,stage1tiletypesa,stage1tiletypesb},	

	/* 10 Monster 2     */ {0,8,11,PLAYER_UP,stage4palette_bin,FIXEDBANKSLOT,stage10tilemap_zx7,stage10tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,boss_psg,boss_psg_bank,updatebosslighting,stage11enemies,stage11numenemies,stage11enemysprites,stage11numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},

	/* 11 Stretching    */ {1,4,25,PLAYER_UP,stage5palette_bin,FIXEDBANKSLOT,stage15tilemap_zx7,stage15tilemap_zx7_bank,48,29,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage3_psg,stage3_psg_bank,updatesliders,stage18enemies,stage18numenemies,stage17enemysprites,stage17numenemysprites,stage10platforms,stage10numplatforms,stage1tiletypesa,stage1tiletypesb},	
	/* 12 StretchingT   */ {1,32,35,PLAYER_UP,stage5palette_bin,FIXEDBANKSLOT,stage14tilemap_zx7,stage14tilemap_zx7_bank,44,39,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage3_psg,stage3_psg_bank,updatesliders,stage17enemies,stage17numenemies,stage17enemysprites,stage17numenemysprites,stage14platforms,stage14numplatforms,stage1tiletypesa,stage1tiletypesb},	
	
	/* 13 The Machine   */ {1,8,20,PLAYER_UP,stage5palette_bin,FIXEDBANKSLOT,stage17tilemap_zx7,stage17tilemap_zx7_bank,16,24,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage3_psg,stage3_psg_bank,updatespmachine,stage44enemies,stage44numenemies,stage44enemysprites,stage44numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},			
	
	/* 14 Stretching    */ {1,4,47,PLAYER_UP,stage5palette_bin,FIXEDBANKSLOT,stage16tilemap_zx7,stage16tilemap_zx7_bank,30,51,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage3_psg,stage3_psg_bank,updatesliders,stage19enemies,stage19numenemies,stage17enemysprites,stage17numenemysprites,stage6platforms,stage6numplatforms,stage1tiletypesa,stage1tiletypesb},	

	/* 15 Monster 3     */ {0,8,11,PLAYER_UP,stage5palette_bin,FIXEDBANKSLOT,stage10tilemap_zx7,stage10tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,boss_psg,boss_psg_bank,updatebosslighting,stage13enemies,stage13numenemies,stage13enemysprites,stage13numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},

	/* 16 First spikes  */ {1,7,21,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage2tilemap_zx7,stage2tilemap_zx7_bank,46,24,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage4_psg,stage4_psg_bank,updatesliders,stage2enemies,stage2numenemies,stage2enemysprites,stage2numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	/* 17 Second spikes */ {1,6,2,PLAYER_DOWN,stage2palette_bin,FIXEDBANKSLOT,stage4tilemap_zx7,stage4tilemap_zx7_bank,77,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage4_psg,stage4_psg_bank,updatesliders,stage4enemies,stage4numenemies,stage2enemysprites,stage2numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	
	/* 18 The lift B    */ {0,8,10,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage18tilemap_zx7,stage18tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage4_psg,stage4_psg_bank,updatelift,stage33enemies,stage33numenemies,stage33enemysprites,stage33numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	

	/* 19 Third spikes  */ {0,8,108,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage5tilemap_zx7,stage5tilemap_zx7_bank,16,112,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage4_psg,stage4_psg_bank,updatesliders,stage5enemies,stage5numenemies,stage2enemysprites,stage2numenemysprites,stage5platforms,stage5numplatforms,stage1tiletypesa,stage1tiletypesb},			
	/* 20 ZigzagT       */ {1,36,29,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage7tilemap_zx7,stage7tilemap_zx7_bank,42,33,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,stage4_psg,stage4_psg_bank,updateslidersc,stage7enemies,stage7numenemies,stage2enemysprites,stage2numenemysprites,stage7platforms,stage7numplatforms,stage1tiletypesa,stage1tiletypesb},				
	
	/* 21 Monster 4     */ {0,8,11,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage10tilemap_zx7,stage10tilemap_zx7_bank,16,14,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,boss_psg,boss_psg_bank,updatebosslighting,stage12enemies,stage12numenemies,stage12enemysprites,stage12numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	
	/* 22 The master    */ {0,8,20,PLAYER_UP,stage2palette_bin,FIXEDBANKSLOT,stage17tilemap_zx7,stage17tilemap_zx7_bank,16,24,stage1tilesmapping_bin,stage1tiles_zx7,stage1tiles_zx7_bank,0,0,updatesliders,stage23enemies,stage23numenemies,stage23enemysprites,stage23numenemysprites,0,0,stage1tiletypesa,stage1tiletypesb},	
	
};
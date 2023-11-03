#include "includes.h"

// Balout
unsigned char baloutposy;
unsigned char baloutbposy;
unsigned int baloutframe;
unsigned char baloutstage;
unsigned char baloutlevel;		
unsigned char baloutvel;
signed char baloutvelx;
signed char baloutvely;
unsigned char baloutballx;
unsigned char baloutbally;
		
// No puede saltar
unsigned char cannotjump;

// Dificultad
unsigned char gamelevel;

// Controles
unsigned char buttoninverse;
unsigned char button1;
unsigned char button2;

// Variables del player
unsigned char playerside;			// Lado al que mira el player
unsigned int playerx;				// Posicion X del player
unsigned int playery;				// Posicion Y del player
unsigned char playerz;				// Posicion Z del player
signed char playerspeedz;			// Velocidad Z del player
signed char playerspeedx;			// Velocidad X del player
signed char playerspeedy;			// Velocidad Y del player
unsigned char playerstatus;			// Status de player
unsigned char playerdiecounter;		// Contador de muerte
#ifdef USEPLAYERSHOOTCOUNTER
	unsigned char playershootcounter;	// Contador de disparo
#endif
unsigned char playerinmunecounter;	// Tiempo de inmunidad del player
unsigned char playertile;			// Donde está el player
unsigned char playerkeymoved;		// Si se ha movido el player
unsigned char playertype;			// Tipo de player
unsigned char playercoins;			// Monedas

// For the shop
unsigned char shopoption;

// Keyboard
unsigned char playershootreleased;	// Shoot released?
unsigned char playerjumpreleased;	// Jump released?

// Check if we are ingame
unsigned char ingame;

// If we have to draw player
unsigned char drawplayer;

unsigned char gamestock;	// Stock for init of the game
unsigned char numplayers;	// Number of player
unsigned char numstage;		// Stage number
unsigned char laststage;	// Last stage, for continue
unsigned int stageframe;	 // Stage frame
unsigned char keystatus;	// Estado del teclado
unsigned char musicbank;	// Banco de la musica
unsigned char soundbank;	// Banco de sonidos
unsigned char numinterrupts;// Numero de interrupciones
const unsigned char *lastpalette;	// Ultima paleta usada
unsigned char lastpalettebank;		// Banco de la ultima paleta
unsigned char usedlastpalette;  	// Si estamos usando una paleta
unsigned char stageframe2mod;	// Cacheando frames
unsigned char stageframe4mod;	// Cacheando frames
unsigned char stageframe8mod;	// Cacheando frames
unsigned int stageframe2div;	// Cacheando frames
unsigned int stageframe4div;	// Cacheando frames
unsigned int stageframe8div;	// Cacheando frames
const unsigned char *lastplayedmusic;	// Ultima musica usada
unsigned char lastplayedmusicbank;		// Banco de la ultima musica
unsigned char lastplayedmusiclooped;  	// Si estamos usando una musica
unsigned char jukeboxselectedline;		// Linea seleccionada por el jukebox
unsigned char jukeboxselectedsong;		// Musica seleccionada por el jukebox
unsigned char jukeboxcheckkey;			// Chequea por una tecla
unsigned char stagestopped;				// Si esta parada
unsigned char stoppedstageframe;		// La frame de stopped
const labelscr *stoppedstagelabel;		// La label
unsigned char stoppedstagex;
unsigned char stoppedstagey;
unsigned char stoppedstageexitonkey;
	
unsigned char stageexitable;			// Si se puede salir de la stage
unsigned char stagestate;				// State for intros and stages
unsigned char labelstate;				// State for intro labels

// Usado para mapas y decompresiones
unsigned char tempbuffer[2048];			// Buffer para mapas y demas

// Mapa
const unsigned char *maptiles;			// Puntero a las tiles de un mapa
unsigned char mapbank;					// Banco en el que está un mapa
unsigned int mapposx;					// Posicion X de una camera
unsigned int mapposy;					// Posicion Y de una camera
unsigned char maptileposx;				// Posicion X en tiles de un mapa
unsigned char maptileposy;				// Posicion Y en tiles de un mapa
unsigned int mapwidth;					// Ancho de mapa
unsigned int mapheight;					// Alto de mapa
unsigned char maptilewidth;				// Ancho en tiles de mapa
unsigned char maptileheight;			// Alto de tiles de mapa
const unsigned char *maptilemappings;		    // Mappings

// Donde estuvo el jugador
unsigned int lastplayerx;
unsigned int lastplayery;
unsigned char lastplayerside;

// Pausa
unsigned char gamepause;				// Si estamos en pausa

// Explosiones
unsigned char numexplosions;
explosion explosions[MAXEXPLOSIONS];

// Spawned explosion
unsigned int spawnedexplosionposx;
unsigned int spawnedexplosionposy;
unsigned char spawnedexplosionwidth;
unsigned char spawnedexplosionheight;
unsigned char spawnedexplosiontime;
unsigned char spawnedexplosionbarrom;

// Barrom
unsigned char barromtime;			// Tiempo del barrom
signed char barromposx;				// Pos Y to pass to map
signed char barromposy;				// Pos X to pass to map

// Tiles
const unsigned char *stagetiletypes;
const unsigned char *stagetiletypesa;
const unsigned char *stagetiletypesb;

// Update function of stage
MyStageUpdateFunction stageupdatecustomfunc;

// Enemies
enemy enemies[MAXENEMIES];
unsigned char numenemies;

// Enemyslots
enemyslot enemyslots[MAXENEMYSLOTS];
unsigned char numenemyslots;
unsigned char usedenemyslots[MAXENEMYSLOTS];

// Enemyspriteslots
enemyspritebase *enemyslotsprites;
unsigned char numenemyslotsprites;

// Goodies
goodie goodies[MAXGOODIES];
unsigned char numgoodies;

// Player shoots
shoot playershoots[MAXPLAYERSHOOTS];
unsigned char numplayershoots;

// Enemy shoots
shoot enemyshoots[MAXENEMYSHOOTS];
unsigned char numenemyshoots;

// Platforms
unsigned char numplatforms;
platform platforms[MAXPLATFORMS];
signed char playerplatformx;
signed char playerplatformy;


// This var exists
volatile __at (0xffff) unsigned char lastbank;


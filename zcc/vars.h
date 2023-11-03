#ifndef _VARS_H
#define _VARS_H

// Balout
extern unsigned char baloutposy;
extern unsigned int baloutframe;
extern unsigned char baloutstage;
extern unsigned char baloutlevel;
extern unsigned char baloutvel;
extern signed char baloutvelx;
extern signed char baloutvely;
extern unsigned char baloutbposy;
extern unsigned char baloutballx;
extern unsigned char baloutbally;

// No puede saltar
extern unsigned char cannotjump;

// Dificultad
extern unsigned char gamelevel;

// Controles
extern unsigned char buttoninverse;
extern unsigned char button1;
extern unsigned char button2;

// Variables del player
extern unsigned char playerside;			// Lado al que mira el player
extern unsigned int playerx;				// Posicion X del player
extern unsigned int playery;				// Posicion Y del player
extern unsigned char playerz;					// Posicion Z del player
extern signed char playerspeedz;			// Velocidad Z del player
extern signed char playerspeedx;			// Velocidad X del player
extern signed char playerspeedy;			// Velocidad Y del player
extern unsigned char playerstatus;			// Status de player
extern unsigned char playerdiecounter;		// Contador de muerte
#ifdef USEPLAYERSHOOTCOUNTER
extern unsigned char playershootcounter;	// Contador de disparo
#endif
extern unsigned char playerinmunecounter;	// Tiempo de inmunidad del player
extern unsigned char playertile;			// Donde está el player
extern unsigned char playerkeymoved;		// Si se ha movido el player
extern unsigned char playertype;			// Tipo de player
extern unsigned char playercoins;			// Monedas

// Draw player?
extern unsigned char drawplayer;

// For the shop
extern unsigned char shopoption;

// Keyboard
extern unsigned char playershootreleased;	// Shoot released?
extern unsigned char playerjumpreleased;	// Jump released?

// Check if we are ingame
extern unsigned char ingame;

// Donde estuvo el jugador
extern unsigned int lastplayerx;
extern unsigned int lastplayery;
extern unsigned char lastplayerside;

// Variables de fase
extern unsigned char gamestock;		// Stock for init of the game
extern unsigned char numplayers;	// Number of player
extern unsigned char numstage;		// Stage number
extern unsigned char laststage;		// Last stage, for continue
extern unsigned int stageframe;		// Stage frame
extern unsigned char  keystatus;		// Estado del teclado
extern unsigned char musicbank;		// Banco de la musica
extern unsigned char soundbank;		// Banco de sonidos
extern unsigned char numinterrupts; // Numero de interrupciones
extern const unsigned char *lastpalette;	// Ultima paleta usada
extern unsigned char lastpalettebank;		// Banco de la ultima paleta
extern unsigned char usedlastpalette;  		// Si estamos usando una paleta
extern unsigned char stageframe2mod;	// Cacheando frames
extern unsigned char stageframe4mod;	// Cacheando frames
extern unsigned char stageframe8mod;	// Cacheando frames
extern unsigned int stageframe2div;	// Cacheando frames
extern unsigned int stageframe4div;	// Cacheando frames
extern unsigned int stageframe8div;	// Cacheando frames
extern const unsigned char *lastplayedmusic;	// Ultima musica usada
extern unsigned char lastplayedmusicbank;		// Banco de la ultima musica
extern unsigned char lastplayedmusiclooped;  	// Si estamos usando una musica
extern unsigned char jukeboxselectedline;		// Linea seleccionada por el jukebox
extern unsigned char jukeboxselectedsong;		// Musica seleccionada por el jukebox
extern unsigned char jukeboxcheckkey;		// Chequea por una tecla
extern unsigned char stagestopped;			// Si esta parada
extern unsigned char stoppedstageframe;		// La frame de stopped
extern const labelscr *stoppedstagelabel;		// La label
extern unsigned char stoppedstagex;
extern unsigned char stoppedstagey;
extern unsigned char stoppedstageexitonkey;
extern unsigned char gamepause;				// Si estamos en pausa
extern unsigned char stageexitable;			// Si se puede salir de la stage

// Buffer para mapas y demas
extern unsigned char tempbuffer[2048];			

// Mapa
extern const unsigned char *maptiles;			// Puntero a las tiles de un mapa
extern unsigned char mapbank;					// Banco en el que está un mapa
extern unsigned int mapposx;					// Posicion X de una camera
extern unsigned int mapposy;					// Posicion Y de una camera
extern unsigned char maptileposx;				// Posicion X en tiles de un mapa
extern unsigned char maptileposy;				// Posicion Y en tiles de un mapa
extern unsigned int mapwidth;					// Ancho de mapa
extern unsigned int mapheight;					// Alto de mapa
extern unsigned char maptilewidth;				// Ancho en tiles de mapa
extern unsigned char maptileheight;			// Alto de tiles de mapa
extern const unsigned char *maptilemappings;

// Explosiones
extern unsigned char numexplosions;
extern explosion explosions[MAXEXPLOSIONS];

// Spawned explosion
extern unsigned int spawnedexplosionposx;
extern unsigned int spawnedexplosionposy;
extern unsigned char spawnedexplosionwidth;
extern unsigned char spawnedexplosionheight;
extern unsigned char spawnedexplosiontime;
extern unsigned char spawnedexplosionbarrom;

// Barrom
extern unsigned char barromtime;	// Tiempo del barrom
extern signed char barromposx;		// Pos Y to pass to map
extern signed char barromposy;		// Pos X to pass to map

// Tiles
extern const unsigned char *stagetiletypes;
extern const unsigned char *stagetiletypesa;
extern const unsigned char *stagetiletypesb;

// Update function of stage
extern MyStageUpdateFunction stageupdatecustomfunc;

// Enemies
extern enemy enemies[MAXENEMIES];
extern unsigned char numenemies;

// Enemyslots
extern enemyslot enemyslots[MAXENEMYSLOTS];
extern unsigned char numenemyslots;
extern unsigned char usedenemyslots[MAXENEMYSLOTS];

// Enemyspriteslots
extern enemyspritebase *enemyslotsprites;
extern unsigned char numenemyslotsprites;

// Goodies
extern goodie goodies[MAXGOODIES];
extern unsigned char numgoodies;

// Player shoots
extern shoot playershoots[MAXPLAYERSHOOTS];
extern unsigned char numplayershoots;

// Enemy shoots
extern shoot enemyshoots[MAXENEMYSHOOTS];
extern unsigned char numenemyshoots;

// This var exists
extern volatile __at (0xffff) unsigned char lastbank;

// For intro
extern unsigned char stagestate;		
extern unsigned char labelstate;

// Platforms
extern unsigned char numplatforms;
extern platform platforms[MAXPLATFORMS];
extern signed char playerplatformx;
extern signed char playerplatformy;


#endif


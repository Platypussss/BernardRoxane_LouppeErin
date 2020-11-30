#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct joueur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct joueur_s joueur_t;

struct mur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct mur_s mur_t;


/**initialise les données du joueur*/
void init_joueur(joueur_t* j,int a,int b,int c,int d);


/**initialise les données du mur*/
void init_mur(mur_t* m,int a,int b,int c,int d);

/**détecte les collisions avec le joueur et les murs*/
int est_en_collision_mur(joueur_t* joueur,mur_t* mur);

struct mur_s{
	int x;
	int y;
};
typedef struct mur_s mur_t;

/**initialise les données du mur*/
void init_mur(mur_t m,int a,int b);

#endif

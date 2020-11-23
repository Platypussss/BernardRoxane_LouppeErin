#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct joueur_s{
	int x;
	int y;
};
typedef struct joueur_s joueur_t;

/**initialise les données du joueur*/
void init_joueur(joueur_t j,int a,int b);

#endif

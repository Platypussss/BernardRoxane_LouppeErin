#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 640

/**initialise les données du joueur*/
void init_joueur(joueur_t* j,int a,int b,int c,int d){
	j->x=a;
	j->y=b;
	j->h=c;
	j->w=d;
}

void init_mur(mur_t* m, int a, int b,int c,int d){
	m->x=a;
	m->y=b;
	m->h=c;
	m->w=d;
}

/**détecte les collisions avec le joueur et les murs*/
int est_en_collision_mur(joueur_t* j,mur_t* m){
	int x=(j->x)+(j->w)/2;
	int x1=(m->x)+(m->w)/2;
	if(((x)-(x1))*((x)-(x1))+(((j->y)-(m->y))*((j->y)-(m->y)))<((j->h)*(m->h))){
		return 1;
	}
	return 0;
}






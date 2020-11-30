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

<<<<<<< HEAD
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
=======
void init_mur(mur_t m, int a, int b){
	m.x=a;
	m.y=b;
}

/**détecte les collisions avec le joueur et les murs
int est_en_collision_mur(joueur_t joueur,mur_t* mur){
	if(((joueur.x)-(mur->x))*((joueur.x)-(mur->x))+(((joueur.y)-(mur->y))*((joueur.y)-(mur->y)))<((joueur.h)*(joueur.h))){
>>>>>>> 0f917f66310870fc7df7f1409aaff5dd2c5b903f
		return 1;
	}
	return 0;
}






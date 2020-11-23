#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 640

/**initialise les données du joueur*/
void init_joueur(joueur_t j,int a,int b){
	j.x=a;
	j.y=b;
}

/**détecte les collisions avec le joueur et les murs
int est_en_collision_mur(joueur_t joueur,mur_t* mur){
	if(((joueur.x)-(mur->x))*((joueur.x)-(mur->x))+(((joueur.y)-(mur->y))*((joueur.y)-(mur->y)))<((joueur.h)*(joueur.h))){
		return 1;
	}
	return 0;
}	
*/

/**
void gere_collision_mur

*/






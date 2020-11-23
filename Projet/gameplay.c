#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 640

void init_joueur(joueur_t j,int a,int b){
	j.x=a;
	j.y=b;
}




#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonction_image.h"
#include "fonctions_fichiers.c"
//#include "fonctions_tableau.c"


/**charge une image et retourne la surface de texture associée*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
	/**charger l'image*/
	SDL_Surface * surface=SDL_LoadBMP(nomfichier);
	/**convertir la surface de l'image au format texture*/
	SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,surface);
	return texture;
}




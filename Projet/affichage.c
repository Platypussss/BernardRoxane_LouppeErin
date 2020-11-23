#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affichage.h"
#include "fichiers.c"


/**charge une image et retourne la surface de texture associée*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
	/**charger l'image*/
	SDL_Surface * surface=SDL_LoadBMP(nomfichier);
	/**convertir la surface de l'image au format texture*/
	SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,surface);
	return texture;
}

/**applique une texture sur un renderer
* x l'abscisse du rendere où l'on applique la texture
* y l'ordonnée du rendere où l'on applique la texture
*/
void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y){
    SDL_Rect dst = {0, 0, 0, 0};
    
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y=y;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);   
}



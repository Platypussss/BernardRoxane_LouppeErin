#ifndef H_AFFICHAGE
#define H_AFFICHAGE

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**charge une image et retourne la surface de texture associée*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer); 

/**applique une texture sur un renderer
* x l'abscisse du rendere où l'on applique la texture
* y l'ordonnée du rendere où l'on applique la texture
*/
void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);

#endif

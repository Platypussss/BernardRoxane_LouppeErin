#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affichage.h"



/**
* \brief charge une image et retourne la surface de texture associée
* \param nomfichier l'image associée
* \param rendere la surface correspondant à l'écran du jeu
*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
	/**charger l'image*/
	SDL_Surface * surface=SDL_LoadBMP(nomfichier);
	/**convertir la surface de l'image au format texture*/
	SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,surface);
	return texture;
}

/**
 * \brief La fonction initialise les texures
 * \param renderer la surface correspondant à l'écran de jeu
 * \param texture les textures du jeu
*/
void init_textures(SDL_Renderer* renderer,textures_t* textures){
	textures->fond=charger_image("ressources/fond1.bmp",renderer);
	textures->perso=charger_image("ressources/marche1.bmp",renderer);
	textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
	textures->ennemi=charger_image("ressources/ennemi.bmp",renderer);
	textures->arme=charger_image("ressources/arme.bmp",renderer);
}

/**
* \brief applique une texture sur un renderer
* \param x l'abscisse du renderer où l'on applique la texture
* \param y l'ordonnée du renderer où l'on applique la texture
*/
void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y){
    SDL_Rect dst = {0, 0, 0, 0};
    
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y=y;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);   
}
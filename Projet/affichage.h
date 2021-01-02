#ifndef H_AFFICHAGE
#define H_AFFICHAGE

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 1000

struct textures_s{
    SDL_Texture* fond;
    SDL_Texture* perso;
    SDL_Texture* murtoutseul;
    SDL_Texture* ennemi;
    SDL_Texture* arme;
};
typedef struct textures_s textures_t;
/**
 * \brief Type qui correspond aux textures du jeu
 */


/**
* \brief charge une image et retourne la surface de texture associée
* \param nomfichier l'image associée
* \param rendere la surface correspondant à l'écran du jeu
*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer); 


/**
 * \brief La fonction initialise les texures
 * \param renderer la surface correspondant à l'écran de jeu
 * \param texture les textures du jeu
*/
void init_textures(SDL_Renderer* renderer,textures_t* textures);

/**
* \brief applique une texture sur un renderer
* \param x l'abscisse du renderer où l'on applique la texture
* \param y l'ordonnée du renderer où l'on applique la texture
*/
void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);


#endif

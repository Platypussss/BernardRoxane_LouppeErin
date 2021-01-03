#include "ttf.h"

/**
 * \brief La fonction initialise l'environnement TTF
*/

void init_ttf(){
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
    }
}


/**
 * \brief La fonction charge une police
 * \param path le chemin du fichier correpondant à la police
 * \param font_size la taille de la police
 * \return la police chargée
*/

TTF_Font * charger_ecriture(const char *chemin, int taille){
    TTF_Font *font = TTF_OpenFont(chemin, taille);
    if(font == NULL){
        fprintf(stderr, "Erreur pendant chargement font: %s\n", SDL_GetError());
    }
    return font;
}


/**
 * \brief La fonction applique un texte dans une certaine police sur le renderer à une certaine position et avec une certaine dimension
 * \param renderer le renderer
 * \param text le texte à afficher
 * \param font la police
 * \param color la couleur de la police
 * \return la texture associée
*/


SDL_Texture* charger_texte(SDL_Renderer *renderer,const char *text, TTF_Font *font,SDL_Color color){
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
    
}

/**
* \brief nettoie la police
* \param font la police
*/
void clean_font(TTF_Font * font){
    TTF_CloseFont(font);
}

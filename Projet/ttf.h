#ifndef TTF_H
#define TTF_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * \brief La fonction initialise l'environnement TTF
*/
void init_ttf();

/**
 * \brief La fonction charge une police
 * \param path le chemin du fichier correpondant à la police
 * \param font_size la taille de la police
 * \return la police chargée
*/
TTF_Font * charger_ecriture(const char* chemin, int taille);

/**
 * \brief La fonction applique un texte dans une certaine police sur le renderer à une certaine position et avec une certaine dimension
 * \param renderer le renderer
 * \param text le texte à afficher
 * \param font la police
 * \param color la couleur de la police
 * \return la texture associée
*/
SDL_Texture* charger_texte(SDL_Renderer *renderer,const char *text, TTF_Font *font,SDL_Color color);

/**
* \brief nettoie la police
* \param font la police
*/
void clean_font(TTF_Font * font);

#endif
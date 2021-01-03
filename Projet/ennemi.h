#ifndef H_ENNEMI
#define H_ENNEMI 

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arme.c"

/**
 * \brief Type qui correspond a un ennemi du jeu
 */
struct ennemi_s{
	int x;
	int y;
	int h;
	int w;
	arme_t *missile;
};
typedef struct ennemi_s ennemi_t;

/**
* \brief initialise les données d'un ennemi
* \param e l'ennemi
* \param a l'abscisse de l'ennemi
* \param b l'ordonnée de l'ennemi
* \param c la hauteur de l'ennemi
* \param d la largeur de l'ennemi
*/
void init_ennemi(ennemi_t* e,int a,int b,int c,int d);

#endif

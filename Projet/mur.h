#ifndef H_MUR
#define H_MUR

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * \brief Type qui correspond aux murs du jeu
 */
struct mur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct mur_s mur_t;

/**
* \brief initialise les données d'un mur
* \param m le mur
* \param a l'abscisse du mur
* \param b l'ordonnée du mur
* \param c la hauteur du mur
* \param d la largeur du mur
*/
void init_mur(mur_t* m,int a,int b,int c,int d);

#endif
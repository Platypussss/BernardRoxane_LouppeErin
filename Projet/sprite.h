#ifndef H_SPRITE
#define H_SPRITE

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arme.c"

/**
 * \brief Type qui correspond au sprite du jeu
 */
struct sprite_s{
	int x;
	int y;
	int h;
	int w;
	arme_t *missile;
};
typedef struct sprite_s sprite_t;

/**
* \brief initialise les données du sprite
* \param j le sprite
* \param a l'abscisse du sprite
* \param b l'ordonnée du sprite
* \param c la hauteur du sprite
* \param d la largeur du sprite
*/
void init_sprite(sprite_t* j,int a,int b,int c,int d);

/**
* \brief libère l'espace mémoire occupé par le sprite
* \param sprite à libérer
*/
void clean_sprite(sprite_t *sprite);

#endif
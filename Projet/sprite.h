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
	int sens;
	int vie;
	int est_visible; 	//0 si vrai 1 sinon
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
* \param s l'orientation du sprite
* \param v la vie du sprite
* \param e 0 si le sprite est visible 1 sinon
*/
void init_sprite(sprite_t* j,int a,int b,int c,int d,int s,int v,int e);

/**
* \brief change la valeur du champ est_visible
* \param s le sprite qu'on modifie
* \param e la nouvelle valeur valeur
*/
void set_est_visible(sprite_t *s,int e);

/**
* \brief retourne le champ est_visible
* \param s le arme_t qu'on souhaite examiner
* \return la valeur du champ est_visible
*/
int get_est_visible(sprite_t *s);

/**
* \brief libère l'espace mémoire occupé par le sprite
* \param sprite à libérer
*/
void clean_sprite(sprite_t *sprite);

#endif
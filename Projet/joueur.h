#ifndef H_JOUEUR
#define H_JOUEUR

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arme.c"

/**
 * \brief Type qui correspond au joueur du jeu
 */
struct joueur_s{
	int x;
	int y;
	int h;
	int w;
	arme_t *missile;
};
typedef struct joueur_s joueur_t;

/**
* \brief initialise les données du joueur
* \param j le joueur
* \param a l'abscisse du joueur
* \param b l'ordonnée du joueur
* \param c la hauteur du joueur
* \param d la largeur du joueur
*/
void init_joueur(joueur_t* j,int a,int b,int c,int d);

/**
* \brief libère l'espace mémoire occupé par le joueur
* \param joueur à libérer
*/
void clean_joueur(joueur_t *joueur);

#endif
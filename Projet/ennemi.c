#include "ennemi.h"

/**
* \brief initialise les données d'un ennemi
* \param e l'ennemi
* \param a l'abscisse de l'ennemi
* \param b l'ordonnée de l'ennemi
* \param c la hauteur de l'ennemi
* \param d la largeur de l'ennemi
*/
void init_ennemi(ennemi_t* e,int a,int b,int c,int d){
	e->x=a;
	e->y=b;
	e->h=c;
	e->w=d;
}
#include "mur.h"

/**
* \brief initialise les données du mur
* \param m le mur
* \param a l'abscisse du mur
* \param b l'ordonnée du mur
* \param c la hauteur du mur
* \param d la largeur du mur
*/
void init_mur(mur_t* m, int a, int b,int c,int d){
	m->x=a;
	m->y=b;
	m->h=c;
	m->w=d;
}
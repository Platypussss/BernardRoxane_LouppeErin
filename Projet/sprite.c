#include "sprite.h"

/**
* \brief initialise les données du sprite
* \param j le sprite
* \param a l'abscisse du sprite
* \param b l'ordonnée du sprite
* \param c la hauteur du sprite
* \param d la largeur du sprite
* \param v la vie du sprite
*/
void init_sprite(sprite_t* j,int a,int b,int c,int d,int v){
	j->x=a;
	j->y=b;
	j->h=c;
	j->w=d;
	j->vie=v;
	j->missile=malloc(sizeof(arme_t));
	init_arme(j->missile,10,10,10,10,0);
}

/**
* \brief libère l'espace mémoire occupé par le sprite
* \param sprite à libérer
*/
void clean_sprite(sprite_t *sprite){
    free(sprite->missile);
}
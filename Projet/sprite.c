#include "sprite.h"

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
void init_sprite(sprite_t* j,int a,int b,int c,int d,int s,int v,int e){
	j->x=a;
	j->y=b;
	j->h=c;
	j->w=d;
	j->sens=s;
	j->vie=v;
	j->missile=malloc(sizeof(arme_t));
	j->est_visible=e;
	init_arme(j->missile,a,b,10,10,1);
}

/**
* \brief change la valeur du champ est_visible
* \param s le sprite qu'on modifie
* \param e la nouvelle valeur valeur
*/
void set_est_visible(sprite_t *s,int e){
    s->est_visible=e;
}

/**
* \brief retourne le champ est_visible 
* \param s le arme_t qu'on souhaite examiner
* \return la valeur du champ est_visible
*/
int get_est_visible(sprite_t *s){
    return s->est_visible;
}

/**
* \brief libère l'espace mémoire occupé par le sprite
* \param sprite à libérer
*/
void clean_sprite(sprite_t *sprite){
    free(sprite->missile);
}
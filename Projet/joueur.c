#include "joueur.h"

/**
* \brief initialise les données du joueur
* \param j le joueur
* \param a l'abscisse du joueur
* \param b l'ordonnée du joueur
* \param c la hauteur du joueur
* \param d la largeur du joueur
*/
void init_joueur(joueur_t* j,int a,int b,int c,int d){
	j->x=a;
	j->y=b;
	j->h=c;
	j->w=d;
	j->missile=malloc(sizeof(arme_t));
	init_arme(j->missile,10,10,10,10,0);
}

/**
* \brief libère l'espace mémoire occupé par le joueur
* \param joueur à libérer
*/
void clean_joueur(joueur_t *joueur){
    free(joueur->missile);
}
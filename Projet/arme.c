#include "arme.h"

/**
* \brief la fonction qui initialise un arme_t
* \param a le arme_t à initialiser
* \param x l'abscisse
* \param y l'ordonnée
* \param h la hauteur
* \param w la largeur
* \param e 0 si l'arme est visible 1 sinon
*/
void init_arme(arme_t *a,int x,int y,int h,int w,int e){
    a->x=x;
    a->y=y;
    a->h=h;
    a->w=w;
    a->est_visible=e;
}

/**
* \brief change la valeur du champ est_visible d'une arme
* \param a le arme_t qu'on modifie
* \param e la nouvelle valeur valeur
*/
void set_est_visible_arme(arme_t *a,int e){
    a->est_visible=e;
}

/**
* \brief retourne le champ est_visible d'une arme
* \param a le arme_t qu'on souhaite examiner
* \return la valeur du champ est_visible
*/
int get_est_visible_arme(arme_t *a){
    return a->est_visible;
}
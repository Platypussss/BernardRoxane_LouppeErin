#include "map.h"

/**
* \brief initialise l'ensemble de tous les murs
* \param tab le tableau de mur_t et d'ennemis
*/
void init_map(tab_t *tab){
	
	for(int i=0;i<NB_MURS;i++){
		tab->tab_mur[i]=malloc(sizeof(mur_t));
		init_mur(tab->tab_mur[i],-50,-50,50,50);
    }
    for(int i=0;i<NB_ENNEMIS;i++){
        tab->tab_ennemi[i]=malloc(sizeof(ennemi_t));
        init_ennemi(tab->tab_ennemi[i],-100,-100,100,100);  //à voir avec les designs des ennemis

    }
}

/**
* \brief libère l'espace mémoire occupé par la map (les murs et les ennemis)
* \param tab à libérer
*/
void clean_map(tab_t *tab){
    for(int i=0;i<NB_MURS;i++){
        free(tab->tab_mur[i]);
    }
    for(int i=0;i<NB_ENNEMIS;i++){
        free(tab->tab_ennemi[i]);
    }
}
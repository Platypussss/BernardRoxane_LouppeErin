#include "map.h"

/**
* \brief initialise l'ensemble de tous les murs
* \param tab le tableau de mur_t et d'ennemis
*/
void init_map(tab_t *tab){
	
    //initialisation des murs
	for(int i=0;i<NB_MURS;i++){
		tab->tab_mur[i]=malloc(sizeof(sprite_t));
		init_sprite(tab->tab_mur[i],-50,-50,50,50,1,-10,0);
    }
    //initialisation des ennemis
    for(int i=0;i<NB_ENNEMIS;i++){
        tab->tab_ennemi[i]=malloc(sizeof(sprite_t));
        init_sprite(tab->tab_ennemi[i],-100,-100,100,100,1,5,0);

    }
}

/**
* \brief libère l'espace mémoire occupé par la map (les murs et les ennemis)
* \param tab à libérer
*/
void clean_map(tab_t *tab){
    for(int i=0;i<NB_MURS;i++){
        //clean les murs
        clean_sprite(tab->tab_mur[i]);
    }
    for(int i=0;i<NB_ENNEMIS;i++){
        //clean les ennemis
        clean_sprite(tab->tab_ennemi[i]);
    }
}

#ifndef H_MAP
#define H_MAP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sprite.c"

#define NB_MURS 100
#define NB_ENNEMIS 20

struct tab_s{
	sprite_t *tab_mur[NB_MURS];
    sprite_t *tab_ennemi[NB_ENNEMIS];
};
typedef struct tab_s tab_t;


/**
* \brief initialise l'ensemble de tous les murs
* \param tab le tableau de mur_t et d'ennemis
*/
void init_map(tab_t *tab);

/**
* \brief libère l'espace mémoire occupé par la map (les murs et les ennemis)
* \param tab à libérer
*/
void clean_map(tab_t *tab);

#endif
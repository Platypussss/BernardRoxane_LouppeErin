#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.c"


/**
* \brief détecte les collisions entre les sprites
* \param j le sprite
* \param m le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision(sprite_t* sprite,sprite_t* sprite2,int sens);

/*/**
* \brief détecte si le sprite se trouve sur un sprite
* \param j le jouer
* \param m le sprite 
* \return 1 si le sprite se trouve sur un sprite
*/
//int est_sur_sprite(sprite_t* j,sprite_t* m,int sens);

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_haut(textures_t* textures,SDL_Renderer* renderer,int sens,sprite_t *sprite);

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens,sprite_t *sprite);

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau en potentiel collision avec le sprite
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab,int sens);

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau en potentiel collision avec le sprite
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab,int sens);

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param sens du sprite 
* \param tab le tableau en potentiel collision avec le sprite
* \return l'orientation du perso
*/
int saut(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,int sens,tab_t *tab);

/**
* \brief fonction qui modifie les coordonnées de tous les sprites et ennemis en fonction des caractères du fichier
* \param nomfichier le fichier représentant le fond avec les sprites
* \param tab le tableau de sprite_t
*/
void lire_fichier(const char* nomfichier,tab_t *tab);


/**
* \brief empêche les personnages de sortir de l'écran horizontalement
* \param j le personnage qui bouge 
*/
void limite_horizontale(sprite_t *j);

#endif

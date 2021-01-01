#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.c"

/**
* \brief fonction qui gère la perte de vie 
* \param sp1 le sprite qui pert une vie
* \param sp2 le sprite qui pert une vie
*/
void perte_vie(sprite_t *sp1,sprite_t *sp2);

/**
* \brief détecte les collisions entre les sprites
* \param j le sprite
* \param m le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision(sprite_t* sprite,sprite_t* sprite2,int sens);

/**
* \brief fonction qui gère les collisions
* \param sp1 le sprite en potentiel collision
* \param tab le tableau de sprite en potentiel collision
* \param sens_sp1 l'orientataion du sprite sp1
*/
void gere_collision(sprite_t *sp1, tab_t *tab, int sens_sp1);

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

/**
* \brief fonction que dit si le jeu est fini
* \param j le joueur, vérifie qu'il a encore de la vie
* \param tab les ennemis, vérifie leur vie
* \return true si le joueur n'a plus de vie ou si tout les ennemis n'ont plus de vie, flase sinon
*/
bool jeu_fini(sprite_t *j,tab_t *tab);

#endif

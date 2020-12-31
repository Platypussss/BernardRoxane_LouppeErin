#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "joueur.c"
#include "map.c"

/**
* \brief détecte les collisions avec le joueur et les murs
* \param j le joueur
* \param m le mur
* \return 1 s'il y a une collision
*/
int est_en_collision(joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief détecte si le joueur se trouve sur un mur
* \param j le jouer
* \param m le mur 
* \return 1 si le joueur se trouve sur un mur
*/
int est_sur_mur(joueur_t* j,mur_t* m);

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_haut(textures_t* textures,SDL_Renderer* renderer,int sens,joueur_t *joueur);

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens,joueur_t *joueur);

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,tab_t *tab,int sens);

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param tab le tableau de mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,tab_t *tab,int sens);

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param sens du joueur 
* \param tab le tableau de mur en potentiel collision avec le joueur
* \return l'orientation du perso
*/
int saut(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,int sens,tab_t *tab);

/**
* \brief fonction qui modifie les coordonnées de tous les murs et ennemis en fonction des caractères du fichier
* \param nomfichier le fichier représentant le fond avec les murs
* \param tab le tableau de mur_t
*/
void lire_fichier(const char* nomfichier,tab_t *tab);


/**
* \brief empêche les personnages de sortir de l'écran horizontalement
* \param j le personnage qui bouge 
*/
void limite_horizontale(joueur_t *j);

#endif

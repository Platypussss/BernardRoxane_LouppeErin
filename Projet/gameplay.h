#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct joueur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct joueur_s joueur_t;
/**
 * \brief Type qui correspond au joueur du jeu
 */


struct mur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct mur_s mur_t;
/**
 * \brief Type qui correspond aux murs du jeu
 */


/**
* \brief initialise les données du joueur
* \param j le joueur
* \param a l'abscisse du joueur
* \param b l'ordonnée du joueur
* \param c la hauteur du joueur
* \param d la largeur du joueur
*/
void init_joueur(joueur_t* j,int a,int b,int c,int d);


/**
* \brief initialise les données du mur
* \param m le mur
* \param a l'abscisse du mur
* \param b l'ordonnée du mur
* \param c la hauteur du mur
* \param d la largeur du mur
*/
void init_mur(mur_t* m,int a,int b,int c,int d);

/**
* \brief détecte les collisions avec le joueur et les murs
* \param j le joueur
* \param m le mur
*/
int est_en_collision_mur(joueur_t* joueur,mur_t* mur);

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur 
*/
int bouger_haut(textures_t* textures,SDL_Renderer* renderer,int sens);

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur 
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens);

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur 
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur 
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur 
*/
int saut(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens);

#endif

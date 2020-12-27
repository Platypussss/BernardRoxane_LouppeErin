#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "affichage.c"

#define NB_MURS 20

/**
 * \brief Type qui correspond au joueur du jeu
 */
struct joueur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct joueur_s joueur_t;


/**
 * \brief Type qui correspond aux murs du jeu
 */
struct mur_s{
	int x;
	int y;
	int h;
	int w;
};
typedef struct mur_s mur_t;

struct tab_s{
	mur_t *tab_mur[NB_MURS];
};
typedef struct tab_s tab_t;

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
* \brief initialise les données d'un mur
* \param m le mur
* \param a l'abscisse du mur
* \param b l'ordonnée du mur
* \param c la hauteur du mur
* \param d la largeur du mur
*/
void init_mur(mur_t* m,int a,int b,int c,int d);

/**
* \brief initialise l'ensemble de tous les murs
* \param murs le tableau de mur_t
*/
void init_murs(tab_t *murs);

/**
* \brief détecte les collisions avec le joueur et les murs
* \param j le joueur
* \param m le mur
* \return 1 s'il y a une collision
*/
int est_en_collision_mur(joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief détecte si le joueur se trouve sur un mur
* \param j le jouer
* \param m le mur 
* \return 1 si le joueur se trouve sur un mur
*/
int est_sur_mur(joueur_t* j,mur_t* m,int sens);

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_haut(textures_t* textures,SDL_Renderer* renderer,int sens);

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens);

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens);

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur 
* \return l'orientation du perso
*/
int saut(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens,tab_t *tab);

/**
* \brief fonction qui modifie les coordonnées de tous les murs en fonction des caractères du fichier
* \param nomfichier le fichier représentant le fond avec les murs
* \param tab le tableau de mur_t
*/
void lire_fichier_mur(const char* nomfichier,tab_t *murs);


/**
* \brief empêche les personnages de sortir de l'écran horizontalement
* \param j le personnage qui bouge 
*/
void limite_horizontale(joueur_t *j);
#endif

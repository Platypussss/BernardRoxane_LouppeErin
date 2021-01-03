#ifndef H_GAMEPLAY
#define H_GAMEPLAY

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.c"
#include "affichage.c"

#define DROIT_HAUT 1
#define GAUCHE_HAUT 2
#define SAUT_DROIT 3
#define ACCROUPIS_DROIT 4
#define ACCROUPIS_GAUCHE 5
#define SAUT_GAUCHE 6

/**
* \brief fonction qui applique toutes les textures
* \param textures la struct contenant toutes les textures
* \param renderer l'écran sur lequel on applique les textures
* \param joueur le joueur
* \param tab la struct avec les ennemis et les murs
*/
void apply_monde(textures_t *textures,SDL_Renderer *renderer,sprite_t *joueur, tab_t *tab);

/**
* \brief fonction qui initialise les données du jeu
* \param joueur le joueur
* \param tab la structure contenant les ennemis et les murs
*/
void init_jeu(sprite_t *joueur,tab_t *tab);

/**
* \brief fonction qui gère la perte de vie 
* \param sp1 le sprite qui pert une vie
*/
void perte_vie(sprite_t *sp1);

/**
* \brief détecte les collisions entre les sprites
* \param sp1 le sprite
* \param sp2 le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision(sprite_t* sp1,sprite_t* sp2);

/**
* \brief détecte les collisions entre les sprites
* \param sp1 le sprite
* \param sp2 le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision_arme(sprite_t *sp1, arme_t *sp2);

/**
* \brief fonction qui gère les collisions
* \param sp1 le sprite en potentiel collision
* \param tab le tableau de sprite en potentiel collision
*/
void gere_collision(sprite_t *sp1, tab_t *tab);

/**
* \brief fonction qui gère les collisions
* \param s le sprite 
* \param a le missile en potentiel collision
* \param tab le tableau de sprite en potentiel collision
*/
void gere_collision_arme(sprite_t *s, arme_t *a, tab_t *tab);

/**
* \brief détecte si le sprite se trouve sur un sprite
* \param j le jouer
* \param m le sprite 
* \return 1 si le sprite se trouve sur un sprite
*/
int est_sur_sprite(sprite_t* j,sprite_t* m,int sens);

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
*/
void bouger_haut(textures_t* textures,SDL_Renderer* renderer,sprite_t *sprite);

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
*/
void bouger_bas(textures_t* textures,SDL_Renderer* renderer,sprite_t *sprite);

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau en potentiel collision avec le sprite
*/
void bouger_gauche(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab);

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau en potentiel collision avec le sprite
*/
void bouger_droite(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab);


/**
* \brief bouge l'ennemi en fonction du joueur
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
*/
void bouger_ennemi(textures_t* textures, SDL_Renderer* renderer, sprite_t *sprite, tab_t* tab);

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau en potentiel collision avec le sprite
*/
void saut(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab);

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

/**
* \brief la fonction qui gere le lancement du missile
* \param s le sprite où on veut gérer le missile 
*/
void lancement_missile(sprite_t *s);

/**
* \brief le fonction qui gère le déplacement du missile
* \param s le sprite du missile à déplacer
*/
void gere_missile(sprite_t *s);

/**
* \brief la fonction qui gère les collisions du missile et des ennemis
* \param s le sprite en collision 
* \param tab la struct d'ennemis
*/
void gere_ennemi(sprite_t *s,tab_t *tab);

#endif

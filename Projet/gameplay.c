#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 640

/**
* \brief initialise les données du joueur
* \param j le joueur
* \param a l'abscisse du joueur
* \param b l'ordonnée du joueur
* \param c la hauteur du joueur
* \param d la largeur du joueur
*/
void init_joueur(joueur_t* j,int a,int b,int c,int d){
	j->x=a;
	j->y=b;
	j->h=c;
	j->w=d;
}

/**
* \brief initialise les données du mur
* \param m le mur
* \param a l'abscisse du mur
* \param b l'ordonnée du mur
* \param c la hauteur du mur
* \param d la largeur du mur
*/
void init_mur(mur_t* m, int a, int b,int c,int d){
	m->x=a;
	m->y=b;
	m->h=c;
	m->w=d;
}

/**
* \brief détecte les collisions avec le joueur et les murs
* \param j le joueur
* \param m le mur
* \return 1 quand c'est en collision
*/
int est_en_collision_mur(joueur_t* j,mur_t* m,int sens){
	int x=(j->x)+(j->w)/2;
	int x1=(m->x)-(m->w)/2;
	int x2=(j->x)-(j->w)/2;
	int x3=(m->x)-(m->w)/2;
	if(x2==x3 && sens==2){	//en collision avec le côté gauche du mur
		return 1;
	}
	if(x==x1 && sens==1){	//en collision avec le côté droit du mur
		return 1;
	}
	return 0;
}


/**
* \brief détecte si le joueur se trouve sur un mur
* \param j le jouer
* \param m le mur 
* \return 1 si le joueur se trouve sur un mur
*/
int est_sur_mur(joueur_t* joueur,mur_t* mur,int sens){
	int x_j=(joueur->x)+(joueur->w)/2;
	int x1_m=(mur->x)-(mur->w)/2;
	int x2_m=(mur->x)+(mur->w)/2;
	if(x1_m<=x_j && x2_m>=x_j){	//le joueur se trouve entre les extremités du mur
		return 1;
	}
	return 0;
}

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur 
*/
int bouger_haut(textures_t* textures, SDL_Renderer* renderer,int sens){
	int s;
	if(sens==1 || sens==4){
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}else{
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		s=2;
	}
	return s;
}

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur,permet de changer de sprite
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens){
	int s;
	if(sens==1 || sens==4){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		s=4;
	}else{
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		s=5;
	}
	return s;
}

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens){
	int s;
	joueur->x=(joueur->x)-5;
	if(sens==4 || sens==5){
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		s=5;
	}else{
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		s=2;
	}
	if(1==(est_en_collision_mur(joueur,mur,sens))){
		//est en collision, on ne bouge pas
		joueur->x=(joueur->x)+5;
	}
	if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
	}
	return s;
}

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens){
	int s;
	joueur->x=(joueur->x)+5;
	
	if(sens==4 || sens==5){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		s=4;
	}else{
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}	
	if(1==(est_en_collision_mur(joueur,mur,sens))){
		//est en collision, on ne bouge pas
		joueur->x=(joueur->x)-5;
	}
	if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
	}
	return s;
}


/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
*/
int saut(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,mur_t* mur,int sens){
	
	if(sens==1 || sens==4){		//saute vers la droite
		joueur->y=(joueur->y)-50;
		joueur->x=(joueur->x)+20;
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut.bmp",renderer);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,joueur->x,joueur->y);
		apply_texture(textures->murtoutseul,renderer,200,480);
		SDL_RenderPresent(renderer);
		SDL_Delay(200);
		
		if(1==est_sur_mur(joueur,mur,sens)){
			joueur->y=(joueur->y)-(mur->h)+60;
		}else if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
		}else{
			joueur->y=(joueur->y)+50;
		}
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
	}else{		//saute vers la gauche
		joueur->y=(joueur->y)-50;
		joueur->x=(joueur->x)-20;
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut_envers.bmp",renderer);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,joueur->x,joueur->y);
		apply_texture(textures->murtoutseul,renderer,mur->x,mur->y);
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		if(1==est_sur_mur(joueur,mur,sens)){
			joueur->y=(joueur->y)-(mur->h)+60;
		}else if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
		}else{
			joueur->y=(joueur->y)+50;
		}
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
	}
	return 3;
}

/**ne pas changer la hauteur quand on saute sur le mur
ajuster les valeurs des x et y*/

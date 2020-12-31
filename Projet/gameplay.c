#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

/**
* \brief détecte les collisions avec le joueur et les murs
* \param j le joueur
* \param m le mur
* \return 1 s'il y a une collision
*/
int est_en_collision(joueur_t* j,mur_t* m,int sens){
	int x=(j->x)+(j->w)/2;
	int x1=(m->x)-(m->w)/2;
	int x2=(j->x)-(j->w)/2;
	int x3=(m->x)-(m->w)/2;
	if((j->y)-(j->h)<=(m->y)-(m->h)){
		if(x2==x3 && (sens==2 || sens==5)){	//en collision avec le côté gauche du mur
			return 1;
		}
		if(x==x1 && (sens==1 || sens==4)){	//en collision avec le côté droit du mur
			return 1;
		}
	}
	return 0;
}


/**
* \brief détecte si le joueur se trouve sur un mur
* \param j le jouer
* \param m le mur 
* \return 1 si le joueur se trouve sur un mur
*/
int est_sur_mur(joueur_t* joueur,mur_t* mur){
	
	return 0;
}

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du joueur 
* \return l'orientation du perso
*/
int bouger_haut(textures_t* textures, SDL_Renderer* renderer,int sens,joueur_t *joueur){
	int s;
	if(sens==1 || sens==4){
		if(sens ==4){
			joueur->h=(joueur->h)*2;
		}
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}else{
		if(sens ==5){
			joueur->h=(joueur->h)*2;
		}
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
* \return l'orientation du perso
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens,joueur_t *joueur){
	int s;
	joueur->h=(joueur->h)/2;
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
* \param tab le tableau de mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,tab_t *tab,int sens){
	int s;
	joueur->x=(joueur->x)-5;
	if(sens==4 || sens==5){	//changement de l'orientation du perso
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		s=5;
	}else{
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		s=2;
	}
	//test de collision avec tous les murs
	for(int i=0;i<NB_MURS;i++){
		if(1==(est_en_collision(joueur,tab->tab_mur[i],sens))){
			//est en collision, on ne bouge pas
			joueur->x=(joueur->x)+5;
		}
		if(0==est_sur_mur(joueur,tab->tab_mur[i])){
				joueur->y=425;
		}
	}
	
	limite_horizontale(joueur);
	return s;
}

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param tab le tableau de mur en potentiel collision avec le joueur
* \param sens du joueur,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,tab_t *tab,int sens){
	int s;
	joueur->x=(joueur->x)+5;
	
	if(sens==4 || sens==5){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		s=4;
	}else{
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}	
	for(int i=0;i<NB_MURS;i++){
		if(1==(est_en_collision(joueur,tab->tab_mur[i],sens))){
			//est en collision, on ne bouge pas
			joueur->x=(joueur->x)-5;
		}
		if(0==est_sur_mur(joueur,tab->tab_mur[i])){
				joueur->y=425;
		}
	}
	limite_horizontale(joueur);
	return s;
}


/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param joueur le joueur qui bouge
* \param sens du joueur,permet de changer de sprite 
*\param tab le tableau de mur en potentiel collision avec le joueur
* \return l'orientation du perso
*/
int saut(textures_t* textures,SDL_Renderer* renderer,joueur_t* joueur,int sens,tab_t *tab){

	if(sens==1 || sens==4){		//saute vers la droite
		joueur->y=(joueur->y)-50;
		joueur->x=(joueur->x)+20;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,joueur->x,joueur->y);
		for(int i=0;i<NB_MURS;i++){	
			apply_texture(textures->murtoutseul,renderer,tab->tab_mur[i]->x,tab->tab_mur[i]->y);
		}
		for(int i=0;i<NB_ENNEMIS;i++){	
			apply_texture(textures->ennemi,renderer,tab->tab_ennemi[i]->x,tab->tab_ennemi[i]->y);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		for(int i=0;i<NB_MURS;i++){
			if(1==est_sur_mur(joueur,tab->tab_mur[i])){
					joueur->y=20;
					//joueur->y=(joueur->y)+(tab->tab_mur[i]->h);
					//joueur->y=(tab->tab_mur[i]->y)-(tab->tab_mur[i]->h);
			}else{
				joueur->y=425;
			}
		}	
		/*if(1==est_sur_mur(joueur,mur,sens)){
			joueur->y=(joueur->y)-(mur->h)+60;
		}else if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
		}else{
			joueur->y=(joueur->y)+50;
		}*/
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
	}else{		//saute vers la gauche
		joueur->y=(joueur->y)-50;
		joueur->x=(joueur->x)-20;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut_envers.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,joueur->x,joueur->y);
		for(int i=0;i<NB_MURS;i++){	
			apply_texture(textures->murtoutseul,renderer,tab->tab_mur[i]->x,tab->tab_mur[i]->y);
		}
		for(int i=0;i<NB_ENNEMIS;i++){	
			apply_texture(textures->ennemi,renderer,tab->tab_ennemi[i]->x,tab->tab_ennemi[i]->y);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		for(int i=0;i<NB_MURS;i++){
			if(1==est_sur_mur(joueur,tab->tab_mur[i])){
					joueur->y=20;
					//joueur->y=(joueur->y)+(tab->tab_mur[i]->h);
					//joueur->y=(tab->tab_mur[i]->y)-(tab->tab_mur[i]->h);
			}else{
				joueur->y=425;
			}
		}
		/*if(1==est_sur_mur(joueur,mur,sens)){
			joueur->y=(joueur->y)-(mur->h)+60;
		}else if(0==est_sur_mur(joueur,mur,sens)){
			joueur->y=425;
		}else{
			joueur->y=(joueur->y)+50;
		}*/
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
	}
	limite_horizontale(joueur);
	return 3;
}

/**
* \brief fonction qui modifie les coordonnées de tous les murs et ennemis en fonction des caractères du fichier
* \param nomfichier le fichier représentant le fond avec les murs
* \param tab le tableau de mur_t
*/
void lire_fichier(const char* nomfichier,tab_t *tab){
	FILE* file;
	file=fopen(nomfichier,"r");
	int i=0;
	int j=0;
	int a=0;	//correspond aux abscisses 
	int b=0;	//correspond aux ordonnées
	char c;
	while((c=fgetc(file))!=EOF){	//pas à la fin du fichier
			if(c=='\n'){
				b=b+50;	//change de ligne
				a=0;	//revient au début de la ligne, les x valent 0
			}				
			if(c=='m'){ 	//m correspond à un mur
				//mets les coordonnées du mur en fonction de la position du 'm' dans le fichier
				tab->tab_mur[i]->x=a;
				tab->tab_mur[i]->y=b;
				i++;	
			}
			if(c=='e'){ 	//e correspond à un ennemi
				//mets les coordonnées de l'ennemi en fonction de la position du 'e' dans le fichier
				tab->tab_ennemi[j]->x=a;
				tab->tab_ennemi[j]->y=b;
				j++;	
			}
			a=a+50;	
	}
	fclose(file);	
}


/**
* \brief empêche les personnages de sortir de l'écran horizontalement
* \param j le personnage qui bouge 
*/
void limite_horizontale(joueur_t *j){
	if(j->x<0){
		j->x=0;
	}
	if(j->x>SCREEN_WIDTH-(j->w)){
		j->x=SCREEN_WIDTH-(j->w);
	}
}


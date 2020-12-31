#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

/**
* \brief détecte les collisions avec le sprite et les ennemis
* \param j le sprite
* \param e le sprite
* \return 1 s'il y a une collision
*/
/*int est_en_collision_ennemi(sprite_t* j,ennemi_t* e,int sens){
	int x=(j->x)+(j->w)/2;
	int x1=(e->x)-(e->w)/2;
	int x2=(j->x)-(j->w)/2;
	int x3=(e->x)-(e->w)/2;
	if((j->y)-(j->h)<=(e->y)-(e->h)){
		if(x2==x3 && (sens==2 || sens==5)){	//en collision avec le côté gauche de l'ennemi
			return 1;
		}
		if(x==x1 && (sens==1 || sens==4)){	//en collision avec le côté droit de l'ennemi
			return 1;
		}
	}
	return 0;
}*/

/**
* \brief détecte les collisions avec le sprite et les murs
* \param j le sprite
* \param m le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision(sprite_t* j,sprite_t* m,int sens){
	int x=(j->x)+(j->w)/2;	//x du coté droit du sprite
	int x1=(m->x)-(m->w)/2;	//x du coté gauche du sprite
	int x2=(j->x)-(j->w)/2;	//x du coté gauche du sprite
	int x3=(m->x)-(m->w)/2;	//x du coté droit du sprite
	if((j->y)-(j->h)<=(m->y)-(m->h)){
		if(x2==x3 && (sens==2 || sens==5)){	//en collision avec le côté droit du sprite
			return 1;
		}
		if(x==x1 && (sens==1 || sens==4)){	//en collision avec le côté gauche du sprite
			return 1;
		}
		
		//pour le saut:
		//le perso se trouve entre les deux extremités
		if(x>x1 && x<x3+(m->w)/2){	
			return 1;
		}
		if(x2<x3 && x2>x1-(m->w)/2){
			return 1;
		}
	}
	/*int d=((m->x)-(j->y))*((m->x)-(j->x))+((m->y)-(j->y))*((m->y)-(j->y));	//distannce entre les centres des 2 objets
	int r=((j->w)/2 - (m->h)/2)*((j->w)/2 - (m->h)/2);	//distance max de collision
	if(d<r){	//en collision
		return 1;
	}*/
	return 0;
}


/**
* \brief détecte si le sprite se trouve sur un sprite
* \param j le jouer
* \param m le sprite 
* \return 1 si le sprite se trouve sur un sprite
*/
/*int est_sur_mur(sprite_t* sprite,mur_t* sprite,int sens){
	int y_j=sprite->y;
	int y_m=sprite->y;
	if(1==est_en_collision(sprite,sprite,sens) && y_j<=y_m && y_j>y_m-sprite->h){
		return 1;
	}
	return 0;
}*/

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sens du sprite 
* \return l'orientation du perso
*/
int bouger_haut(textures_t* textures, SDL_Renderer* renderer,int sens,sprite_t *sprite){
	int s;
	if(sens==1 || sens==4){
		if(sens ==4){
			sprite->h=(sprite->h)*2;
		}
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}else{
		if(sens ==5){
			sprite->h=(sprite->h)*2;
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
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_bas(textures_t* textures,SDL_Renderer* renderer,int sens,sprite_t *sprite){
	int s;
	sprite->h=(sprite->h)/2;
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
* \param sprite le sprite qui bouge
* \param tab le tableau de sprite en potentiel collision avec le sprite
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_gauche(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab,int sens){
	int s;
	sprite->x=(sprite->x)-5;
	if(sens==4 || sens==5){	//changement de l'orientation du perso
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		s=5;
	}else{
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		s=2;
	}
	//test de collision avec tous les murs
	for(int i=0;i<NB_MURS;i++){
		if(1==(est_en_collision(sprite,tab->tab_mur[i],sens))){
			//est en collision, on ne bouge pas
			sprite->x=(sprite->x)+5;
		}
		/*if(0==est_sur_mur(sprite,tab->tab_mur[i],sens)){
				sprite->y=425;
		}*/
	}
	
	limite_horizontale(sprite);
	return s;
}

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau de sprite en potentiel collision avec le sprite
* \param sens du sprite,permet de changer de sprite
* \return l'orientation du perso
*/
int bouger_droite(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab,int sens){
	int s;
	sprite->x=(sprite->x)+5;
	
	if(sens==4 || sens==5){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		s=4;
	}else{
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		s=1;
	}	
	for(int i=0;i<NB_MURS;i++){
		if(1==(est_en_collision(sprite,tab->tab_mur[i],sens))){
			//est en collision, on ne bouge pas
			sprite->x=(sprite->x)-5;
		}
		/*if(0==est_sur_mur(sprite,tab->tab_mur[i],sens)){
				sprite->y=425;
		}*/
	}
	limite_horizontale(sprite);
	return s;
}


/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param sens du sprite,permet de changer de sprite 
*\param tab le tableau de sprite en potentiel collision avec le sprite
* \return l'orientation du perso
*/
int saut(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,int sens,tab_t *tab){
	int y_base=sprite->y;
	if(sens==1 || sens==4){		//saute vers la droite
		sprite->y=(sprite->y)-100;
		sprite->x=(sprite->x)+20;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,sprite->x,sprite->y);
		for(int i=0;i<NB_MURS;i++){	
			apply_texture(textures->murtoutseul,renderer,tab->tab_mur[i]->x,tab->tab_mur[i]->y);
		}
		for(int i=0;i<NB_ENNEMIS;i++){	
			apply_texture(textures->ennemi,renderer,tab->tab_ennemi[i]->x,tab->tab_ennemi[i]->y);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		for(int i=0;i<NB_MURS;i++){
			/*if(1==est_sur_mur(sprite,tab->tab_mur[i],sens)){
					sprite->y=(tab->tab_mur[i]->y)-(sprite->h);
			}else{
				
			}*/
			if(1==(est_en_collision(sprite,tab->tab_mur[i],sens))){
					//est en collision, on ne bouge pas
					sprite->x=(sprite->x)-20;
					sprite->y=(sprite->y)+100;
				}
		}	
		textures->perso=charger_image("ressources/marche1.bmp",renderer);

	}else{		//saute vers la gauche

		sprite->y=(sprite->y)-100;
		sprite->x=(sprite->x)-20;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut_envers.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_texture(textures->perso,renderer,sprite->x,sprite->y);
		for(int i=0;i<NB_MURS;i++){	
			apply_texture(textures->murtoutseul,renderer,tab->tab_mur[i]->x,tab->tab_mur[i]->y);
		}
		for(int i=0;i<NB_ENNEMIS;i++){	
			apply_texture(textures->ennemi,renderer,tab->tab_ennemi[i]->x,tab->tab_ennemi[i]->y);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		for(int i=0;i<NB_MURS;i++){
			/*if(1==est_sur_mur(sprite,tab->tab_mur[i],sens)){
					sprite->y=(tab->tab_mur[i]->y)-(sprite->h);
			}else{
				
			}*/	
			if(1==(est_en_collision(sprite,tab->tab_mur[i],sens))){
				//est en collision, on ne bouge pas
				sprite->x=(sprite->x)+20;
				sprite->y=(sprite->y)+100;
			}
		}
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
	}
	sprite->y=y_base;
	limite_horizontale(sprite);
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
			if(c=='m'){ 	//m correspond à un sprite
				//mets les coordonnées du sprite en fonction de la position du 'm' dans le fichier
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
void limite_horizontale(sprite_t *j){
	if(j->x<0){
		j->x=0;
	}
	if(j->x>SCREEN_WIDTH-(j->w)){
		j->x=SCREEN_WIDTH-(j->w);
	}
}


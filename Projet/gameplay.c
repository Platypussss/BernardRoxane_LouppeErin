#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

/**
* \brief fonction qui applique toutes les textures
* \param textures la struct contenant toutes les textures
* \param renderer l'écran sur lequel on applique les textures
* \param joueur le joueur
* \param tab la struct avec les ennemis et les murs
*/
void apply_monde(textures_t *textures,SDL_Renderer *renderer, sprite_t *joueur, tab_t *tab){
	if(get_est_visible(joueur)==0){	//le joueur est visible
		apply_texture(textures->perso,renderer,joueur->x,joueur->y);
	}	
	if(get_est_visible_arme(joueur->missile)==0){	//le missile du joueur est visible
		apply_texture(textures->arme,renderer,joueur->missile->x,joueur->missile->y);
	}
	for(int i=0;i<NB_MURS;i++){	
		apply_texture(textures->murtoutseul,renderer,tab->tab_mur[i]->x,tab->tab_mur[i]->y);
	}
	for(int i=0;i<NB_ENNEMIS;i++){	
		if(get_est_visible(tab->tab_ennemi[i])==0){	//les ennemis sont visibles
			apply_texture(textures->ennemi,renderer,tab->tab_ennemi[i]->x,tab->tab_ennemi[i]->y);
		}	
		if(get_est_visible_arme(joueur->missile)==0){	//le missile de l'ennemi est visible
		apply_texture(textures->arme,renderer,tab->tab_ennemi[i]->missile->x,tab->tab_ennemi[i]->missile->y);
		}
	}
}

/**
* \brief fonction qui initialise les données du jeu
* \param joueur le joueur
* \param tab la structure contenant les ennemis et les murs
*/
void init_jeu(sprite_t *joueur,tab_t *tab){
	init_sprite(joueur,0,425,100,100,DROIT_HAUT,5,0);
	init_map(tab);
	lire_fichier("file.txt",tab);	//modifie les coordonnées des murs en fonction du fichier txt*/
}

/**
* \brief fonction qui gère la perte de vie 
* \param sp1 le sprite qui pert une vie
*/
void perte_vie(sprite_t *sp1){
	sp1->vie=(sp1->vie)-1;
}

/**
* \brief détecte les collisions avec le sprite et les murs
* \param j le sprite
* \param m le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision(sprite_t* sp1,sprite_t* sp2){
	if(get_est_visible(sp1)==0 && get_est_visible(sp2)==0){
		if(((sp1->x)-(sp2->x))*((sp1->x)-(sp2->x))+(((sp1->y)-(sp2->y))*((sp1->y)-(sp2->y)))<((sp1->h)*(sp1->h))){
			return 1; //les sprites sont en collision
		}
	}
	return 0;	//les sprites ne sont pas en collision
}

/**
* \brief détecte les collisions entre les sprites
* \param sp1 le sprite
* \param sp2 le sprite
* \return 1 s'il y a une collision
*/
int est_en_collision_arme(sprite_t *sp1, arme_t *sp2){
	if(get_est_visible(sp1)==0 && get_est_visible_arme(sp2)==0){
		if(((sp1->x)-(sp2->x))*((sp1->x)-(sp2->x))+(((sp1->y)-(sp2->y))*((sp1->y)-(sp2->y)))<((sp1->h)*(sp1->h))){
			return 1; //les sprites sont en collision
		}
	}
	return 0;	//les sprites ne sont pas en collision
}

/**
* \brief fonction qui gère les collisions
* \param s le sprite 
* \param a le missile en potentiel collision
* \param tab le tableau de sprite en potentiel collision
*/
void gere_collision_arme(sprite_t *s, arme_t *a, tab_t *tab){
	for(int i=0;i<NB_MURS;i++){
		if(1==est_en_collision_arme(tab->tab_mur[i],a)){	//missile et un mur en collision
			set_est_visible_arme(a,1);
			a->x=s->x;	//le missile revient au joueur
			a->y=(s->y)+(s->h)/2;
		}
	}	
	for(int i=0;i<NB_ENNEMIS;i++){
		if(1==est_en_collision_arme(tab->tab_ennemi[i],a)){	//missile et un ennemi en collision
			set_est_visible_arme(a,1);
			a->x=s->x;	//le missile revient au joueur
			a->y=(s->y)+(s->h)/2;
			perte_vie(tab->tab_ennemi[i]);	//l'ennemi perd une vie
		}
	}
}

/**
* \brief fonction qui gère les collisions
* \param sp1 le sprite en potentiel collision
* \param tab le tableau de sprite en potentiel collision
*/
void gere_collision(sprite_t *sp1, tab_t *tab){
		int x_en_moins=0;
		int y_en_moins=0;
		if(sp1->sens==DROIT_HAUT || sp1->sens==ACCROUPIS_DROIT){
			x_en_moins=-10;
		}
		if(sp1->sens==GAUCHE_HAUT || sp1->sens==ACCROUPIS_GAUCHE){
			x_en_moins=+10;
		}
		if(sp1->sens==SAUT_DROIT){
			x_en_moins=-200;
			y_en_moins=200;
		}
		if(sp1->sens==SAUT_GAUCHE){
			x_en_moins=200;
			y_en_moins=200;
		}
		for(int i=0;i<NB_MURS;i++){
			if(1==(est_en_collision(sp1,tab->tab_mur[i]))){
				//est en collision, on ne bouge pas
				sp1->x=(sp1->x)+x_en_moins;
				sp1->y=(sp1->y)+y_en_moins;
			}
		}
		for(int i=0;i<NB_ENNEMIS;i++){
			if(1==(est_en_collision(sp1,tab->tab_ennemi[i]))){
				//est en collision, on recule un petit peu et on perd une vie
				sp1->x=(sp1->x)+x_en_moins+x_en_moins;
				sp1->y=(sp1->y)+y_en_moins;
				perte_vie(sp1);
			}
		}
}

/**
* \brief détecte si le sprite se trouve sur un sprite
* \param sp1 un sprite
* \param sp2 un sprite 
* \return 1 si le sprite se trouve sur un sprite
*/
int est_sur_sprite(sprite_t* sp1,sprite_t* sp2){
	if(est_en_collision(sp1,sp2)==1 && sp1->h>sp2->h){
		return 1;
	}
	return 0;
}

/**
* \brief bouge le perso vers le haut
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
*/
void bouger_haut(textures_t* textures, SDL_Renderer* renderer,sprite_t *sprite,tab_t *tab){
	
	if(sprite->sens==DROIT_HAUT || sprite->sens==ACCROUPIS_DROIT || sprite->sens==SAUT_DROIT){
		if(sprite->sens ==ACCROUPIS_DROIT){
			sprite->h=(sprite->h)*2;
		}
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		sprite->sens=DROIT_HAUT;
	}else{
		if(sprite->sens ==ACCROUPIS_GAUCHE){
			sprite->h=(sprite->h)*2;
		}
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		sprite->sens=GAUCHE_HAUT;
	}
	gere_collision(sprite,tab);
}

/**
* \brief bouge le perso vers le bas
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
*/
void bouger_bas(textures_t* textures,SDL_Renderer* renderer,sprite_t *sprite){
	
	sprite->h=(sprite->h)/2;
	if(sprite->sens==DROIT_HAUT || sprite->sens==ACCROUPIS_DROIT || sprite->sens==SAUT_DROIT){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		sprite->sens=ACCROUPIS_DROIT;
	}else{
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		sprite->sens=ACCROUPIS_GAUCHE;
	}
}

/**
* \brief bouge le perso vers la gauche
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau de sprite en potentiel collision avec le sprite
*/
void bouger_gauche(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab){
	
	sprite->x=(sprite->x)-5;
	if(sprite->sens==ACCROUPIS_DROIT || sprite->sens==ACCROUPIS_GAUCHE){	//changement de l'orientation du perso
		textures->perso=charger_image("ressources/accroupis_envers.bmp",renderer);
		sprite->sens=ACCROUPIS_GAUCHE;
	}else{
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
		sprite->sens=GAUCHE_HAUT;
	}
	gere_collision(sprite,tab);
	limite_horizontale(sprite);
}

/**
* \brief bouge le perso vers la droite
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau de sprite en potentiel collision avec le sprite
*/
void bouger_droite(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab){
	
	sprite->x=(sprite->x)+5;
	
	if(sprite->sens==ACCROUPIS_DROIT || sprite->sens==ACCROUPIS_GAUCHE){
		textures->perso=charger_image("ressources/accroupis.bmp",renderer);
		sprite->sens=ACCROUPIS_DROIT;
	}else{
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
		sprite->sens=DROIT_HAUT;
	}
	gere_collision(sprite,tab);
	limite_horizontale(sprite);
}

/**
* \brief bouge l'ennemi en fonction du joueur
* \param sprite le joueur
* \param tab les ennemis
*/
void bouger_ennemi(sprite_t *sprite, tab_t* tab){
	for(int i=0;i<NB_ENNEMIS;i++){
			if(sprite->x < (tab->tab_ennemi[i]->x)+300){
				if(sprite->x < tab->tab_ennemi[i]->x){
					tab->tab_ennemi[i]->x=(tab->tab_ennemi[i]->x)-2;
					if(sprite->x == tab->tab_ennemi[i]->x){
						perte_vie(sprite);
					}
				}
				if(sprite->x > tab->tab_ennemi[i]->x){
					tab->tab_ennemi[i]->x=(tab->tab_ennemi[i]->x)+2;
					if(sprite->x == tab->tab_ennemi[i]->x){
						perte_vie(sprite);
					}
				}
			}
	}
}

/**
* \brief fait sauter le perso
* \param textures les textures du jeu
* \param renderer la surface correspondant à la surface du jeu
* \param sprite le sprite qui bouge
* \param tab le tableau de sprite en potentiel collision avec le sprite
*/
void saut(textures_t* textures,SDL_Renderer* renderer,sprite_t* sprite,tab_t *tab){
	
	int y_base=sprite->y;
	if(sprite->sens==DROIT_HAUT || sprite->sens==ACCROUPIS_DROIT || sprite->sens==SAUT_DROIT){	//saute vers la droite
		sprite->y=(sprite->y)-200;
		sprite->x=(sprite->x)+200;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_monde(textures,renderer,sprite,tab);
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		sprite->sens=SAUT_DROIT;
		gere_collision(sprite,tab);
		sprite->y=y_base;
		textures->perso=charger_image("ressources/marche1.bmp",renderer);
	}else{		//saute vers la gauche

		sprite->y=(sprite->y)-200;
		sprite->x=(sprite->x)-200;

		//change l'apparence du perso
		textures->murtoutseul=charger_image("ressources/murtoutseul.bmp",renderer);
		textures->perso=charger_image("ressources/saut_envers.bmp",renderer);

		//applique la nouvelle texture à l'écran
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,textures->fond,NULL,NULL);
		apply_monde(textures,renderer,sprite,tab);
		SDL_RenderPresent(renderer);
		SDL_Delay(200);

		sprite->sens=SAUT_GAUCHE;
		gere_collision(sprite,tab);
		sprite->y=y_base;
		textures->perso=charger_image("ressources/marche1_envers.bmp",renderer);
	}
	
	limite_horizontale(sprite);
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
				tab->tab_ennemi[j]->est_visible=0;
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


/**
* \brief fonction que dit si le jeu est fini
* \param j le joueur, vérifie qu'il a encore de la vie
* \param tab les ennemis, vérifie leur vie
* \return true si le joueur n'a plus de vie ou si tout les ennemis n'ont plus de vie, flase sinon
*/
bool jeu_fini(sprite_t *j,tab_t *tab){
	int nb=0;
	if(j->vie==-1){	//le joueur n'a plus de vie
		return true;
	}
	for(int i=0;i<NB_ENNEMIS;i++){
		if(get_est_visible(tab->tab_ennemi[i])==1){	//le nb d'ennemis invisibles
			nb++;
		}	
	}
	if(nb==NB_ENNEMIS){	//tous les ennemis sont invisibles donc morts
		return true;
	}
	return false;
}

/**
* \brief la fonction qui gere le missile
* \param s le sprite où on veut gérer le missile 
*/
void lancement_missile(sprite_t *s){
	set_est_visible_arme(s->missile,0);	//le missile devient visible
}

/**
* \brief le fonction qui gère le déplacement du missile
* \param s le sprite du missile à déplacer
*/
void gere_missile(sprite_t *s){
	if((s->missile->x<0 || s->missile->x>SCREEN_WIDTH)){
		//le missile à dépasser les bords, il devient invisible
		set_est_visible_arme(s->missile,1);
		s->missile->x=s->x;	//revient au niveau du joueur
		
	}else{	//le missile ne dépasse pas les bords
		
		if(get_est_visible_arme(s->missile)==0 && get_est_visible(s)==0){
			if(s->sens==DROIT_HAUT || s->sens==ACCROUPIS_DROIT || s->sens==SAUT_DROIT){
				//le missile part vers la droite
				s->missile->x=(s->missile->x)+(s->missile->v);
			}else{
				//le missile part vers la gauche
				s->missile->x=(s->missile->x)-(s->missile->v);
			}	
		}	
	}
}

/**
* \brief la fonction qui gère les collisions du missile et des ennemis
* \param s le sprite en collision 
* \param tab la struct d'ennemis
*/
void gere_ennemi(sprite_t *s,tab_t *tab){
	for(int i=0;i<NB_ENNEMIS;i++){
		if(get_est_visible(tab->tab_ennemi[i])==0 && get_est_visible_arme(s->missile)==0){
			gere_collision_arme(s,s->missile,tab);
		}
		if(tab->tab_ennemi[i]->vie<0){
			tab->tab_ennemi[i]->est_visible=1;
		}
	}
}
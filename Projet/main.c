#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.c"

int main(int argc, char *argv[]){
	SDL_Window* fenetre;  // Déclaration de la fenêtre
	SDL_Event evenements; // Événements liés à la fenêtre
	bool terminer = false;
	if(SDL_Init(SDL_INIT_VIDEO) < 0){ // Initialisation de la SDL
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	// Créer la fenêtre
	fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if(fenetre == NULL){ // En cas d’erreur
		printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());SDL_Quit();
		return EXIT_FAILURE;
	}
	
	//Mettre en place un contexte de rendu de l'écran
	SDL_Renderer* ecran;

	ecran=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);

	init_ttf();

	textures_t textures;
	init_textures(ecran,&textures);
	
	SDL_Color color={100,100,100,0};
	char msg[]="La partie commence";
	char c[20];
	char d[]="Vous avez perdu !";
	char e[]="Vous avez gagne !";
	SDL_Texture *texte=charger_texte(ecran,msg,textures.ecriture,color);
	SDL_Rect text_pos; // Position du texte
	text_pos.x = SCREEN_WIDTH/4;
	text_pos.y =SCREEN_HEIGHT/2;
	text_pos.w=500;
	text_pos.h=100;
	
	//initialisation
	sprite_t joueur;
	tab_t tab;
	
	//affichage du début de la partie
	init_jeu(&joueur,&tab);
	SDL_RenderClear(ecran);
	SDL_RenderCopy(ecran,textures.fond,NULL,NULL);
	SDL_RenderCopy(ecran,texte,NULL,&text_pos);
	SDL_RenderPresent(ecran);
	SDL_Delay(1000);

	text_pos.x = 10;
	text_pos.y =10;
	text_pos.w=50;
	text_pos.h=50;
	// Boucle principale
	while(!terminer){
		sprintf(c,"vie: %d",joueur.vie);
		SDL_Texture *v=charger_texte(ecran,c,textures.ecriture,color);
		//appliquer les textures sur l'écran
		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,textures.fond,NULL,NULL);
		SDL_RenderCopy(ecran,v,NULL,&text_pos);	//affichage de la vie du joueur
		apply_monde(&textures,ecran,&joueur,&tab);
		SDL_RenderPresent(ecran);
		
		//boucle qui gère les évenements
		while( SDL_PollEvent(&evenements))
			switch(evenements.type){
				case SDL_QUIT:
					terminer = true; 
					break;
				//évenements clavier
				case SDL_KEYDOWN:
				switch(evenements.key.keysym.sym){
					case SDLK_q:
						terminer = true;  
						break;
					case SDLK_UP:
						bouger_haut(&textures,ecran,&joueur,&tab);
						bouger_ennemi(&joueur,&tab);
						break;
					case SDLK_DOWN:
						bouger_bas(&textures,ecran,&joueur);
						bouger_ennemi(&joueur,&tab);
						break;
					case SDLK_LEFT:
						bouger_gauche(&textures,ecran,&joueur,&tab);
						bouger_ennemi(&joueur,&tab);
						break;
					case SDLK_RIGHT:
						bouger_droite(&textures,ecran,&joueur,&tab);
						bouger_ennemi(&joueur,&tab);
						break;
					case SDLK_SPACE:
						saut(&textures,ecran,&joueur,&tab);
						bouger_ennemi(&joueur,&tab);
						break;
				}
				//évenements souris
				case SDL_MOUSEBUTTONDOWN:
				switch(evenements.button.button){
					case SDL_BUTTON_LEFT:
						lancement_missile(&joueur);
						break;
					}
				if(jeu_fini(&joueur,&tab)){
					if(joueur.vie==-1){	//le jeu est fini et le perso est mort
						SDL_Texture *perdu=charger_texte(ecran,d,textures.ecriture,color);
						SDL_Rect text_pos; // Position du texte
						text_pos.x = SCREEN_WIDTH/4;
						text_pos.y = SCREEN_HEIGHT/2;
						text_pos.w=500;
						text_pos.h=100;
						SDL_RenderCopy(ecran,perdu,NULL,&text_pos);
						SDL_RenderPresent(ecran);
						SDL_Delay(2000);
						terminer=true;
					}else{	//le jeu est fini et les ennemis sont morts
						SDL_Texture *gagne=charger_texte(ecran,e,textures.ecriture,color);
						SDL_Rect text_pos; // Position du texte
						text_pos.x = SCREEN_WIDTH/4;
						text_pos.y = SCREEN_HEIGHT/2;
						text_pos.w=500;
						text_pos.h=100;
						SDL_RenderCopy(ecran,gagne,NULL,&text_pos);
						SDL_RenderPresent(ecran);
						SDL_Delay(2000);
						terminer=true;
					}
				}
			}	
		gere_missile(&joueur);
		gere_ennemi(&joueur,&tab);
	}
	//Libérer de la mémoire
	clean_sprite(&joueur);
	clean_map(&tab);
	SDL_DestroyTexture(textures.fond);
	SDL_DestroyRenderer(ecran);
	clean_font(textures.ecriture);
	
	// Ferme tout
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	TTF_Quit();
	return 0;
}

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
	
	//Charger l'image
	textures_t textures;
	init_textures(ecran,&textures);
	
	//initialisation
	sprite_t joueur;
	tab_t tab;
	init_jeu(&joueur,&tab);
	
	
	// Boucle principale
	while(!terminer){
		
		//appliquer les textures sur l'écran
		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,textures.fond,NULL,NULL);
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
						bouger_haut(&textures,ecran,&joueur);
						break;
					case SDLK_DOWN:
						bouger_bas(&textures,ecran,&joueur);
						break;
					case SDLK_LEFT:
						bouger_gauche(&textures,ecran,&joueur,&tab);
						break;
					case SDLK_RIGHT:
						bouger_droite(&textures,ecran,&joueur,&tab);
						break;
					case SDLK_SPACE:
						saut(&textures,ecran,&joueur,&tab);
						break;
				}
				//évenements souris
				case SDL_MOUSEBUTTONDOWN:
				switch(evenements.button.button){
					case SDL_BUTTON_LEFT:
						lancement_missile(&joueur);
						break;
					}
				terminer=jeu_fini(&joueur,&tab);
			}
		gere_missile(&joueur);
	}
	//Libérer de la mémoire
	clean_sprite(&joueur);
	clean_map(&tab);
	SDL_DestroyTexture(textures.fond);
	SDL_DestroyRenderer(ecran);

	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}

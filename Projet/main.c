#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "affichage.c"
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
	fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
	if(fenetre == NULL){ // En cas d’erreur
		printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());SDL_Quit();
		return EXIT_FAILURE;
	}
	
	//Mettre en place un contexte de rendu de l'écran
	SDL_Renderer* ecran;
	ecran=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
	
	//Charger l'image
	textures_t textures;
	textures.fond=charger_image("ressources/fond1.bmp",ecran);
	textures.perso=charger_image("ressources/marche1.bmp",ecran);
	textures.murtoutseul=charger_image("ressources/murtoutseul.bmp",ecran);
	
	
	joueur_t joueur;
	init_joueur(&joueur,0,425,100,100);

	mur_t mur;
	init_mur(&mur,200,480,50,50);


	int tmp=1;
	int sens=tmp;//1 droite,2 gauche,3 saut,4 bas*/
	
	// Boucle principale
	while(!terminer){
		
		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,textures.fond,NULL,NULL);
		apply_texture(textures.perso,ecran,joueur.x,joueur.y);
		apply_texture(textures.murtoutseul,ecran,200,480);
		SDL_RenderPresent(ecran);
		sens=tmp;
		while( SDL_PollEvent(&evenements ) )
		switch(evenements.type){
			case SDL_QUIT:
				terminer = true; 
				break;
			case SDL_KEYDOWN:
			switch(evenements.key.keysym.sym){
				case SDLK_q:
					terminer = true;  
					break;
				case SDLK_UP:
					sens=bouger_haut(&textures,ecran,sens);
					tmp=sens;
					break;
				case SDLK_DOWN:
					sens=bouger_bas(&textures,ecran,sens);
					tmp=sens;
					break;
				case SDLK_LEFT:
					sens=bouger_gauche(&textures,ecran,&joueur,&mur,sens);
					tmp=sens;
					break;
				case SDLK_RIGHT:
					sens=bouger_droite(&textures,ecran,&joueur,&mur,sens);
					tmp=sens;
					break;
				case SDLK_SPACE:
					tmp=sens;
					sens=saut(&textures,ecran,&joueur,&mur,sens);
					break;
			}
		}
	}
	//Libérer de la mémoire
	SDL_DestroyTexture(textures.fond);
	SDL_DestroyRenderer(ecran);
	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}

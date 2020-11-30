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
	SDL_Texture* fond=charger_image("ressources/fond1.bmp",ecran);
	SDL_Texture* perso=charger_image("ressources/marche1.bmp",ecran);
	SDL_Texture* murtoutseul=charger_image("ressources/murtoutseul.bmp",ecran);
	
	int x=0;
	int y=425;

	joueur_t joueur;
	init_joueur(&joueur,x,y,100,100);

	mur_t mur;
	init_mur(&mur,200,480,50,50);
	
	

	// Boucle principale
	while(!terminer){
		SDL_RenderClear(ecran);
		SDL_RenderCopy(ecran,fond,NULL,NULL);
		apply_texture(perso,ecran,x,y);
		apply_texture(murtoutseul,ecran,200,480);
		SDL_RenderPresent(ecran);
		
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
					perso=charger_image("ressources/marche1.bmp",ecran);
					break;
				case SDLK_DOWN:
					perso=charger_image("ressources/accroupis.bmp",ecran);
					break;
				case SDLK_LEFT:
					joueur.x=(joueur.x)-5;
					x=x-5;
					if(1==(est_en_collision_mur(&joueur,&mur))){
						joueur.x=(joueur.x)+5;
						x=x+5;
						break;
					}
					perso=charger_image("ressources/marche1_envers.bmp",ecran);
					break;
				case SDLK_RIGHT:
					joueur.x=(joueur.x)+5;
					x=x+5;
					if(1==(est_en_collision_mur(&joueur,&mur))){
						joueur.x=(joueur.x)-5;
						x=x-5;
						break;
					}
					perso=charger_image("ressources/marche1.bmp",ecran);
					break;
				case SDLK_SPACE:
					//valeur à ajuster avec le bon perso
					joueur.y=(joueur.y)-50;
					y=y-50;
					joueur.x=(joueur.x)+20;
					x=x+20;
					murtoutseul=charger_image("ressources/murtoutseul.bmp",ecran);
					perso=charger_image("ressources/saut.bmp",ecran);
					SDL_RenderClear(ecran);
					SDL_RenderCopy(ecran,fond,NULL,NULL);
					apply_texture(perso,ecran,x,y);
					apply_texture(murtoutseul,ecran,200,480);
					SDL_RenderPresent(ecran);
					SDL_Delay(200);
					joueur.y=(joueur.y)+50;
					y=y+50;
					perso=charger_image("ressources/marche1.bmp",ecran);
					break;
			}
		}
		
	}
	//Libérer de la mémoire
	SDL_DestroyTexture(fond);
	SDL_DestroyRenderer(ecran);
	// Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}

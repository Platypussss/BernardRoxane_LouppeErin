#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fichiers.c"


int main(int argc, char *argv[]){

	tableau_t t;
	init_struct(&t,4,8);	//premier paramètre c'est le nb de lignes
	lire_fichier("file.txt",&t);
	afficher_tab_2D(&t,4,8);
	/*modifier_caractere(&t,2,4,'k','j');
	afficher_tab_2D(&t,2,4);
	desallouer_tab_2D(&t,2);*/
	
	
	
	return EXIT_SUCCESS;
}

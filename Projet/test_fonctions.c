#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fichiers.c"

int main(){
	int x=3; int y=2;
	char** tab; char** tab1;
	
	/*//Tests sur les tableaux
	tab=allouer_tab_2D(x,y);
	tab1=allouer_tab_2D(x,y);
	afficher_tab_2D(tab,x,y);
	tab1=modifier_caractere(tab,x,y,' ','a');
	afficher_tab_2D(tab1,x,y);*/
	
	/*//Test sur les fichiers
	int ligne; int colonne;
	ligne=nbLigne("file.txt");
	colonne=nbColonne("file.txt");
	afficher_taille_fichier("file.txt");
	ecrire_fichier("file.txt",tab1,x,y);
	afficher_taille_fichier("file.txt");*/
	char** t;
	t=allouer_tab_2D(x,y);
	//afficher_tab_2D(t,x,y);
	lire_fichier("file.txt");
	//afficher_tab_2D(t,x,y);
	return EXIT_SUCCESS;
}

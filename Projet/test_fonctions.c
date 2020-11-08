#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_fichiers.c"

int main(){
	int n=4; int m=4;
	char** tab; char** tab1;
	
	//Tests sur les tableaux
	tab=allouer_tab_2D(n,m);
	tab1=allouer_tab_2D(n,m);
	afficher_tab_2D(tab,n,m);
	tab1=modifier_caractere(tab,n,m,' ','a');
	afficher_tab_2D(tab1,n,m);
	
	//Test sur les fichiers
	int ligne; int colonne;
	ligne=nbLigne("file.txt");
	colonne=nbColonne("file.txt");
	afficher_taille_fichier("file.txt");
	ecrire_fichier("file.txt",tab1,n,m);
	afficher_taille_fichier("file.txt");
	return EXIT_SUCCESS;
}

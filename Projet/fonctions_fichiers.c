#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_fichiers.h"

/**alloue un tableau de caractère de taille n*m
*n nombre de lignes
*m nb de colonnes
*initialisé avec le caractère " "
*/
char** allouer_tab_2D(int n, int m){
	//allocation mémoire
	char ** tab=malloc(m*sizeof(char *));

	for(int i=0;i<m;i++){
		tab[i]=malloc(n*sizeof(char));
	}
	
	//remplissage tableau
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			tab[i][j]=' ';
		}
	}
	return tab;	
}

/**désalloue la mémoire du tableau
*n nombre de lignes
*/
void desallouer_tab_2D(char** tab,int n){
	for(int i=0;i<n;i++){
		free(tab[i]);
	}
	free(tab);	
}

/**affiche le contenu du tableau
*n nombre de  lignes
*m nombre de colonnes
*/
void afficher_tab_2D(char** tab,int n,int m){
	char c;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			c=tab[i][j];
			printf(" %c ",c);
		}
		putchar('\n');
	}
}

int main(){
	int n,m;
	n=4;
	m=2;
	char** tab;
	tab=allouer_tab_2D(n,m);
	afficher_tab_2D(tab,n,m);
	EXIT_SUCCESS;
}

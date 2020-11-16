#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tableau.h"

/**alloue un tableau de caractère de taille n*m
*m nombre de lignes
*n nb de colonnes
*initialisé avec le caractère " "
*/
char** allouer_tab_2D(int n, int m){
	//allocation mémoire
	char** tab=(char**)malloc(n*sizeof(char *));
	for(int i=0;i<n;i++){
		tab[i]=malloc(m*sizeof(char));
	}
	
	//remplissage tableau
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tab[i][j]=' ';
		}
	}
	return tab;	
}

/**désalloue la mémoire du tableau
*n nombre de colonnes
*/
void desallouer_tab_2D(char** tab,int n){
	for(int i=0;i<n;i++){
		free(tab[i]);
	}
	free(tab);	
}

/**affiche le contenu du tableau
*m nombre de  lignes
*n nombre de colonnes
*/
void afficher_tab_2D(char** tab,int n,int m){
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c=tab[i][j];
			printf(" %c ",c);
		}
		putchar('\n');
	}
}

/**retourne un nouveau tableau avec le caractère ancien remplacé par le nouveau*/
char** modifier_caractere(char** tab, int n,int m,char ancien,char nouveau){
	char** tab_bis;
	tab_bis=allouer_tab_2D(n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tab[i][j]==ancien){
				tab_bis[i][j]=nouveau;
			}else{
				tab_bis[i][j]=tab[i][j];
			}
		}
	}
	desallouer_tab_2D(tab,n);
	return tab_bis;
}


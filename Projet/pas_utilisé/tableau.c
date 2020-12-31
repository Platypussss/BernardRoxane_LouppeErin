#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tableau.h"

/**initialisation structure*/
void init_struct(tableau_t* t,int n,int m){
	t->tab=(char**)malloc(n*sizeof(char *));
	for(int i=0;i<n;i++){
		t->tab[i]=malloc(m*sizeof(char));
	}
	
	//remplissage tableau
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			t->tab[i][j]=' ';
		}
	}
}

/**alloue un tableau de caractère de taille n*m
*m nombre de lignes
*n nb de colonnes
*initialisé avec le caractère " "
*/
/*char** allouer_tab_2D(int n, int m){
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
}*/

/**désalloue la mémoire du tableau
*n nombre de colonnes
*/
void desallouer_tab_2D(tableau_t* t,int n){
	for(int i=0;i<n;i++){
		free(t->tab[i]);
	}
	free(t->tab);	
}

/**affiche le contenu du tableau
*m nombre de  lignes
*n nombre de colonnes
*/
void afficher_tab_2D(tableau_t* t,int n,int m){
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c=t->tab[i][j];
			printf(" %c ",c);
		}
		putchar('\n');
	}
}

/**retourne un nouveau tableau avec le caractère ancien remplacé par le nouveau*/
void modifier_caractere(tableau_t* t, int n,int m,char ancien,char nouveau){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(t->tab[i][j]==ancien){
				t->tab[i][j]=nouveau;
			}
		}
	}
}


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tableau_s{
	char ** tab;
};
typedef struct tableau_s tableau_t; 

/**initialisation structure*/
void init_struct(tableau_t* t,int n,int m);


/**alloue un tableau de caractère de taille n*m
*n nombre de colonne
*m nb de ligne
*initialisé avec le caractère " "
*/
//char** allouer_tab_2D(int n, int m);

/**désalloue la mémoire du tableau
*n nombre de lignes
*/
void desallouer_tab_2D(tableau_t* t,int n);

/**affiche le contenu du tableau*/
void afficher_tab_2D(tableau_t* t,int n,int m);

/**retourne un nouveau tableau avec le caractère ancien remplacé par le nouveau*/
void modifier_caractere(tableau_t* t, int n,int m,char ancien,char nouveau);

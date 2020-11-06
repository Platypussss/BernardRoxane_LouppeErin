#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**alloue un tableau de caractère de taille n*m
*n nombre de colonne
*m nb de ligne
*initialisé avec le caractère " "
*/
char** allouer_tab_2D(int n, int m);

/**désalloue la mémoire du tableau
*n nombre de lignes
*/
void desallouer_tab_2D(char** tab,int n);

/**affiche le contenu du tableau*/
void afficher_tab_2D(char** tab,int n,int m);

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**Compte le nombre de lignes du fichier*/
int nbLigne(const char* nomFichier);

/**Compte le nombre max de colonne du fichier*/
int nbColonne(const char* nomFichier);

/**affiche le nombre maximum de lignes et celui de colonne dans le fichier*/
void afficher_taille_fichier(const char* nomFichier);

/**lit un fichier dont le nomestnomFichier
*retourne le tableau qui contient les caractères du fichier tel qu’une ligne du tableau *correspond à une ligne du fichier.
*/
void lire_fichier(const char* nomFichier);

/**écrit le tableau dans le fichier*/
void ecrire_fichier(const char* nomFichier, char** tab, int n, int m);

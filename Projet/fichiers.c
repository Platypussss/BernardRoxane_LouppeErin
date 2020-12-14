#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fichiers.h"


/**Compte le nombre de lignes du fichier*/
int nbLigne(const char* nomFichier){
	FILE * file;
	file=fopen(nomFichier,"r");
	int nbLigMax=0;
	int c;
	if(file==NULL){
		perror("Erreur dans l'ouverture du fichier");
	}else{
		while((c=fgetc(file))!=EOF){ //tant que c'est pas la fin du fichier
			if(c=='\n'){ //nouvelle ligne
				nbLigMax++;
			}
		}
	}
	fclose(file);
	return nbLigMax;
} 

/**Compte le nombre max de colonne du fichier*/
int nbColonne(const char* nomFichier){
	FILE * file;
	file=fopen(nomFichier,"r");
	int nb=0;
	int nbColMax=0;
	int c;
	if(file==NULL){
		perror("Erreur dans l'ouverture du fichier");
	}else{
		while((c=fgetc(file))!=EOF){ //tant que c'est pas la fin du fichier
			if(c=='\n'){ //nouvelle ligne
				nb=0; //remet le compteur de colonne à 0 à chaque nouvelle ligne
			}
			if(c!='\n'){ //pas à la fin de la ligne
				nb++;
				if(nb>=nbColMax){
					nbColMax=nb;
				}
			}
		}
	}
	fclose(file);
	return nbColMax;
}

/**affiche le nombre maximum de lignes et celui de colonne dans le fichier*/
void afficher_taille_fichier(const char* nomFichier){
	FILE * file;
	file=fopen(nomFichier,"r");
	int nb=0;
	int nbLigMax=0;
	int nbColMax=0;
	int c;
	if(file==NULL){
		perror("Erreur dans l'ouverture du fichier");
	}else{
		while((c=fgetc(file))!=EOF){ //tant que c'est pas la fin du fichier
			if(c=='\n'){ //nouvelle ligne
				nbLigMax++;
				nb=0; //remet le compteur de colonne à 0 à chaque nouvelle ligne
			}
			if(c!='\n'){ //pas à la fin de la ligne
				nb++;
				if(nb>=nbColMax){
					nbColMax=nb;
				}
			}
		}
	}
	fclose(file);
	printf("Le nombre de lignes max:%d \nLe nombre de colonnes max:%d \n",nbLigMax,nbColMax);
}

/**lit un fichier dont le nomestnomFichier
*retourne le tableau qui contient les caractères du fichier tel qu’une ligne du tableau *correspond à une ligne du fichier.
*/
void lire_fichier(const char* nomFichier,tableau_t* t){
	FILE * file;
	file=fopen(nomFichier,"r");
	int n=nbColonne(nomFichier);
	int m=nbLigne(nomFichier);
	char c;
	if(file==NULL){
		perror("Erreur dans l'ouverture du fichier");
	}else{
		for(int i=0;i<m;i++){
			c=fgetc(file);
			while(c!='\n'){ //pas à la fin de la ligne
				for(int j=0; j<n;j++){
					t->tab[i][j]=c;
					c=fgetc(file);
				}
			}	
		}
		fclose(file);
	}
}

/**écrit le tableau dans le fichier*/
void ecrire_fichier(const char* nomFichier, tableau_t* t, int n, int m){
	FILE* file;
	file=fopen(nomFichier,"w");
	if(file==NULL){
		perror("Erreur dans l'ouverture du fichier");
	}else{
		int j=0;
		for(int i=0;i<n;i++){
			while(j<m){
				fputc(t->tab[i][j],file);
				if(ferror(file)){
					perror("Erreur dans l'écriture du fichier.\n");
				}
				j++;
			}
			fputc('\n',file);
				if(ferror(file)){
					perror("Erreur dans l'écriture du fichier.\n");
				}
			j=0;
		}
	fclose(file);
	}
}

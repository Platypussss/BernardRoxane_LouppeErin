#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**charge une image et retourne la surface de texture associée*/
SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer); 

/**charge l'image en transparence*/
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);



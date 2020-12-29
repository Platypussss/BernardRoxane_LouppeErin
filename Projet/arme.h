#ifndef H_ARME
#define H_ARME

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arme_s{
    int x;
    int y;
    int h;
    int w;
    int est_visible;
};
typedef struct arme_s arme_t;

void init_arme(arme_t *a,int x,int y,int h,int w,int e);

void set_est_visible(arme_t *a,int e);

int get_est_visible(arme_t *a);

#endif
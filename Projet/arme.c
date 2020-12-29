#include "arme.h"

void init_arme(arme_t *a,int x,int y,int h,int w,int e){
    a->x=x;
    a->y=y;
    a->h=h;
    a->w=w;
    a->est_visible=e;
}

void set_est_visible(arme_t *a,int e){
    a->est_visible=e;
}

int get_est_visible(arme_t *a){
    return a->est_visible;
}
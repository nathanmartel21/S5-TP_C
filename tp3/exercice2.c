#include <stdio.h>
#include "sqrt.c"

float distance(float xa, float xb, float ya, float yb){

    float nb = 0;
    float distance = 0;

    nb = ((xb - xa) * (xb - xa)) + ((yb - ya) * (yb - ya));

    distance = estimation_sqrt(nb);

    printf("\nLa distance entre les points A et B est de %f\n",distance);

}

int main(){

    float xa;
    float ya;
    float xb;
    float yb;

    printf("Pour le point A, donnez les coordonnées de l'abscisse : ");
    scanf(" %f", &xa);

    printf("\nPour le point A, donnez les coordonnées de l'ordonnée : ");
    scanf(" %f", &ya);

    printf("\nPour le point B, donnez les coordonnées de l'abscisse : ");
    scanf(" %f", &xb);

    printf("\nPour le point B, donnez les coordonnées de l'ordonnée : ");
    scanf(" %f", &yb);   

    printf("\nLe point A a pour coordonnées : (%f;%f)",xa,ya);
    printf("\nLe point B a pour coordonnées : (%f;%f)",xb,yb);


    distance(xa, xb, ya, yb);

}



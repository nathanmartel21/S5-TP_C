#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "distance.c"

int touche_cercle(float xa, float ya, float ra, float xb, float yb, float rb) {
    
    double distance_cercle = distance(xa, xb, ya, yb);
    double somme_rayon = ra + rb;
    double va_rayon = fabs(ra - rb);

    printf("\nDistance : %.6f", distance_cercle);
    printf("\nSomme des rayons : %.6f", somme_rayon);
    printf("\nDifférence des rayons : %.6f", va_rayon);

    if (distance_cercle == 0 && ra == rb) {
        printf("\nLes cercles sont identiques.\n");
        return 0;
    }
    if (distance_cercle > somme_rayon) {
        printf("\nLes cercles sont séparés, donc ils ne se touchent pas.\n");
        return 1;
    }
    else if (distance_cercle == somme_rayon) {
        printf("\nLes cercles se touchent extérieurement, ils sont tangents.\n");
        return 0;
    } 
    else if (distance_cercle == va_rayon) {
        printf("\nLes cercles se touchent intérieurement.\n");
        return 0;
    }
    else if (distance_cercle < va_rayon) {
        printf("\nL'un des cercles est entièrement à l'intérieur de l'autre mais ils ne se touchent pas.\n");
        return 1;
    }

    printf("\nLes cercles se chevauchent.\n");

}

int main() {
    float xa, ya, xb, yb, ra, rb;

    printf("Point d'abscisse pour le centre du cercle A : ");
    scanf(" %f", &xa);

    printf("Point d'ordonnée pour le centre du cercle A : ");
    scanf(" %f", &ya);

    printf("Rayon du cercle A : ");
    scanf(" %f", &ra);

    printf("Point d'abscisse pour le centre du cercle B : ");
    scanf(" %f", &xb);

    printf("Point d'ordonnée pour le centre du cercle B : ");
    scanf(" %f", &yb);   

    printf("Rayon du cercle B : ");
    scanf(" %f", &rb);

    touche_cercle(xa, ya, ra, xb, yb, rb);
    return 0; 
}

#include <stdio.h>
#include "sqrt.c"

double distance(float xa, float xb, float ya, float yb){

    float nb = 0;
    double distance = 0;

    nb = ((xb - xa) * (xb - xa)) + ((yb - ya) * (yb - ya));

    distance = estimation_sqrt(nb);

    printf("\nLa distance entre les points A et B est de %f\n",distance);

    return distance;

}
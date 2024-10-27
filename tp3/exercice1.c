#include <stdio.h>

int main(){

    double x1 = 5;
    double valeur_depart = 5;
    int nb_ite = 2;

    for(int i=0;i<nb_ite;i++){

        x1 = x1 - (((x1 * x1) - valeur_depart)/(2 * x1));
        printf("Après l'itéraction %d, l'estimation est de %f\n", i +1, x1);
    }

}
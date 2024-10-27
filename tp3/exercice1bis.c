#include <stdio.h>

double estimation_sqrt(double valeur_depart){

    double x1 = valeur_depart;
    int nb_ite = 15;

    for(int i=0;i<nb_ite;i++){

        x1 = x1 - (((x1 * x1) - valeur_depart)/(2 * x1));
        //printf("Après l'itéraction %d, l'estimation est de %f\n", i +1, x1);
    }

    return x1;

}

int main(){

    double nombres[] = {4, 5, 9, 57, 573};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    for(int i = 0;i<taille;i++){

        double result = estimation_sqrt(nombres[i]);
        printf("Estimation de %f après 15 itérations : %f\n",nombres[i],result);
        
    }

}
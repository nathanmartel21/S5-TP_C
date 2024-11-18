#include <stdio.h>

char *concat (char* first, char* second){

    char tab[100];

    int i = 0;

    for(i; first[i] != '\0'; i++){

        tab[i] = first[i];

    }

    for(int j = 0; second[j] != '\0'; j++){

        tab[i] = second[j];
        i++;

    }

    tab[i] = '\0';
    
    printf("Chaines concatenées : %s\n", tab);

}


void main(){

    int nb_chaine;

    char premiere[100];

    printf("Combien de chaîne de caractères voulez-vous saisir : ");
    scanf("%d", &nb_chaine);

    char *tabfinal = malloc(nb_chaine * sizeof())

    for (int i = 0; i < nb_chaine; i++){

        printf("Entrez votre chaîne de caractère : ");
        scanf("%s", premiere);

    }

}
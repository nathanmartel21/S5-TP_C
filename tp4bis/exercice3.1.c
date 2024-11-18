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
    
    return tab;

}


void main(){

    char premiere[100];
    char deuxieme[100];
    char troisieme[100];
    char quatrieme[100];


    printf("Donnez une chaîne de caractère (1/4)) : ");
    scanf(" %s", premiere);

    printf("Donnez une chaîne de caractère (2/4)) : ");
    scanf(" %s", deuxieme);

    printf("Donnez une chaîne de caractère (3/4)) : ");
    scanf(" %s", troisieme);

    printf("Donnez une chaîne de caractère (4/4)) : ");
    scanf(" %s", quatrieme);


    char *c1 = concat(premiere, deuxieme);
    char *c2 = concat(troisieme, quatrieme);

    char* finalResult = concat(c1, c2);

    printf("Résultat final: %s\n", finalResult);

    return 0;


}
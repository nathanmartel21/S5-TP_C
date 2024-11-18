#include <stdio.h>

void minuscule(char* majuscule){

for (int i = 0; majuscule[i] != '\0'; i++){

    if (majuscule[i] >= 'A' && majuscule[i] <= 'Z'){
        majuscule[i] += 32;
        }
    }

}

void main(){

    char tab[100];
    printf("Donnez une chaîne de caractère : ");
    scanf(" %s", tab);

    minuscule(tab);

    printf("%s", tab);

}
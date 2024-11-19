#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat (char* a, char* b){

    char tab[100];
    int i = 0;

    for(i ; i < strlen(a) ; i++){
        tab[i] = a[i];
    }

    for(int j = 0 ; j < strlen(b) ; j++){
        tab[i] = b[j];
        i++;
    }

    printf("%s", tab);
    return tab;

}

int main(){

    char a[100], b[100];

    printf("Donnez chaine de caractère de a : ");
    scanf("%s", a);

    printf("Donnez chaine de caractère de b : ");
    scanf("%s", b);

    concat(a, b);

}
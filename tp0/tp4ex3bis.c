#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *first, char *second){

    char tab[200];

    int i = 0, j = 0;

    for (i ; i < strlen(first) ; i++){

        tab[i] = first[i];

    }

    i++;

    for (j ; j < strlen(second) ; j ++){

        tab[i] = second[j];
        i++;

    }

    i++;

    tab[i] = '\0';

    printf("%s", tab);

    return tab;

}

void main(void){

    char a[100] = "Nathan";
    char b[100] = "Martel";

    concat(a, b);

}
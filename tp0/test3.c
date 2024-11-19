#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char *a, char *b){

    int i = 0;
    int j = 0;

    char* result = malloc(strlen(a) + strlen(b) + 1);

    for (i ; i < strlen(a) ; i++){
        result[i] = a[i];
    }

    for (j = 0 ; j < strlen(b); j++){
        result[i] = b[j];
        i++;
    }

    result[i] = '\0';

    return result;

}

void main(){

    int nb;
    char *result = malloc(1);
    result[0] = '\0';

    printf("Combien de chaines de caractères : ");
    scanf("%d", &nb);
    char temp[200];

    for (int i = 0 ; i < nb ; i++){

        printf("Entrez une chaîne de caractère (%d) : ", i+1);
        scanf("%s", temp);

        char * concatened = concat(result, temp);
        free(result);
        result = concatened;

    }

    printf("%s", result);
    
    free(result);


}
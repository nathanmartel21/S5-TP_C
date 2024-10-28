#include <stdio.h>

char *def_concat(char* first, char* second){

    char concat[200];
    int i = 0;
    int j = 0;

    do{
        concat[i] = first[i];
        i++;
    } while(first[i] != '\0');

    do{
        concat[i] = second[j];
        j++;
        i++;
    } while(second[j] != '\0');

    concat[i] = '\0';
    
    printf("Chaines concatenées : %s\n",concat);
    return concat;

}

int main(){

    char tab_first[100];
    char tab_second[100];

    printf("Entrez une chaîne chaine de caractères : ");
    scanf(" %s", tab_first);

    printf("Entrez une deuxième chaine de caractères : ");
    scanf(" %s", tab_second);

    def_concat(tab_first, tab_second);

}
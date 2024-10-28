#include <stdio.h>

char lower(char *chaine){

    //printf(" %p", chaine);
    //printf(" %c", chaine);
    if (*chaine >= 'A' && *chaine <= 'Z') { 
        *chaine = *chaine + 32;
    }

}

char main(){

    char maj = 'T';
    lower(&maj);

    printf("Le caractère %c devient maintenant %c.\n", (maj - 32), maj);

}



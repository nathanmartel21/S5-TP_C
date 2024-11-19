#include <stdio.h>

char* Enminuscule(char *maj){

    *maj += 32;
    printf("\n%c\n\n", *maj);
    return maj;

}

void main(void){



    char t1[] = "A";
    char *a = Enminuscule(t1);

    printf("%s", a);

    //char t2[] = "E";
    //Enminuscule(t2);

    //char t3[] = "N";
    //Enminuscule(t3);


}
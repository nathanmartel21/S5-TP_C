#include <stdio.h>

int swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void main(){

    int x = 6;
    int y = 18;

    swap (&x, &y);
    printf("%d et %d", x, y);

}
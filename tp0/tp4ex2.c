#include <stdio.h>

void *swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

    printf("A = %d et B = %d\n", *a, *b);
}

void main(void){

    int x = 10;
    int y = 20;

    swap(&x, &y);
    
}
#include <stdio.h>

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void main(void){

    int a = 25;
    int b = 50;

    swap(&a, &b);

    printf("%d, %d", a, b);


}
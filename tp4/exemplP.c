#include <stdio.h>

void changerValeur(int *p) {
    *p = 10; 
}

int main() {
    int x = 5;
    printf("Avant : x = %d\n", x); // 5

    changerValeur(&x); 

    printf("Après : x = %d\n", x); // 10
}
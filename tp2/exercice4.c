#include <stdio.h>

int main() {
    int tableau[6];
    int i;

    printf("Entrer 6 entiers : \n");
    for (i = 0; i < 6; i++) {
        scanf("%d", &tableau[i]);
    }

    for (i = 1; i < 6; i++) {
        if (tableau[i] > tableau[i - 1]) {
            int temp = tableau[i];
            tableau[i] = tableau[i - 1];
            tableau[i - 1] = temp;
        }
    }

    printf("Tableau après inversion : \n");
    for (i = 0; i < 6; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

}

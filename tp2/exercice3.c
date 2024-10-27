#include <stdio.h>

int main() {
    char direction;
    char direction2;
    int nb;
    int i, j;

    printf("'h' pour triangle en haut, 'b' pour triangle en bas : ");
    scanf(" %c", &direction);

    printf("'d' pour triangle a droite, 'g' pour triangle a gauche : ");
    scanf(" %c", &direction2);

    printf("Nombre de lignes : ");
    scanf("%d", &nb);

    if (direction2 == 'g') {
        if (direction == 'b') {
            for (i = nb; i >= 1; i--) {
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
        } else if (direction == 'h') {
            for (i = 1; i <= nb; i++) {
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
        }
    } else if (direction2 == 'd') {
        if (direction == 'h') {
            for (i = 1; i <= nb; i++) {
                for (j = nb; j > i; j--) {
                    printf("  ");  
                }
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
        } else if (direction == 'b') {
            for (i = nb; i >= 1; i--) {
                for (j = nb; j > i; j--) {
                    printf("  ");  
                }
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
        }
    }
}
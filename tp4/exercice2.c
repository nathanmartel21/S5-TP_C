#include <stdio.h>

void lower(char *chaine) {
    for (int i = 0; chaine[i] != '\0'; i++) { // fin du tableau \O. Sinon strlen ?
        if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            chaine[i] = chaine[i] + 32;
        }
    }
}

int main() {
    char chaine[100];

    printf("Entrez une chaîne de caractères : ");
    scanf(" %s", chaine);

    lower(chaine);

    printf("La chaîne en minuscules est : %s\n", chaine);

}

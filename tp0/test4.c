#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concatmul(int n, char** strings) {
    // Calculer la taille totale nécessaire pour la chaîne concaténée
    int total_length = 0;
    for (int i = 0; i < n; i++) {
        total_length += strlen(strings[i]);
    }

    // Allouer de la mémoire pour la chaîne concaténée (total_length + 1 pour le '\0')
    char* result = malloc(total_length + 1);  // +1 pour le caractère nul de fin

    // Concaténer toutes les chaînes dans le résultat
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(strings[i]); j++) {
            result[index++] = strings[i][j];
        }
    }

    // Ajouter le caractère nul à la fin
    result[index] = '\0';

    return result;
}

int main() {
    // Exemple d'utilisation de concatmul
    int n = 3;
    char* strings[] = {
        "Bonjour",
        " tout",
        " le monde"
    };

    // Concaténer les chaînes
    char* concatened = concatmul(n, strings);

    printf("Chaîne concaténée : %s\n", concatened);

    free(concatened);

}

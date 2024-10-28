#include <stdio.h>
#include <stdlib.h> // pour la partie malloc et free

// Test pour être sur d'avoir compris les pointeurs.

int main() {
    int var;
    var = 10;

    int *pointeur = &var; // Déclaration d'un pointeur d'entier qui pointe vers var

    printf("Valeur de var : %d\n", var); //10
    printf("Adresse de var : %p\n", (void*)&var); // 0x7ffd5be0bfdc
    printf("Valeur du pointeur (adresse de var): %p\n", (void*)pointeur); // 0x7ffd5be0bfdc

    // Pour afficher la valeur pointée par le pointeur
    printf("Valeur pointée par pointeur (valeur de var) : %d\n", *pointeur); // 10
    printf("Adresse de pointeur : %p\n", (void*)&pointeur); // 0x7ffde43b0350

    printf("\n######## Incrémentation de la variable var de 1 ########\n");

    var += 1;

    printf("\nValeur de var : %d\n", var); //11
    printf("Adresse de var : %p\n", (void*)&var); // 0x7ffec70f70dc
    printf("Valeur du pointeur (adresse de var): %p\n", (void*)pointeur); // 0x7ffec70f70dc

    printf("Valeur pointée par pointeur (valeur de var) : %d\n", *pointeur); // 11
    printf("Adresse de pointeur : %p\n", (void*)&pointeur); // 0x7ffec70f70e0

    printf("\n######## Incrémentation sur le pointeur de 1 ########\n");

    printf("\nValeur de var : %d\n", var); //11
    printf("Adresse de var : %p\n", (void*)&var); // 0x7ffc4be7f8bc
    printf("Valeur du pointeur (adresse de var): %p\n", (void*)pointeur); // 0x7ffc4be7f8bc

    printf("Valeur pointée par pointeur (valeur de var) : %d\n", *pointeur); // 11
    printf("Adresse de pointeur : %p\n", (void*)&pointeur); // 0x7ffc4be7f8c0

    printf("\n######## Changement valeur *pointeur = 2 ########\n");

    *pointeur = 2;

    printf("\nValeur de var : %d\n", var); // 2
    printf("Adresse de var : %p\n", (void*)&var); // 0x7fffb7106aec
    printf("Valeur du pointeur (adresse de var): %p\n", (void*)pointeur); // 0x7fffb7106aec
    printf("Valeur pointée par pointeur (valeur de var) : %d\n", *pointeur); // 2
    printf("Adresse de pointeur : %p\n", (void*)&pointeur); // 0x7fffb7106af0

    var = 20;

    printf("\n######## Changement valeur var = 20 ########\n");    

    printf("\nValeur de var : %d\n", var); // 20
    printf("Adresse de var : %p\n", (void*)&var); // 0x7fff0ba55e3c
    printf("Valeur du pointeur (adresse de var): %p\n", (void*)pointeur); // 0x7fff0ba55e3c
    printf("Valeur pointée par pointeur (valeur de var) : %d\n", *pointeur); // 20
    printf("Adresse de pointeur : %p\n", (void*)&pointeur); // 0x7fff0ba55e40

    printf("\n######## Première valeur d'un tableau ########\n");        

    char chaine[] = "Nathan";

    printf("Premier caractère (via *chaine) : %c\n", *chaine); // N
    printf("Premier caractère (via chaine[0]) : %c\n", chaine[0]); // N 

    int tableau[] = {1, 2, 35, 456, 1043};
    int *pointeurTableau = tableau; // pointe vers le premier élément du tableau

    printf("\n######## Pointeurs et tableaux ########\n");
        for (int i =0; i < 5;i++) {
            printf("Valeur de tableau[%d] : %d, via pointeur : %d. Pointeur : %d. @ pointeur qui bouge : %p. @ pointeur variable : %p\n", i, tableau[i], *(pointeurTableau + i), *pointeurTableau, (void*)(pointeurTableau + i), (void*)pointeurTableau);
    } // en gros pointeurTableau + i = valeur du tableau sinon ça reste à 1
    // son addresse commence à 0x7ffc55c21af0 puis 0x7ffc55c21af4 puis 0x7ffc55c21af8, 0x7ffc55c21afc, ...
    // car pointeur = 4 octets dans la mémoire

    int **pointeurPointeur = &pointeur; // pointeur vers un pointeur (qui point sur variable var = 20)
    printf("\n######## Pointeurs de Pointeurs ########\n");
    printf("\nValeur via pointeur de pointeur : %d\n", **pointeurPointeur); // accède à la valeur de var = 20

    int *ptrDynamique = malloc(sizeof(int)); // allocation dynamique
    *ptrDynamique = 42;

    printf("\n######## Allocation Dynamique ########\n");
    printf("Valeur allouée dynamiquement : %d\n", *ptrDynamique); //42 du coup

    free(ptrDynamique); // libération de la mémoire 

}
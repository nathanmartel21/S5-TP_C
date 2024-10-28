#include <stdio.h>
#include <time.h>
#include "random.c"

int demande_mise(int argent) {
    int mise;
    do {
        printf("\nEntrez votre mise (max %d euros) : ", argent);
        scanf(" %d", &mise);
        if (mise <= 0 || mise > argent) {
            printf("\nMise invalide.");
        }
    } while (mise <= 0 || mise > argent);
    return mise;
}

int demande_pari() {
    int pari;
    do {
        printf("\nEntrez votre pari (entre 1 et 6) : ");
        scanf(" %d", &pari);
        if (pari < 1 || pari > 6) {
            printf("\nPari invalide. ");
        }
    } while (pari < 1 || pari > 6);
    return pari;
}

int main() {
    int argent = 50;
    int mise, pari;

    while (argent > 0 && argent < 30000) {
        printf("\nVous avez %d euros\n", argent);
        mise = demande_mise(argent);
        printf("\nVous misez : %d\n", mise);
        pari = demande_pari();
        printf("\nVous avez parié : %d\n", pari);

        //int resultat = (def_random() % 6) + 1;
        int resultat = pari;

        printf("\nRésultat du lancé : %d\n", resultat);

        if (pari == resultat) {
            printf("\nVous gagnez : %d\n", 2 * mise);
            argent += 2 * mise;
        } else {
            printf("\nVous perdez la mise\n");
            argent -= mise;
        }
    }

    if (argent >= 30000) {
        printf("\nBravo vous avez ruiné le casino\n");
    } else {
        printf("\nVous êtes ruiné\n");
    }
}

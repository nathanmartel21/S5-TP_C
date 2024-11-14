#include <stdio.h>
#include <stdlib.h>

struct Vecteur {
    float *tab;
    int taille;
};

struct Vecteur returntab(float new_valeur) {
    struct Vecteur vect;
    vect.taille = 1;
    vect.tab = (float *)malloc(vect.taille * sizeof(float));
    vect.tab[0] = new_valeur;
    return vect;
}

void ajoutele(struct Vecteur *vect, float nouv_ele) {
    float *nouv_tab = (float *)malloc((vect->taille + 1) * sizeof(float));

    for (int i = 0; i < vect->taille; i++) {
        nouv_tab[i] = vect->tab[i];
    }

    nouv_tab[vect->taille] = nouv_ele;

    free(vect->tab);

    vect->tab = nouv_tab;
    vect->taille++;
}

void liberervecteur(struct Vecteur *vect) {
    free(vect->tab);
}

int main() {
    float val;

    struct Vecteur vect = returntab(2); 

    printf("Valeur initiale : %f\n", vect.tab[0]);

    printf("Entrer une valeur : ");
    scanf("%f", &val);

    ajoutele(&vect, val); 

    for (int i = 0; i < vect.taille; i++) {
        printf("Valeur %d : %f\n", i + 1, vect.tab[i]);
    }

    liberervecteur(&vect);

    return 0;
}

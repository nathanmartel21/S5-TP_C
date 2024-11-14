#include <stdio.h>
#include <stdlib.h>

float *returntab(int *taille, float new_valeur) {
    *taille = 1;
    float *tab = (float *)malloc(*taille * sizeof(float));
    tab[0] = new_valeur;
    return tab;
}

void ajoutele(int *taille, float **tab, float nouv_ele) {
    float *nouv_tab = (float *)malloc((*taille + 1) * sizeof(float));


    for (int i = 0; i < *taille; i++) {
        nouv_tab[i] = (*tab)[i];
    }

    nouv_tab[*taille] = nouv_ele;

    free(*tab);
    *tab = nouv_tab;
    (*taille)++;
}

void liberertab(float *tab){
    free(tab);
}

int main() {
    int taille;
    float *tab = returntab(&taille, 2); 

    if (tab == NULL) {
        printf("Échec de l'allocation de mémoire\n");
        return 1; 
    }

    printf("Valeur : %f\n", tab[0]);

    float val;
    printf("Entrer une valeur : ");
    scanf("%f", &val);

    ajoutele(&taille, &tab, val); 

    for (int i = 0; i < taille; i++) {
        printf("Valeur %d : %f\n", i + 1, tab[i]);
    }

    liberertab(tab);
}

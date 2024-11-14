#include <stdio.h>
#include <stdlib.h>

// Définition de la structure sans typedef
struct Vecteur {
    float *tab;
    int taille;
};

// Fonction qui initialise un vecteur avec un élément
struct Vecteur returntab(float new_valeur) {
    struct Vecteur vect;
    vect.taille = 1;
    vect.tab = (float *)malloc(vect.taille * sizeof(float));
    vect.tab[0] = new_valeur;
    return vect;
}

// Fonction pour ajouter un élément au vecteur
void ajoutele(struct Vecteur *vect, float nouv_ele) {
    // Allouer un tableau de taille taille+1
    float *nouv_tab = (float *)malloc((vect->taille + 1) * sizeof(float));

    // Copier les éléments existants dans le nouveau tableau
    for (int i = 0; i < vect->taille; i++) {
        nouv_tab[i] = vect->tab[i];
    }

    // Ajouter le nouvel élément à la fin
    nouv_tab[vect->taille] = nouv_ele;

    // Libérer l'ancien tableau
    free(vect->tab);

    // Mettre à jour le tableau et la taille
    vect->tab = nouv_tab;
    vect->taille++;
}

// Fonction pour libérer la mémoire du vecteur
void liberervecteur(struct Vecteur *vect) {
    free(vect->tab);
}

int main() {
    float val;

    // Initialisation du vecteur avec un premier élément
    struct Vecteur vect = returntab(2); 

    printf("Valeur initiale : %f\n", vect.tab[0]);

    // Demander à l'utilisateur de saisir une valeur
    printf("Entrer une valeur : ");
    scanf("%f", &val);

    // Ajouter la valeur au vecteur
    ajoutele(&vect, val); 

    // Affichage du contenu du vecteur
    for (int i = 0; i < vect.taille; i++) {
        printf("Valeur %d : %f\n", i + 1, vect.tab[i]);
    }

    // Libérer la mémoire allouée pour le vecteur
    liberervecteur(&vect);

    return 0;
}

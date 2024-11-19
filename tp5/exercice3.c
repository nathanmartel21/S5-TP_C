#include <stdio.h>
#include <string.h>

enum Resultat { 
    OK,
    CMP_UNFOUND,
    PAUVRE
};

struct User {
    char nom[30];
    int id;
    int solde;
};

struct Result {
    int compte_id;
    enum Resultat rez;
};

struct Result trouver_compte(int nombre_comptes, struct User* comptes_user, char* user_a_trouver) {
    struct Result r1;
    for (int i = 0; i < nombre_comptes; i++) {
        if (strcmp(comptes_user[i].nom, user_a_trouver) == 0) {
            r1.compte_id = i;
            r1.rez = OK;
            return r1;
        }
    }
    r1.rez = CMP_UNFOUND;
    return r1;
}

struct Result retrait_argent(int nombre_comptes, struct User* comptes_user, char* user) {
    printf("Quel est le montant du retrait ? ");
    int montant;
    scanf("%d", &montant);
    
    struct Result compte_pos = trouver_compte(nombre_comptes, comptes_user, user);
    if (compte_pos.rez == CMP_UNFOUND) {
        return compte_pos;
    }
    
    if (comptes_user[compte_pos.compte_id].solde < montant) {
        compte_pos.rez = PAUVRE;
        return compte_pos;
    }
    
    comptes_user[compte_pos.compte_id].solde -= montant;
    compte_pos.rez = OK;
    return compte_pos;
}

int main() {

    struct User comptes[3] = {
        {"mlk", 5, 500},
        {"fdm", 12, 60},
        {"sdb", 7, 12700}
    };

    while (1) {
        char nom_compte[30];
        printf("Veuillez entrer votre nom : ");
        scanf("%s", nom_compte);
        
        printf("Quelle opération souhaitez-vous effectuer ?\n\tTapez 'a' pour afficher votre solde\n\tTapez 'r' pour effectuer un retrait\n");
        char operation;
        scanf(" %c", &operation);

        if (operation == 'a') {
            struct Result compte_pos = trouver_compte(3, comptes, nom_compte);
            if (compte_pos.rez == CMP_UNFOUND) {
                printf("Erreur : votre compte n'a pas été trouvé.\n");
            } else {
                printf("Le solde de votre compte est : %d\n", comptes[compte_pos.compte_id].solde);
            }
        } else if (operation == 'r') {
            struct Result resultat = retrait_argent(3, comptes, nom_compte);
            if (resultat.rez == CMP_UNFOUND) {
                printf("Erreur : votre compte n'a pas été trouvé.\n");
            } else if (resultat.rez == PAUVRE) {
                printf("Erreur : solde insuffisant pour effectuer ce retrait.\n");
            } else {
                printf("La somme a bien été retirée. Nouveau solde : %d\n", comptes[resultat.compte_id].solde);
            }
        }
    }
}
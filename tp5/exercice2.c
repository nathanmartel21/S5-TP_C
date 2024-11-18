#include <stdio.h>
#include <string.h>

typedef enum ResultCode {
    SUCCESS, //par défaut du coup 0       
    ERREUR_COMPTE,     
    SOLDE_INSUFFISANT  
} ResultCode;


typedef struct Result{
    int compte_id;     
    ResultCode code;
} Result;

/**
  Cette fonction trouve un compte dans la liste des comptes en utilisant le nom de l'utilisateur
  Elle renvoie la position du compte dans la liste des comptes
*/
int trouver_compte(int nombre_comptes, char** comptes_user, char* user_a_trouver) {
    for (int i = 0; i < nombre_comptes; i++) {
        if (strcmp(comptes_user[i], user_a_trouver) == 0) {
            return i;
        }
    }
    return -1;
}

/**
  Cette fonction permet de déposer de l'argent sur un compte
  Elle renvoie un objet Result qui contient le code d'erreur et l'ID du compte
*/
Result retrait_argent(int nombre_comptes, int* comptes_id, int* comptes_solde, char** comptes_users, char* user) {
    Result r1;
    printf("Quel est le montant du retrait ? ");
    int montant;
    scanf("%d", &montant);

    int compte_pos = trouver_compte(nombre_comptes, comptes_users, user);
    if (compte_pos == -1) {
        r1.compte_id = -1;
        r1.code = ERREUR_COMPTE;
        return r1;
    }
    if (comptes_solde[compte_pos] < montant) {
        r1.compte_id = comptes_id[compte_pos];
        r1.code = SOLDE_INSUFFISANT;
        return r1;
    }
    
    comptes_solde[compte_pos] -= montant;
    r1.compte_id = comptes_id[compte_pos];
    r1.code = SUCCESS;
    return r1;
}

int main() {
    int comptes_id[3] = {5, 12, 7};
    int comptes_soldes[3] = {500, 60, 12700};
    char* comptes_users[3] = {"mlk", "fdm", "sdb"};

    while (1) {
        char nom_compte[4];
        int id_compte;
        printf("Veuillez entrer votre nom (3 lettres) : ");
        scanf(" %c%c%c", nom_compte, nom_compte + 1, nom_compte + 2);
        nom_compte[3] = 0;

        printf("Quelle opération souhaitez-vous effectuer ?\n\tTapez 'a' pour afficher votre solde\n\tTapez 'r' pour effectuer un retrait\n");
        char operation;
        scanf(" %c", &operation);

        if (operation == 'a') {
            int compte_pos = trouver_compte(3, comptes_users, nom_compte);
            if (compte_pos == -1) {
                printf("Erreur: votre compte n'a pas été trouvé\n");
            } else {
                printf("Le solde de votre compte est : %d\n", comptes_soldes[compte_pos]);
            }
        } else if (operation == 'r') {
            Result resultat = retrait_argent(3, comptes_id, comptes_soldes, comptes_users, nom_compte);
            if (resultat.code == SUCCESS) {
                printf("La somme a bien été retirée du compte n° %d\n", resultat.compte_id);
            } else if (resultat.code == ERREUR_COMPTE) {
                printf("Erreur: votre compte n'a pas été trouvé\n");
            } else if (resultat.code == SOLDE_INSUFFISANT) {
                printf("Erreur: solde insuffisant pour effectuer le retrait\n");
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>


struct User{

    int age;
    char *name;

};

struct User demande(){

    struct User user;

    user.name = (char *)malloc(11);

    printf("\nDonnez un nom d'utilisateur : ");
    scanf("%s", (user.name));

    printf("\nDonnez un age : ");
    scanf("%d", &(user.age));


    printf("Bonjour %s, vous avez %d ans", user.name, user.age);

    return user;

}

struct User* enregistre(int *n){

    int n;

    printf("Combien d'utilisateurs : ");
    scanf("%d", &n);

    struct User* users = malloc(sizeof(struct User) * *n);

    for (int i = 0 ; i < n ; i++){

        users[i] = demande();

    }

    return users;

}

struct User affiche(int n, struct User *users){

    for (int j = 0 ; j < n ; j++){

        printf("%s", users[j].name);

    }

}

int main(){

    int n;
    struct User *users = enregistre(&n);
    affiche(users, n);

    free(users);

}
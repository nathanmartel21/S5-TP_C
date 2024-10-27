#include <stdio.h>

int def_random(){

    int a, c, m, graine, resultat, random_num;

    printf("\nSaisissez un premier nombre : ");
    scanf(" %d", &a);

    printf("\nSaisissez un deuxième nombre : ");
    scanf(" %d", &c);

    printf("\nSaisissez un troisième nombre : ");
    scanf(" %d", &m);

    printf("\nSaisissez la graine : ");
    scanf(" %d", &graine);

    for(int i = 0;i < 10;i++){

        random_num = (graine * a + c) % m;
        printf("%d - Le résultat est de : %d\n", i+1 ,random_num);
        graine = random_num;

    }

}

int main(){

    def_random();

}
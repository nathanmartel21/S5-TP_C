#include <stdio.h>
#include <time.h>

int premiere_valeur() {
    return (int) time(NULL) % 16;
}

int def_random() {

    int a = 75;
    int c = 74;
    int m = 65537;
    int resultat, random_num;

    int graine = premiere_valeur();

    for(int i = 0; i < 10; i++) {
        random_num = (graine * a + c) % m;
        printf("%d - Le résultat est de : %d\n", i +1, random_num);
        graine = random_num;
    }

}

int main() {
    def_random();
}

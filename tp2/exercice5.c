#include <stdio.h>

int main() {
    char phrase[100];
    int count[26] = {0};
    int i;

    printf("Entrez une phrase : ");
    fgets(phrase, sizeof(phrase), stdin);

    for (i = 0; phrase[i] != '\0'; i++) {
        if (phrase[i] >= 'a' && phrase[i] <= 'z') {
            count[phrase[i] - 'a']++;
        }
    }

    printf("Occurrences des lettres minuscules :\n");
    for (i = 0; i < 26; i++) {
        printf("%c : %d\n", 'a' + i, count[i]);
    }

}
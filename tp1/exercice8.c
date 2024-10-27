#include <stdio.h>

int main(){

	int n1, n2, n3, n4, n5, n6;
	int somme_pair = 0;
	int nb_impair = 0;
	int somme_total;

	printf("\nEntrer le premier entier : ");
	scanf(" %d", &n1);

	printf("\nEntrer le deuxième entier : ");
	scanf(" %d", &n2);

	printf("\nEntrer le troisième entier : ");
	scanf(" %d", &n3);

	printf("\nEntrer le quatrième entier : ");
	scanf(" %d", &n4);

	printf("\nEntrer le cinquième entier : ");
	scanf(" %d", &n5);

	printf("\nEntrer le sixième entier : ");
	scanf(" %d", &n6);

	somme_pair += (n1 % 2 == 0) ? n1 : 0;
	nb_impair += (n1 % 2 != 0) ? 1 : 0;

	somme_pair += (n2 % 2 == 0) ? n2 : 0;
	nb_impair += (n2 % 2 != 0) ? 1 : 0;

	somme_pair += (n3 % 2 == 0) ? n2 : 0;
	nb_impair += (n3 % 2 != 0) ? 1 : 0;

	somme_pair += (n4 % 2 == 0) ? n4 : 0;
	nb_impair += (n4 % 2 != 0) ? 1 : 0;

	somme_pair += (n5 % 2 == 0) ? n5 : 0;
	nb_impair += (n5 % 2 != 0) ? 1 : 0;

	somme_pair += (n6 % 2 == 0) ? n6 : 0;
	nb_impair += (n6 % 2 != 0) ? 1 : 0;

	somme_total = somme_pair * nb_impair;

	printf("\nLe résultat est %d\n", somme_total);

}


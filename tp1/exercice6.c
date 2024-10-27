#include <stdio.h>

int main(){

	char lettre1;
	char lettre2;
	char lettre3;

	printf("Première lettre du premier prenom :");
	scanf(" %c", &lettre1);

	printf("\nPremiere lettre du deuxieme prenom :");
	scanf(" %c", &lettre2);

	printf("\nPremiere lettre du troisieme prenom :");
	scanf(" %c", &lettre3);

	if (lettre1 < lettre2 && lettre1 < lettre3){
		if (lettre2 < lettre3){
			printf("Ordre alphabétique : %c %c %c", lettre1, lettre2, lettre3);
		} else {
			printf("Ordre alphabétique : %c %c %c", lettre1, lettre3, lettre2);
		}
	} else if (lettre2 < lettre1 && lettre2 < lettre3){
		if (lettre1 < lettre3){
			printf("Ordre alphabétique : %c %c %c", lettre2, lettre1, lettre3);
		} else {
			printf("Ordre alphabétique : %c %c %c", lettre2, lettre3, lettre1);
		}
	} else {
		if (lettre1 < lettre2){
			printf("Ordre alphabétique : %c %c %c", lettre3, lettre1, lettre2);
		} else {
			printf("Ordre alphabétique : %c %c %c", lettre3, lettre2, lettre1);
		}
	}
}

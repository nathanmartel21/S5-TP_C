#include <stdio.h>
#include <stdlib.h>

int main(){

	int entier1;
	int entier2;

	int va_entier1;
	int va_entier2;

	printf("Saisissez un premier entier : ");
	scanf("%d", &entier1);

	printf("\nSaisissez un deuxième entier : ");
	scanf("%d", &entier2);

	if (entier1 > entier2){
		printf("\nL'entier %d est le plus grand", entier1);
	} else {
		printf("\nL'entier %d est le plus grand", entier2);
	}

	va_entier1 = abs ( entier1 );
	va_entier2 = abs ( entier2 );

	printf("\nLa valeur absolue du premier entier est %d et pour le deuxieme %d",va_entier1,va_entier2);

	if (va_entier1 > va_entier2){
		printf("\nL'entier avec la plus grand valeur absolue : %d",va_entier1);
	} else {
		printf("\nL'entier avec la plus grand valeur absolue : %d",va_entier2);
	}



}

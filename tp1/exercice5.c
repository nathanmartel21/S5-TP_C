#include <stdio.h>

int main(){

	float rayon;
	printf("Donner un flottant pour le rayon d'un cercle : ");
	scanf("%f", &rayon);


	float surface;
	surface = 3.1415926535 * rayon * rayon;

	printf("\nLa surface du cercle est de : %f", surface);

	float perimetre;
	perimetre = 2 * 3.1415926535 * rayon;

	printf("\nLe perimetre du cercle est de %f",  perimetre);
}

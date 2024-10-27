#include <stdio.h>

int main(){
	
	int tableau[5];
	int min, max;
	int i;

	printf("Entrer 5 entiers : \n");
	for (i = 0; i < 5; i++){
		scanf(" %d", &tableau[i]);
	}	
	
	min = tableau[0];
	max = tableau[0];

	for(i = 0; i < 5; i++){
		if (tableau[i] < min){
			min = tableau[i];
		}
		if (tableau[i] > max){
			max = tableau[i];
		}
	}

	printf("\nL'entier le plus petit du tableau est %d", min);
	printf("\nL'entier le plus grand du tableau est %d", max);

}


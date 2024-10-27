#include <stdio.h>

int main(){

	float moyenne = 0;
	int somme_total = 0;
	int entier;
	int nb_entier = 0;

	do{
		
		//if (entier != -1){
		//	somme_total += entier;
		//	nb_entier++;
		//}

		printf("\nEntrer un entier positif : ");
		scanf(" %d", &entier);

		somme_total += entier;
		//printf("ST : %d", somme_total);
		//printf("INT : %d",entier);

		nb_entier++;

	} while(entier != -1);

	nb_entier--;
	somme_total++;

	moyenne = (somme_total + 1) / nb_entier;
	//printf("ST %d", somme_total);

	printf("La moyenne de ces %d entiers vaut %.6f\n",nb_entier,moyenne);
}

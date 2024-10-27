#include <stdio.h>

int main(){
	
	char lettre1;
	int age1;
	float tpc1;
	float point1;
	int distance1;

	char lettre2;
	int age2;
	float tpc2;
	float point2;
	int distance2;

	printf("Pour la première personne, donnez les valeurs suivantes :\n\n");

	printf("\nPrénom : ");
	scanf(" %c", &lettre1);

	printf("\n Age : ");
	scanf(" %d", &age1);

	printf("\nTemps pour courir 100m : ");
	scanf(" %f", &tpc1);

	printf("\nDistance parcourue : ");
	scanf(" %d", &distance1);
	
	point1 = ((distance1/tpc1)*(distance1/tpc1))/age1;

	printf("\n\nPour la deuxième personne, donnez les valeurs :\n\n");

	printf("\nPrénom : ");
	scanf(" %c", &lettre2);

	printf("\n Age : ");
	scanf(" %d", &age2);

	printf("\nTemps pour courir 100m : ");
	scanf(" %f", &tpc2);

	printf("\nDistance parcourue : ");
	scanf(" %d", &distance2);
	
	point2 = ((distance2/tpc2)*(distance2/tpc2))/age2;	

	char gagnant;

	if (point1 > point2){
		gagnant = lettre1;
	} else {
		gagnant = lettre2;
	}

	printf("Le gagnant est %c\n", gagnant);

	if (gagnant == lettre1 && lettre1 < lettre2){
		printf("Bravo\n");
	} else if (gagnant == lettre2 && lettre2 < lettre1){
		printf("Bravo\n");
	} else {
		printf("Désolé\n");
	}

}

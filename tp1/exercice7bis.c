#include <stdio.h>
#include <string.h>

//mode1 :
int main(){

	int entier1, entier2, entier3, entier4, entier5;
	int mode;
	int enentier = 0;

	printf("Choisissez le mode (1 pour entrer 5 entiers, 2 pour découder un entier) : ");
	scanf(" %d", &mode);

	if (mode == 1){

		printf("Entier 1 : ");
		scanf(" %d", &entier1);

		enentier |= (entier1 & 0x3F) << 24; //parce que du coup 32/5 = 6,... donc 3F = 00 11 11 11

		printf("Entier 2 : ");
		scanf(" %d", &entier2);

		enentier |= (entier2 & 0x3F) << 18;

		printf("Entier 3 : ");
		scanf(" %d", &entier3);

		enentier |= (entier3 & 0x3F) << 12;

		printf("Entier 4 : ");
		scanf(" %d", &entier4);

		enentier |= (entier4 & 0x3F) << 6;

		printf("Entier 5 : ");
		scanf(" %d", &entier5);

		enentier |= (entier5 & 0x3F);

		printf("Entier de 32 bits est : %d\n", enentier);
	} else if (mode == 2){

		printf("Entrer un entier de 32 bits : ");
		scanf(" %d", &enentier);

		entier1 = (enentier >> 24) & 0x3F;
		entier2 = (enentier >> 18) & 0x3F;
		entier3 = (enentier >> 12) & 0x3F;
		entier4 = (enentier >> 6) & 0x3F;
		entier5 = enentier & 0x3F;

		printf("\nEntier 1 : %d\n", entier1);
	        printf("\nEntier 2 : %d\n", entier2);
		printf("\nEntier 3 : %d\n", entier3);
		printf("\nEntier 4 : %d\n", entier4);
		printf("\nENtier 5 : %d\n", entier5);	
	       		
		



	}

}



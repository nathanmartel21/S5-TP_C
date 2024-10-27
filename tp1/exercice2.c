#include <stdio.h>
int main(){
	int nombre;
	printf("Donner un nombre pair ou impair : \n");
	scanf("%d", &nombre);
	printf("\nVous avez saisi le nombre %d", nombre);

	if (nombre % 2){
		printf("\nLe nombre est impair\n");
	}
	else{
		printf("\nLe nombre est pair\n");
	}
}

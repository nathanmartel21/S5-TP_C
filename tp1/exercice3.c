#include <stdio.h>
int main(){
	int age;	
	printf("Donner votre âge :\n");
	scanf("%d", &age);
	
	if(age < 5){
		printf("Votre billet est gratuit\n");
	}
	else if(age > 5 && age < 19){
		printf("Votre billet est de 15 euros\n");
	}
	else if(age > 20 && age < 60){
		printf("Votre billet est de 50 euros\n");
	}
	else if(age > 60){
		printf("Votre billet est de 10 euros\n");
	}
	else{
		printf("Age impossible\n");
	}


}

#include<stdlib.h>
#include<stdio.h>
int annee = 10001;

int main() {
	while (annee > 10000 || annee < 0)
	{
		printf("Entrez l'annee choisi :");
		scanf_s("%d", &annee);
	}
	/*printf("L'annee");
	if (annee % 400 == 0 || (annee % 4 == 0 && !(annee % 100 == 0))){
		printf(" est ");
	}
	else {
		printf(" n'est pas ");
	}
	printf("bissextile");*/
	//############    Autre méthode ###############
	printf("L'annee");
	if (annee % 400 == 0) {
		printf(" est ");
	}
	else {
		if (annee % 100==0) {
			printf(" n'est pas ");
		}
		else {
			if (annee % 4 == 0) {
				printf(" est ");
			}
			else {
				printf(" n'est pas ");
			}
		}
		
	}
	printf("bissextile");
}
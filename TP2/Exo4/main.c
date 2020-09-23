#include<stdlib.h>
#include<stdio.h>

int jeu = 1;
int i = 0;

int main() {
	srand(5);
	int nombre = rand();
	int choix;
	//printf("%u",nombre);
	while (jeu) { //Tant que le jeu est en cours
		printf("\nSaisissez une valeur :");
		scanf_s("%d",&choix);
		if (choix == nombre) { //Si bon choix
			jeu = 0;
		}
		else {
			if (choix > nombre) { //Si la valeur est trop grande
				printf("Trop grand");
			}
			else {
				printf("Trop petit");
			}
		}
		i++;
	}
	printf("Jeu fini avec %d test", i);
}
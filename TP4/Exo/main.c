#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int tableau[100];
int main() {
	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < 100; i++) {
		
		int value = (rand() % 20) + 1;
		tableau[i] = value;
	}
	printf("Saisissez la valeur a chercher : ");
	int search=0;
	scanf_s("%d", &search);
	int	a = 0;
	for (int i = 0; i < 100; i++) {
		int* Curseur;
		Curseur = &tableau[i];
		if (*Curseur == search && a == 0) {
			printf("La valeur %d a ete trouvee en %d ",search, i);
			a++;
		}
		else if (*Curseur == search && a == 1) {
			printf("puis en %d, ",i);
		}
	}
	if (a == 0) {
		printf("Aucune valeur trouvee");
	}
}
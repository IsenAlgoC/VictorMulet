#include<stdlib.h>
#include<stdio.h>

int main() {
	char prenom[20];
	char nom[20];
	char sexe;
	printf("Saisissez votre nom : ");
	scanf_s("%s", nom,20);
	printf("Saisissez votre prenom : ");
	scanf_s("%s", prenom,20);
	printf("Saisissez votre sexe : (H/F)");
	sexe = _getch();
	printf("\n");
	if (sexe == 'H')
		printf("Monsieur ");
	else printf("Madame ");
	printf("%s %s", nom, prenom);
}
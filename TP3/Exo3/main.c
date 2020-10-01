#include<stdlib.h>
#include<stdio.h>
#define nbmaxnotes 30
#include<math.h>

int indice=-1;
int nbnote = 30;
float note[nbmaxnotes];
int arret = 0,arret_complet =0;
int absence = 0;
float variance;
float moyenne = 0.f;
int min = 21;
int max = -1;
double somme=0;
void affichage(float tableau[],int index[],  int size, int a) { //affichage d'un tableau en "carré"
	int compteur = 0;
	for (int j = 0; j < size; j++) {
		if (a == 1)printf("Rang:	");
		printf("No Note	Valeur note\n");
		printf("%d	",compteur);
		if (a == 1)printf("%d	", index[j]);
		printf("%.2f", tableau[compteur]);
		printf("\n");
		compteur++;
	}
		
}
void tri(float tableau[], float index[], int size) {
	float tmp;
	float ind;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (tableau[j] < tableau[j + 1]) {
				tmp = tableau[j];
				ind = index[j];
				index[j] = index[j + 1];
				tableau[j] = tableau[j + 1];
				index[j + 1] = ind;
				tableau[j + 1] = tmp;
			}
		}
	}
	}
int main() {
	for (int i = 0; i < nbmaxnotes; i++) note[i] = -2; //création du tableau
	while ((indice < nbmaxnotes) && (arret_complet == 0)) {
		indice++;
		printf("Saisissez la note no %d (entre 0 et 20)", indice);
		scanf_s("%f", &note[indice]);
		arret = 0;
		moyenne = 0;
		while (((float)note[indice] < 0.f || (float)note[indice]>20.f) && (arret == 0)) {
			printf("Eleve absent ? Ou voulez-vous arreter la saisie des notes ? A/O/N : ");
			char choice;
			scanf_s("%c", &choice);
			switch (choice)
			{
			case 'O':
			case 'o':
				note[indice] = -2;
				arret_complet = 1;
				arret = 1;
				break;
			case 'A':
			case 'a':
				note[indice] = -1;
				absence += 1;
				arret = 1;
				break;
			case 'N':
			case 'n':
				printf("Resaisissez la note : ");
				scanf_s("%f", &note[indice]);
				break;
			default:
				printf("Erreur de saisie");
				break;
			}
		}
	}
	for (int i = 0; i < indice; i++) {
		if (note[i] != -1.f && note[i] != -2.f) {
			moyenne += note[i];
			if (min > note[i])min = note[i];
			if (max < note[i])max = note[i];
		}
	}
	moyenne /= indice;
	for (int i = 0; i < indice; i++) {
		if (note[i] != -1.f) { 
			somme += pow((double)(note[i] - moyenne), 2);
			}
	}
	variance = (1.f/(indice-1))*somme;
	printf("Valeur de l'ecart-type : %.10f\n\n", sqrt(variance));
	printf("Vous avez entre %d notes, %d absences, la moyenne est de %.2f, la note min est de %d et la note max est de %d\n\n", indice,absence,moyenne,min,max);
	affichage(note, note, indice, 0);
	printf("\n");
	int index[nbmaxnotes];
	for (int i = 0; i < indice; i++)	index[i] = i; //creation du tableau d'indice
	tri(note, index, indice);
	affichage(note, index, indice, 1);
	printf("\nBye !");
}
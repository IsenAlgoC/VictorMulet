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
void affichage(float tableau[], int size) { //affichage d'un tableau en "carré"
	int compteur = 0;
	for (int j = 0; j < (int)(sqrt(size))+1; j++) {//partie entière sup
		for (int k = 0; k < (int)(sqrt(size)); k++) {//partie enitère min
			printf(" %f ", tableau[compteur]);
			compteur++;

		}
		printf("\n");
	}
}
/*void tri(float tableau[], int size,) {
	for (int i = 0; i < size - 1; i++) {
		for (int k = 0; k < size - i - 1; i++) {
			if (tableau[k] > tableau[k + 1]) {
				float j = tableau[k];
				tableau[k] = tableau[k + 1];
				tableau[k + 1] = j;
			}
		}
	}
}*/
int main() {
	for (int i = 0; i < nbmaxnotes; i++) note[i] = -2; //création du tableau
	while ((indice < nbmaxnotes) && (arret_complet == 0)) {
		indice++;
		printf("Saisissez la note no %d (entre 0 et 20)", indice);
		scanf_s("%f", &note[indice]);
		arret = 0;
		moyenne = 0;
		while ((note[indice] < 0.f || note[indice]>20.f) && (arret == 0)) {
			printf("Elève absent ? Ou voulez-vous arrêter la saisie des notes ? A/O/N : ");
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
			somme += pow((note[i] - moyenne), 2);
			}
	}
	printf("somme = %f", somme);
	variance = (1.f/(indice-1))*somme;
	printf("ecart-type : %.10f\n", sqrt(variance));
	printf("Vous avez entré %d notes, %d absences, la moyenne est de %.2f, la note min est de %d et la note max est de %d\n", indice,absence,moyenne,min,max);
	affichage(note, nbmaxnotes);
}
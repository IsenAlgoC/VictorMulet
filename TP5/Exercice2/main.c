#include <stdlib.h>
#include<stdio.h>
#define TAILLEINITIALE 100
typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;
TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = malloc(TAILLEINITIALE * sizeof(int));
	for (int i = 0; i < TAILLEINITIALE; i++) {
		tab.elt[i] = 0;
	}
	return tab;
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {//Augmenter la taille du tableau
	int* save = tab->elt;
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	if (tab->elt == NULL) {//Si l'adresse est NULL
		tab->elt = save;
		return -1;
	}
	for (int i = 0; i < incrementValue; i++) {
		tab->elt[tab->size + i] = 0;
	}
	tab->size += incrementValue;
	return tab->size;
}
int setElement(TABLEAU* tab, int pos, int element) {//Définir une valeur à sa position
	if (pos < 1) {//Si la position est incohérente
		return 0;
	}
	if (pos > tab->size) {//Si la position est plus loin que la taille du tableau
		incrementArraySize(tab, pos - tab->size);
	}
	if (tab->elt == NULL) {//Si l'adresse est NULL
		return 0;
	}
	tab->elt[pos-1] = element;
	return pos;
}
int displayElements(TABLEAU* tab, int startPos, int endPos) { //Afficher les éléments dans l'intervalle
	if (startPos >= endPos ) {
		int indice = endPos;
		endPos = startPos;
		startPos = indice;
	}
	if (tab->elt == NULL || startPos<1 || endPos > tab->size) {//Si valeurs incohérentes sur les indices ou adresse NULL
		return -1;
	}
	for (int i = startPos; i <= endPos; i++) {
		printf("%d ", tab->elt[i - 1]);
	}
	return 0;
}
int deleteElements(TABLEAU* tab, int startPos, int endPos) {//Détruit les éléments dans l'intervalle des positions
	if (startPos >= endPos) {
		int indice = endPos;
		endPos = startPos;
		startPos = indice;
	}
	if (tab->elt == NULL || endPos > tab->size || startPos < 1) {//Si valeurs incohérentes sur les indices ou adresse NULL
		return -1;
	}
	int* tab2 = tab->elt;//Création d'un tableau qui stocke les éléments
	int c = 0;
	for (int i = 0; i<tab->size;i++) {
		if (i<(startPos - 1) || i>(endPos - 1)) {//Modification des éléments dans le tableau si l'indice est en dehors de l'intervalle
			tab->elt[c] = tab2[i];
			c++;
		}
	}
	tab->size -= endPos - startPos + 1;
	return tab->size;
}
int main() {
	TABLEAU tab;
	tab = newArray();
	setElement(&tab,3,10);
	setElement(&tab, 2, 11);
	setElement(&tab, 1, 12);
	setElement(&tab, 4, 10);
	displayElements(&tab, 1, 5);
	deleteElements(&tab, 1, 3);
	displayElements(&tab, 1, 6);
	setElement(&tab, 11, 15);
	displayElements(&tab, 1, 15);
}


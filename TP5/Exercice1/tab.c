#include <stdlib.h>
#include<stdio.h>
#include "tab.h"

int* myTab2 = NULL;

int initTab(int* tab, int size) { //Initialisation du tableau avec des 0
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
		return size;
	}
}
int afficheTab(int* tab, int size, int nbElts) { //Affichage des nbElts premiers éléments
	if (size < 0 || tab == NULL || size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
		return 0;
	}
}
int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) { //Ajouter un élément dans le tableau
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		if (*nbElts >= *size) { //S'il n'y a pas assez de place, on ajoute 50 cases
			int* test_tab = tab;
			tab = (int*)realloc(tab, (*size + TAILLAJOUT) * sizeof(int));
			if (test_tab == NULL) {
				tab = test_tab;
				return -1;
			}
			for (int i = 0; i < TAILLAJOUT; i++) {
				*(tab + *size + i) = 0;
			}
			*size += TAILLAJOUT;
		}
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return *nbElts;
	}
}
int main() {
	int myTab1[10];
	int nbElmts = 20;
	int size = TAB2SIZE;
	myTab2 = (int*)malloc(100 * sizeof(int));
	initTab(myTab2, TAB2SIZE);
	if (myTab2 != NULL) {
		for (int i = 0; i < 20; i++) {
			myTab2[i] = i + 1;
		}
	}
	afficheTab(myTab2, size, 90);
	nbElmts = 105;
	ajoutElementDansTableau(myTab2, &size, &nbElmts, 15);
	printf("%d",afficheTab(myTab2, size, 106));
	free(myTab2);
}
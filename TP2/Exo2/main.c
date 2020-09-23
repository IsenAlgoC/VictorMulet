#include<stdlib.h>
#include<stdio.h>

float h = 0.f;
float l = 0.f;
float p = 0.f;

int verification(float n,int a) { //Vérification des dimensions du bagage
	if (0.f < n && n <= 56.f - a * 10) { return 1; }
	else { return 0; }
}
void echanger(float* a, float* b) { //echange des termes
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void tri(float* a, float* b, float* c) { //tri décroissant
	if (*a < *b) {
		echanger(a, b);
	}
	if (*b < *c) {
		echanger(b, c);
	}
	if (*a < *b) {
		echanger(a, b);
	}
}

	int main() {
	while (h<=1.f || h>=150 || l <= 1.f || l >= 150 || p <= 1.f || p >= 150) { //Rentrer des dimensions conformes
		printf("Saisissez les dimensions de vos bagages :");
		scanf_s("%f", &h);
		scanf_s("%f", &l);
		scanf_s("%f", &p);
	}
	tri(&h, &l, &p);
	
	while (!(verification(h, 0) && verification(l, 2) && verification(p, 3))) { //Tant que toutes les dimensions ne sont pas validées
		printf("Colis non ");
	}
	printf("valide");
}
#include<stdlib.h>
#include<stdio.h>
float revenus = -1.f;
float imposable = 0;

int main() {
	while (revenus < 0) {
		printf("Saisissez vos revenus : ");
		scanf_s("%f", &revenus);
	}
	if (revenus > 9700 && revenus <= 26791) { imposable = revenus * 0.14; }
	else if (revenus > 26791 && revenus <= 71826) { imposable = revenus * 0.3; }
	else if (revenus > 71826 && revenus <= 152108) {imposable = revenus * 0.41;	}
	else if (revenus > 152108) { imposable = revenus * 0.45; }
	printf("Vous etes impose de %f euros !", imposable);
}
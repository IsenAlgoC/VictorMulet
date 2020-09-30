#include<stdlib.h>
#include<stdio.h>
unsigned int nb = 2868838400;
int main() {
	printf("%d octets pris par le nombre", sizeof(nb));
	printf("\n%d bits pris par le nombre", 8 * sizeof(nb));
	for (int i = 0; i < (8 * sizeof(nb)); i++) {
		printf("\nbit %d : ", i);
		if (1 << i & nb) printf("ON"); //Test si l'indice i de bit est à 1
		else printf("OFF");
	}
	printf("\nBye !");
}
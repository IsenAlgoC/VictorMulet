#include<stdio.h>
#include<stdlib.h>
int n;
unsigned short int sum1 = 0;
int sum2 = 0;
unsigned short int sum3 = 0;
n = 100;
int i = 1;
int j = 1;
unsigned short int SUM = 0; //valeur maximale 65 535
int n1;

int main() {
	printf("Donner la somme des :");
	scanf_s("%hu", &n1);
	for (i; i < (int)n1 + 1; i++) {
		SUM = sum1;
		sum1 += i;
		if (SUM >= sum1) { //Si dépassement donc resultat qui chute brutalement
			printf("Changez la valeur de n, calcul impossible :");
			scanf_s("%hu", &n1);
			i = 0;
		}
		}
	printf("Valeur de la somme : %d", sum1);
	i = 0;
	while (i < n+1) {
	sum2 += i;
		i++;
	}
	do {
		SUM = sum3;
		sum3 += j;
		j++;
	}
	while ( j<n+1);
	printf("n = %d sum = %d ou %d",n, sum2, sum3);                                             
}
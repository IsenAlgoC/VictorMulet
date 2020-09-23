#include<stdio.h>
#include<stdlib.h>
int n;
int sum1 = 0;
int sum2 = 0;
int sum3 = 0;
n = 100;
int i = 1;
int j = 1;

int main() {
	for (i; i < n + 1; i++) {
		sum1 += i;
		}
	printf("n = %d, sum = %d",n, sum1);
	i = 0;
	while (i < n+1) {
		sum2 += i;
		i++;
	}
	do {
		sum3 += j;
		j++;
		printf("boucle");
	}
	while ( j<n+1);
	printf("sum = %d ou %d", sum2, sum3);
}
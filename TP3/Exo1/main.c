#include<stdio.h>
#include<stdlib.h>
#define carre(x) (x)*(x);//Oblig� car sinon le carr� fait le calcul en "ligne" : 5+1*5+1 (sans priorit� du *)
int nb = 5;
int main() { 
	int a = carre(nb+1);
	printf("%d", a);
}

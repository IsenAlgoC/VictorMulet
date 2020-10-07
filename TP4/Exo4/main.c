#include<stdlib.h>
#include<stdio.h>
int main() {
	char mot[30];
	printf("Saisissez votre mot : ");
	scanf_s("%s", mot, 30);
	int a = strlen(mot);
	char palindrome = 1;
	for (int i = 0; i < strlen(mot); i++) {
		char a = *(mot + i);
		if (a > 90 && a < 97 || a < 65 || a>123) {
			a = 32;
		}
		if (a <= 90 && a >= 65) {
			a += 32;
		}
		*(mot + i) = a;
	}
	printf("%s",mot);
	for (int i = 0; i < (int)strlen(mot) / 2; i++) {
		char a = *(mot+i);
		char b = *(mot+strlen(mot)-i-1);
		if (a != b) palindrome = 0;
	}
	if (palindrome == 1) printf("C'est un palindrome !");
	else printf("Ce n'est pas un palindrome !");

}
#include<stdlib.h>
#include<stdio.h>

int main() {
	char buffer[1024];
	printf("Saisissez votre phrase : ");
	gets_s(buffer,1024);
	int mots = 1;
	float longueur = 0.f;
	for (int i = 0; i < strlen(buffer); i++) {
		char a = *(buffer + i);
		if ((a > 90 && a < 97) || a < 65 || a>123) {
			mots++;
		}
		else {
			longueur++;
		}
	}
	longueur /= mots;
	printf("%d mots,%.2f longueur moyenne", mots, longueur);
}
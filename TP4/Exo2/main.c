#include<stdlib.h>
#include<stdio.h>

#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {
	int mytab1[TAILLETAB1];
	for (int i = 1; i < TAILLETAB1 + 1; i++) mytab1[i - 1] = i;
	for (int i = 0; i < TAILLETAB1; i++) {
		printf("%d", mytab1[i]);
		if (i< TAILLETAB1 - 1){
			printf("%c", SEPARATEUR); }
	}
	printf("\n");
	for (int i = TAILLETAB1 - 1; i >= 0; i--) {
		int* MyPtr;
		MyPtr = &mytab1[i];
		printf("%d", *MyPtr);
		if (i > 0) {
			printf("%c", SEPARATEUR);
		}
	}
}
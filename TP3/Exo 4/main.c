#include<stdlib.h>
#include<stdio.h>

char add_w = 192;
char add_x = 168;
char add_y = 129;
char add_z = 10;
char addr_w;
char addr_x;
char addr_y;
char addr_z;
char addb_w;
char addb_x;
char addb_y;
char addb_z;
char mask = 24;
unsigned char maskx = 0;
unsigned char masky = 0;
unsigned char maskz = 0;
unsigned char maskw = 0;
int main() {
	/*printf("Saisissez votre adresse : w.x.y.z/n\n");
	printf("w = \n");
	scanf_s("%u", &add_w);
	printf("x = \n");
	scanf_s("%u", &add_x);
	printf("y = \n");
	scanf_s("%u", &add_y);
	printf("z = \n");
	scanf_s("%u", &add_z);
	printf("n = \n");
	scanf_s("%d", &mask);*/
	for (int i = 0; i < mask; i++) {
		int indice = 31 - i;
		if (indice >= 24) {
			maskw = maskw | (1 << indice%8);
		}
		else {
			if (indice >= 16) maskx = maskx | 1 << indice%8;
			else {
				if (indice >= 8)	masky = masky | 1 << indice%8;
				else {
					if (indice >= 0) maskz = maskz | 1 << indice%8;
				}
			}
		}
	}
	printf("%u . %u . %u . %u", maskw, maskx, masky, maskz);
	addr_w = addr_w & maskw;
	addr_x = addr_x & maskx;
	addr_y = addr_y & masky;
	addr_z = addr_z & maskz;
	printf("%u", (char)~maskz);
	addb_w = addb_w | ~(maskw);
	addb_x = addb_x | ~(maskx);
	addb_y = addb_y | ~(masky);
	addb_z = addb_z | ~(maskz);
	printf("%u . %u . %u . %u", addb_w, addb_x, addb_y, addb_z);

}
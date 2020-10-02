#include<stdlib.h>
#include<stdio.h>

unsigned char add_w = 192;
unsigned char add_x = 168;
unsigned char add_y = 129;
unsigned char add_z = 10;
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
	printf("adresse IPv4 : %u.%u.%u.%u / %d\n",add_w,add_x,add_y,add_z, mask);
	printf("adresse du reseau : %u.%u.%u.%u / %d\n", add_w & maskw, add_x & maskx, add_y & masky, add_z & maskz,mask);
	maskw = ~(unsigned char)maskw;
	maskx = ~(unsigned char)maskx;
	masky = ~(unsigned char)masky;
	maskz = ~(unsigned char)maskz;
	printf("adresse broadcast : %u.%u.%u.%u", add_w | maskw, add_x | maskx, add_y | masky, add_z | maskz);

}
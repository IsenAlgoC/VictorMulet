#include "tp4.h"
#include <stdlib.h>
#include<stdio.h>

int main() {
	HEURE debut,duree,fin;
	debut.heure = 12, debut.min = 30;
	duree.heure = 0, duree.min = 45;
	fin.min = (duree.min + debut.min) % 60;
	fin.heure = (int)(duree.min + debut.min) / 60;
	printf("%d:%d debut, %d:%d duree, %d:%d fin", debut.heure, debut.min, duree.heure, duree.min, debut.heure + fin.heure, debut.min + fin.min);
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int pgcd(int a, int b) {

	int def = a > b ? a - b : b - a;

	if((a > b ? b : a) != def)
	{
		return pgcd((a > b ? b : a), def);
	}
	
	return a > b ? b : a;
}

void main() {
	
	char retry = 'y';

	do {

		int a = 0, b = 0;
		retry = 'n';
	
		printf("Entrez un nombre\n");
		scanf("%d", &a);
	
		printf("Entrez un nombre\n");
		scanf("%d", &b);

		printf("le PGCD entre %d et %d est %d\n", a, b, pgcd(a, b));

		printf("Retry ? [y|n]\n");

		retry = getch();

	} while (retry == 'y');
}
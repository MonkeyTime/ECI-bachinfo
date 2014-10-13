#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define VECTOR_MAX 100

void main() {

	int i = 0, max = 0;
	int val[VECTOR_MAX] = {0};

	do {

		printf("Combien de note voulez vous encoder (max 100) ?\n");

		scanf("%d", &max);

		if(max > VECTOR_MAX) 
		{
			printf("Valeur trop elevee, veuillez en choisir une autre...\n");
		}

	} while(max > VECTOR_MAX);

	printf("Commencer l'encodage...\n");

	for(i = 0; i < max; i++) {

		scanf("%d", &val[i]);

		printf("Valeur %d est %d\n", i , val[i]);
	}

	getch();
}
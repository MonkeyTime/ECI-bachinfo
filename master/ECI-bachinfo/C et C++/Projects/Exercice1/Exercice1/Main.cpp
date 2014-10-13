#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void main() {
	
	int a, b, c;
	double delta, result1, result2;

	a = b = c = 0;
	result1 = result2 = delta = 0;

	printf("Entrez une valeur pour a: ");
	scanf("%d", &a);
	printf("Entrez une valeur pour b: ");
	scanf("%d", &b);
	printf("Entrez une valeur pour c: ");
	scanf("%d", &c);

	delta : b * b - 4 * a * c;

	if(delta < 0)
	{
		printf("Pas de racine");
	}
	else if (delta > 0)
	{
		result1 = (-b + sqrt(delta)) / (2 * a);
		result2 = (-b - sqrt(delta)) / (2 * a);

		printf("\nRacine 1: %f\nRacine2: %f", result1, result2);
	}
	else // == 0
	{
		result1 = -(b / (2 * a));
		printf("\nRacine double = %f", result1);
	}

	getch();

}

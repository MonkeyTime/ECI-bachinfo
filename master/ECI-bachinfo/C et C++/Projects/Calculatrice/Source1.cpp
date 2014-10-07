#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void main() {

	do 
	{
		float op1, op2, result;
		char sign, retry;

		printf("continue[y|n]");
		retry = getch();

		printf("Entrez un nombre:\n");
		scanf("%f", &op1);

		printf("choisissez: +, -, * ou /\n");
		sign = getch();

		printf("Entrez un nombre:\n");
		scanf("%f", &op2);

		if(sign != '/' && op2 != 0)
		{
			switch(sign)
			{
				case('+'):
					result = op1 + op2;
				break;

				case('-'):
					result = op1 - op2;
				break;

				case('*'):
					result = op1 * op2;
				break;

				case('/'):
					result = op1 / op2;
				break;

				default:
					return;
			}

		} else {

			printf("Division par zero !");
		}

	} while(retry == 'y');
}

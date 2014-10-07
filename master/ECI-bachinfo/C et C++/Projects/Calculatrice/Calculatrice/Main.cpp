#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void main() {

	char retry = 'y';

	do 
	{
		float op1, op2, result;
		char sign;

		printf("calculatrice[y|n]\n");
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

			printf("%f %c %f = %f", op1, sign, op2, result);
			printf("\n--------------------------------------------\n");

		} else {

			printf("Division par zero !\n");
		}

	} while(retry == 'y');
}

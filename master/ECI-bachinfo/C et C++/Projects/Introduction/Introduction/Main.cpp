#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


void main() {

	char exercice = '1';
	
	do 
	{
		printf("Choisir un exercice: 1 est plus grand que, 2 nbr croissant, 3 batiment, 4 batiment, q pour quitter\n");
		exercice = getch();

		float op1 = 0, op2 = 0, sum = 0, age = 0, a = 0, b = 0, c = 0, delta = 0;

		switch(exercice)
		{
			case('1'):
				printf("Entrez un nombre:\n");
				scanf("%f", &op1);
				printf("Entrez un nombre:\n");
				scanf("%f", &op2);
				printf("%f est plus grand que %f\n", 
					    op1 > op2 ? op1 : op2, 
						op1 < op2 ? op1 : op2
					  );
			break;

			case('2'):
				printf("Entrez un nombre:\n");
				scanf("%f", &op1);
				printf("Entrez un nombre:\n");
				scanf("%f", &op2);
				printf("%f < %f\n", 
					    op1 < op2 ? op1 : op2, 
					    op1 > op2 ? op1 : op2
					  );
			break;

			case('3'):
				printf("Montant du batiment:\n");
				scanf("%f", &sum);
				printf("Age du batiment:\n");
				scanf("%f", &age);
				printf("Total facture maison: %f + %f = %f (tva %d pourcent)\n", 
						sum, 
						age > 15 ? sum * 0.06 : sum * 0.21, 
						age > 15 ? sum * 1.06 : sum * 1.21,
						age > 15 ? 6 : 21
					  );
			break;

			case('4'):
				printf("Montant du batiment:\n");
				scanf("%f", &sum);
				printf("Age du batiment:\n");
				scanf("%f", &age);
				printf("Total facture maison: %f + %f = %f (tva %d pourcent)\n", 
						sum, 
						age <= 15 ? sum * 0.21 : sum * 0.06, 
						age <= 15 ? sum * 1.21 : sum * 1.06,
						age <= 15 ? 21 : 6
					  );
			break;

			case('5'):
				
				printf("Valeur pour a:\n");
				scanf("%f", &a);
				printf("Valeur pour b: \n");
				scanf("%f", &b);
				printf("Valeur pour c:\n");
				scanf("%f", &c);

				delta = (b * b) - (4 * a * c);

				if(delta > 0) {

				}
				else if(delta == 0) {

				}
				else {

				}

			break;

			default:
			break;
		}

	} while(exercice != 'q');
}

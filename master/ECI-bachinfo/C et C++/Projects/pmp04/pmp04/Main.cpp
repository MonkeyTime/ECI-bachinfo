#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {

	char choice = '1';

	do {

		printf("1 loop nbr reel, 2 loop au carre, 3 loop recherche, q pour quitter\n");

		choice = getch();

		switch(choice) {

			case('1'):

					float arrayListFloat[10];
					int i;
					float entry;

					for(i = 0; i < 10; i++)
					{
						entry = 0;

						printf("Entre un nombre reel\n");
						scanf("%f", &entry);

						arrayListFloat[i] = entry;
					}

					for(i = 0; i < 10; i++)
					{
						printf("nombre reel entrez : %f\n", arrayListFloat[i]);
					}

			break;

			case('2'):

					int arrayListInt[10];

					for(i = 1; i <= 10; i++)
					{
						arrayListInt[i-1] = i*i;
						printf("nombre entier au %d au carre = %d\n",i, arrayListInt[i-1]);
					}

			break;

			case('3'):

					int arrayListSearch[10];
					int biggest, current, previous;

					arrayListSearch[0] = 34;
					arrayListSearch[1] = 48;
					arrayListSearch[2] = 6;
					arrayListSearch[3] = 5;
					arrayListSearch[4] = 3;
					arrayListSearch[5] = 18;
					arrayListSearch[6] = 56;
					arrayListSearch[7] = 229;
					arrayListSearch[8] = 9;
					arrayListSearch[9] = 34;

					for(i = 0; i < 10; i++)
					{
						if(i == 0) {
							current = arrayListSearch[i];
							previous = arrayListSearch[i];
							biggest = arrayListSearch[i];
						}
						else {

							current = arrayListSearch[i];
							previous = arrayListSearch[i - 1];

							biggest = current > previous ? current : previous;
						}

					}

					printf("le + grand nbr est %d\n",biggest);

			break;

			case('4'):

			break;

			default:
				return;
		}

	} while(choice != 'q');
}
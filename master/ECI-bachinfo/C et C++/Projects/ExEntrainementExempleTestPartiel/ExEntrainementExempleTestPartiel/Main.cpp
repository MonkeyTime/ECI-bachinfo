#include<stdio.h>
#include<conio.h>
#include<random>
#include<time.h>

#define MAX_DAYS 31
#define MAX_MONTHS 12

bool isBisextile(int year);

/**
 * main
 *
 */
void main() {

	srand(time(NULL));

	char rebuild = ' ';
	int i = 0;
	bool reverse;
	double sum;
	double random;
	double totals[12] = {0};
		
	int maxDayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
	if(isBisextile(2014)) {
			
		int maxDayInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	}

	double values[MAX_DAYS][MAX_DAYS] = {0};

	do {

		if(i > 0) {
			printf("\n");
		}

		printf("Choisissez le menu: 1 Initialiser l'array, 2 Generation des temperatures, 3 Impression des donnees, 4 Impression des moyennes mensuelles, 5 Permutation lignes/colonnes\n");
		rebuild = getch();

		i++;

		switch(rebuild) {

			case('0'):
				return;

			case('1'):

				for(int i = 0; i < MAX_DAYS; i++) {

					for(int j = 0; j < MAX_DAYS; j++) {

						values[i][j] = 0.0;
					}
				}

				reverse = true;

				printf("\nValeurs de l'array \"values\" innitilisees a zero\n");

			break;

			case('2'):

				if(values[0][0] != 0 && values[MAX_DAYS][MAX_DAYS] != 0) {

					printf("\nVous devez d'abord initialiser l'array values a zero (option 1)\n");

					break;
				}

				sum = 0;
				random = 0;

				if(!reverse) {

					for(int i = 0; i < MAX_MONTHS; i++) {
		
						totals[i] = 0;

						for(int j = 0; j < maxDayInMonth[i]; j++) {

							values[i][j] = ((rand() % 700) - 300) / 10.0;

							totals[i] += values[i][j];
						}
					}

				} else {

					for(int i = MAX_MONTHS; i >= 0; i--) {
		
						totals[i] = 0;

						for(int j = maxDayInMonth[i]; j >= 0; j--) {

							values[i][j] = ((rand() % 700) - 300) / 10.0;

							totals[i] += values[i][j];
						}
					}
				}

				printf("\nArray values initialisees\n");

			break;

			case('3'):

				if(!reverse) {

					printf("\n");

					for(int i = 0; i < MAX_MONTHS; i++) {

						for(int j = 0; j < maxDayInMonth[i]; j++) {

							printf("%6.1f", values[i][j]);
						}

						printf("\n");
					}

				} else {

					for(int i = MAX_MONTHS; i >= 0; i--) {

						for(int j = maxDayInMonth[i]; j >= 0; j--) {

							printf("%6.1f", values[i][j]);
						}

						printf("\n");
					}
				}

			break;

			case('4'):

				if(!reverse) {

					printf("\n");

					for(int i = 0; i < MAX_MONTHS; i++) {

						switch(i + 1) {

							case(1):
								printf("Mois de janvier: ");
							break;

							case(2):
								printf("Mois de fevrier: ");
							break;

							case(3):
								printf("Mois de mars: ");
							break;

							case(4):
								printf("Mois d'avril: ");
							break;

							case(5):
								printf("Mois de mai: ");
							break;

							case(6):
								printf("Mois de juin: ");
							break;

							case(7):
								printf("Mois de juillet: ");
							break;

							case(8):
								printf("Mois d'aout: ");
							break;

							case(9):
								printf("Mois de septembre: ");
							break;

							case(10):
								printf("Mois d'octobre: ");
							break;

							case(11):
								printf("Mois de novembre: ");
							break;

							case(12):
								printf("Mois de decembre: ");
							break;

							default:
							break;				
						}

						printf("%6.1f\n", totals[i] / 10.0);
					}

				} else {

					printf("\n");

					for(int i = 11; i >= 0; i--) {
		
						sum = 0;

						switch(i + 1) {

							case(1):
								printf("Mois de janvier: ");
							break;

							case(2):
								printf("Mois de fevrier: ");
							break;

							case(3):
								printf("Mois de mars: ");
							break;

							case(4):
								printf("Mois d'avril: ");
							break;

							case(5):
								printf("Mois de mai: ");
							break;

							case(6):
								printf("Mois de juin: ");
							break;

							case(7):
								printf("Mois de juillet: ");
							break;

							case(8):
								printf("Mois d'aout: ");
							break;

							case(9):
								printf("Mois de septembre: ");
							break;

							case(10):
								printf("Mois d'octobre: ");
							break;

							case(11):
								printf("Mois de novembre: ");
							break;

							case(12):
								printf("Mois de decembre: ");
							break;

						}

						printf("%6.1f\n", totals[i] / 10.0);
					}
				}

			break;

			case('5'):

				reverse = (reverse == true) ? false : true;

				printf("\nLes valeurs ont etes permutees (choisir 3 ou 4 pour voir)\n");

			break;

			default:

				printf("\nMauvais menu, merci de choisir un numero de menu valide\n");

			break;
		}


	} while(rebuild != '0');
}

/**
 * isBisextile
 *
 * @param int	The current Year
 *
 * @return bool
 *
 */
bool isBisextile(int year) {

	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}
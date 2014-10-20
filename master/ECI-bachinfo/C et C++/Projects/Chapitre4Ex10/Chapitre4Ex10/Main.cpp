#include<stdio.h>
#include<conio.h>
#include<random>
#include<time.h>

#define MAX_MONTH 12

bool isBisextile(int year);

/**
 * main
 *
 */

void main() {

	int maxDayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(isBisextile(2014)) {

		int maxDayInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	}

	double sum = 0; 
	double random = 0;

	srand(time(NULL));

	for(int i = 0; i < MAX_MONTH; i++) {
		
		sum = 0;

		for(int j = 0; j < maxDayInMonth[i]; j++) {

			random = ((rand() % 700) - 300) / 10.0;

			printf("%6.1f", random);

			sum += random;
		}

		printf("|%10.1f\n", sum / 10.0);
	}

	getch();
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
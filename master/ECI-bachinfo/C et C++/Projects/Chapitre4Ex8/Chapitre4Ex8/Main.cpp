#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 10

void reverseTabLine(int sender[], int recever[]);
void display(int tab[MAX_SIZE][MAX_SIZE]);

/**
 * main
 *
 */
void main() {

	int tab[MAX_SIZE][MAX_SIZE];
	int reversedTab[MAX_SIZE][MAX_SIZE];

	for(int i = 0; i < MAX_SIZE; i++) {

		for(int j = 0; j < MAX_SIZE; j++) {

			tab[i][j] = (i + 1) * (j + 1);
			printf("%4d", tab[i][j]);
		}

		reverseTabLine(tab[i], reversedTab[i]);

		printf("\n");
	}

	printf("\n");

	display(reversedTab);

	getch();
}

/**
 * reverseTabLine
 *
 * reverse a tab values and push it in another
 *
 * @param int[]		The sender tab
 * @param int[]		The resever tab
 *
 * @return void
 */
void reverseTabLine(int sender[], int recever[]) {
	
	int temp1; 
	int temp2;

	for(int i = 0; i < MAX_SIZE / 2; i++) {

		temp1 = sender[MAX_SIZE - i - 1];
		temp2 = sender[i];

		recever[i] = temp1;
		recever[MAX_SIZE - i - 1] = temp2;
	}
}

/**
 * display
 * 
 * display 2 dimensional array to the console output
 *
 * @param int[][]	The 2 dimensions array to display
 *
 * @return void
 *
 */
void display(int tab[MAX_SIZE][MAX_SIZE]) {
	
	for(int i = 0; i < MAX_SIZE; i++) {

		for(int j = 0; j < MAX_SIZE; j++) {

			printf("%4d", tab[i][j]);
		}

		printf("\n");
	}
}
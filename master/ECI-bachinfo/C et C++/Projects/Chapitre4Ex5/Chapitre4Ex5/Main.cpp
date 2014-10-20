//include
#include<stdio.h>
#include<conio.h>

//define
#define MAX_SIZE 10

//declare func
void display(int tab[MAX_SIZE]);

/**
 * main
 *
 * assign values to each tab 1, display each tab1 value, assign tab2[i] = tab1[i], display each tab2 value
 *
 */
void main() {

	int tab1[MAX_SIZE] = {0};
	int tab2[MAX_SIZE] = {0};

	//initialize
	for(int i = 0; i < MAX_SIZE; i++) {

		tab1[i] = (i + 1) * (i + 1);
	}

	//separator
	printf("---------------------\nTableau 1\n---------------------\n");

	//display
	display(tab1);

	//assign tab1 to tab2
	for(int i = 0; i < MAX_SIZE; i++) {
		
		tab2[i] = tab1[i];
	}

	//separator
	printf("---------------------\nTableau 2\n---------------------\n");

	//display
	display(tab2);

	getch();
}

/**
 * display
 * 
 * display array to the console output
 *
 * @param int[]		The array to display
 *
 * @return void
 *
 */
void display(int tab[MAX_SIZE]) {
	
	for(int i = 0; i < MAX_SIZE; i++) {

		printf("%21d\n", tab[i]);
	}
}
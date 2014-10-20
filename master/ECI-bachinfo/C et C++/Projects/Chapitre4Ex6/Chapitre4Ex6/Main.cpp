#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 10

int sum(int add1, int add2);
void display(int tab[MAX_SIZE]);


/**
 * main
 *
 */
void main() {

	int tab1[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int tab2[MAX_SIZE] = {0};

	display(tab1);

	for(int i = 0; i < MAX_SIZE; i++) {

		tab2[i] = (i == 0) ? tab1[i] : sum(tab2[i - 1], tab1[i]);
	}

	display(tab2);

	getch();
}

/**
 * sum
 *
 * simple addition
 *
 * @param int
 * @param int
 *
 * @return int
 *
 */
int sum(int add1, int add2) {

	return add1 + add2;
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

		printf("%d\n", tab[i]);
	}
}
#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 10

void main() {

	int tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int temp1, temp2;
	
	for(int i = 0; i < MAX_SIZE; i++) {
		printf("%d\n", tab1[i]);
	}

	for(int i = 0; i < MAX_SIZE / 2; i++) {

		temp1 = tab1[MAX_SIZE - i - 1];
		temp2 = tab1[i];

		tab1[i] = temp1;
		tab1[MAX_SIZE - i - 1] = temp2;
	}

	for(int i = 0; i < MAX_SIZE; i++) {
		printf("%d\n", tab1[i]);
	}

	getch();
}
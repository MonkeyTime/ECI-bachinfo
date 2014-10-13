#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nbre=2,cpt=0;

	while (cpt<10)
	{
		printf("\n %d",nbre);
		nbre=nbre+2;
		cpt=cpt+1;
	}
	getch();
}
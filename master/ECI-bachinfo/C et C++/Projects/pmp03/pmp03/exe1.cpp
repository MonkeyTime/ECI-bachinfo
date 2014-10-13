#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{

	int cpt=0,nbre=0;

	printf("Les 10 premiers nombres:");

	while (cpt<10)
	{
		printf("%d ",nbre);
		nbre=nbre+1;
		cpt=cpt+1;
	}
	getch();
	
}

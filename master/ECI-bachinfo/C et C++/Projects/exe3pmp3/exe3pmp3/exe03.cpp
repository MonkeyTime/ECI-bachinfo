#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nbre=0;

	while(nbre<10)
	{
		printf("\nle carre de %d est %d",nbre,nbre*nbre);
		nbre=nbre+1;
	}
	getch();
}
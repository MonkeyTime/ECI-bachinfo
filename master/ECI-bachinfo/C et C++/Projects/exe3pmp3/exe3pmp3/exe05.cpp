#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nbre=2,cpt=0,pairs=0;

	printf("Combien de nombres pairs voulez-vous afficher?");
	scanf("%d",&pairs);


	while (cpt<pairs)
	{
		printf("\n %d",nbre);
		nbre=nbre+2;
		cpt=cpt+1;
	}
	getch();
}
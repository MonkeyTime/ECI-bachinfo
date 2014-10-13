#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void main(void)
{
	int dlimite=0,flimite=0,cpt=0;

	printf("debut de la limite:");
	scanf("%d",&dlimite);
	printf("fin de la limite:");
	scanf("%d",&flimite);
	printf("%d %d \n",dlimite,flimite);

	if (dlimite<flimite)
	{
		while(dlimite<(flimite-1))
		{
			printf("%d ",++dlimite);
			//dlimite=dlimite+1;
		}
	}
	if (dlimite>flimite)
	{
		while((dlimite-1)>flimite)
		{
			printf("%d ",--dlimite);
			//dlimite=dlimite-1;
		}
	}

	if(dlimite==flimite)
	{
		printf("debut egale a la fin!");
	}
	getch();


}

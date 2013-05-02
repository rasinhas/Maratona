#include <stdio.h>

int main()
{
	int teste = 1, aldo, beto, entradas, n1, n2, i;
	while(1)
	{
		scanf( "%d", &entradas );
		if(entradas == 0)
			return 0;
		aldo = 0;
		beto = 0;
		for(i=0;i<entradas;i++)
		{
			scanf( "%i%i", &n1, &n2 );
			aldo += n1; 
			beto += n2;
		}
		printf( "Teste %i\n", teste );
		if(aldo > beto)
			printf("Aldo\n");
		else
			printf("Beto\n");
		teste++;
	}
	return 0;
}


#include <stdio.h>

int main()
{
	int n, i, cont=1, aux, ganhador;

	while(1)
	{   
		scanf("%d", &n);
		if(n == 0)
			return 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &aux);
			if(aux == i)
			{
				ganhador = i;
			}
		}
		printf("Teste %d", cont);
		printf("\n%d\n\n", ganhador);
		cont ++;
	} 
	return 0;
}


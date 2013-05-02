#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cont[101], A, V, teste=1, i, X, Y, maior;
	while(1)
	{
		scanf("%d %d", &A, &V);
		for(i=0;i<A;i++)
		{
			cont[i] = 0;
		}
		maior = 0;
		if(A == 0)
			return 0;
		for(i=0;i<V;i++)
		{
			scanf("%d %d", &X, &Y);
			cont[X-1]++;
			cont[Y-1]++;
		}
		for(i=0;i<A;i++)
		{
			if(cont[i] > maior)
			{
				maior = cont[i];
			}
		}
		printf("Teste %d\n", teste);
		for(i=0;i<A;i++)
		{
			if(cont[i] == maior)
			{
				printf("%d ", i+1);
			}
		}
		printf("\n\n");
		teste++;
	}
}



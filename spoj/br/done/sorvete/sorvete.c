#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int main()
{
	int praia[10100];
	int inter, tam, ini, fim, ant, i, j, teste=1;
	while(scanf("%d %d", &tam, &inter) && tam)
	{
		for(i=0;i<tam+1;i++)
			praia[i] = 0;
		for(i=0;i<inter;i++)
		{
			scanf("%d %d", &ini, &fim);
			for(j=ini;j<fim;j++)
				praia[j] = 1;
		}
		ant = 0;
		printf("Teste %d\n", teste++);
		for(i=0;i<tam+1;i++)
		{
			if(praia[i] == 1 && ant == 0)
				printf("%d ", i);
			if(praia[i] == 0 && ant == 1)
				printf("%d\n", i);
			ant = praia[i];
		}
		printf("\n");
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int topo, i, N, D, val, substituidos;
	char entrada[100000];
	int resultado[100000];
	while(1)
	{
		scanf("%d", &N);
		scanf("%d", &D);
		topo = -1;
		substituidos = 0;
		if(N == 0 && D == 0)
			return 0;
		getchar();
		for(i=0;i<N;i++)
		{
			scanf("%c", &entrada[i]);
		}
		for(i=0;i<N;i++)
		{
			val = (int)entrada[i] - 48;		
			while(topo != -1 && resultado[topo] < val && substituidos < D)
			{
				topo--;
				substituidos++;
			}
			topo++;
			resultado[topo] = val;
		}
		while(substituidos < D)
		{
			topo--;
			substituidos++;
		}
		for(i=0;i<N-D;i++)
			printf("%d", resultado[i]);
		printf("\n");
	}
	return 0;
}


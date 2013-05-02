#include <stdio.h>

int main()
{
	int votos, vet[101][101], sum[101], max, i, j;
	while(1)
	{
		scanf("%d", &votos);
		for(i=0;i<votos;i++)
			sum[i] = 0;
		if(votos == 0)
			return 0;
		for(i=0;i<votos;i++)
		{
			for(j=0;j<votos;j++)
				scanf( "%d", &vet[i][j]);
		}
		for(i=0;i<votos;i++)
		{
			for(j=0;j<votos;j++)
			{
				sum[i] += vet[j][i];
			}
		}
		max = sum[0];
		for(i=1;i<votos;i++)
		{
			if(sum[i]>max)
				max = sum[i];
		}
		printf("%d\n", max);
	}
}


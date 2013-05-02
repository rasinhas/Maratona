#include <stdio.h>
#define INF 0x3f3f3f
#define FOR(i,n) for(i=0;i<(n);i++)
#define min(a,b) a < b ? a : b

int main()
{
	int Mat[61][61];
	int freq[61][61];
	int N;
	int i, j, k, minimo, teste=1;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		FOR(i,N+1)
		{
			FOR(j,N+1)
			{
				Mat[i][j] = 0;
				freq[i][j] = 0;
			}
		}
		FOR(i,N)
		{
			scanf("%d ", &freq[i][i+1]);
			Mat[i][i+1] = freq[i][i+1];
		}
		for(i=0;i<N+1;i++)
		{
			for(k=i+2;k<N+1;k++)
			{
				freq[i][k] = freq[i][k-1] + freq[k-1][k];
			}
		}
		for(i=2;i<N+1;i++)
		{
			for(k=0;k<N-i+1;k++)
			{
				minimo = INF;
				for(j=0;j<i;j++)
				{
					minimo = min(minimo, Mat[k][k+j] + Mat[k+j+1][i+k]);
				}
				//printf("%d\n", minimo);
				Mat[k][k+i] = freq[k][k+i] + minimo;
			}
		}
		printf("Teste %d\n%d\n\n", teste++, Mat[0][N]-freq[0][N]);

		/*		for(i=0;i<N+1;i++)
				{
				for(j=0;j<N+1;j++)
				{
				printf("%d ", Mat[i][j]);
				}
				printf("\n");
				}
		 */
	}
}



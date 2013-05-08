#include <stdio.h>
#define FOR(i, n) for(i=0;i<n;i++)

int main()
{
	int Mat[1000][1000];
	int P, N, C, Palitos, Tam;
	int i, j;
	while(1)
	{
		scanf("%d %d %d", &P, &N, &C);
		if(P == 0)
			return 0;
		FOR(i, N)
		{
			FOR(j, P)
			{
				scanf("%d", &Mat[i][j]);
			}
		}
		Palitos = 0;
		FOR(i, P)
		{
			Tam = 0;
			FOR(j, N)
			{
				if(Mat[j][i] == 1)
				{
					Tam += 1;
				}
				if(Tam >= C && (Mat[j][i] == 0 || j == N-1))
				{
					Palitos++;
					Tam = 0;
				}
				if(Mat[j][i] == 0)
					Tam = 0;
			}
		}
		printf("%d\n", Palitos);
	}
}



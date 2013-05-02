#include <stdio.h>
#define INF 0x3f3f3f

int main()
{
	int var;
	int N, M, T[10000];
	int min, max, aux;
	int i, k, teste=1;
	while(1)
	{
		scanf("%d %d", &N, &M);
		if(N == 0)
			return 0;
		var = 0;
		max = -INF;
		min = INF;
		k = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d", &T[i]);
			var += T[i];		
			if(k >= M-1)
			{
				aux = var/M;
				if(aux > max)
					max = aux;
				if(aux < min)
					min = aux;
				var -= T[i-M+1];
			}
			k++;
		}
		printf("Teste %d\n%d %d\n\n", teste++, min, max);
	}
}



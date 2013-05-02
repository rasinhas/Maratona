#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int main()
{
	int t=1, i, n, soma, val, sol, para;
	while(scanf("%d", &n) != EOF)
	{
		para = 0;
		soma = 0;
		sol = -10000;
		for(i=0;i<n;i++)
		{
			scanf("%d", &val);
			if(soma == val && !para)
			{
				sol = val;
				para = 1;
			}
			soma += val;
		}
		printf("Instancia %d\n", t++);
		if(sol == -10000)
			printf("nao achei\n\n");
		else
			printf("%d\n\n", sol);
	}
	return 0;
}



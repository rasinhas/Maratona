#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

int main()
{
	int i, j, n, c, k, p, m;
	int cont[110];
	while(scanf("%d %d %d", &n, &c, &k) && n)
	{
		for(i=1;i<=k;i++)
			cont[i] = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d", &p);
				cont[p]++;
			}
		}
		m = INF;
		for(i=1;i<=k;i++) if(cont[i] < m) m = cont[i];
		for(i=1;i<=k;i++)
		{
			if(cont[i] == m)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int mat[1100][1100];

int main()
{
	int i, j, n, m, x, y, xtot, ytot, teste=1;
	while(scanf("%d %d", &n, &m) && n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		xtot = 0;
		ytot = 0;
		while(scanf("%d %d", &x, &y) && (y || x))
		{
			xtot += x;
			ytot += y;
		}
		while(xtot < 0)
			xtot = m + xtot;
		while(ytot < 0)
			ytot = n + ytot;
		xtot = m - (xtot % m);
		ytot = ytot % n;
		printf("Teste %d\n", teste++);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d", mat[((i+ytot)%n)][((j+xtot)%m)]);
				if(j != m-1)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int main()
{
	int pilha[1001][1001];
	int i, j, n, p, cx, h, x, y, minesq, mindir, aux, minimo;
	while(scanf("%d %d", &n, &p) && n)
	{
		for(i=0;i<p;i++)
		{
			scanf("%d", &h);
			for(j=0;j<h;j++)
			{
				scanf("%d", &cx);
				if(cx == 1)
				{
					x = j;
					y = i;
				}
				pilha[i][j] = h-j;
			}
			pilha[i][h] = 0;
			pilha[i][h+1] = 0;
		}
		mindir = 0;
		minesq = 0;
		for(i=y;i<p;i++)
		{
			mindir += pilha[i][x];
			if(pilha[i][x] == 0)
				break;
		}
		for(i=y;i>=0;i--)
		{
			minesq += pilha[i][x];
			if(pilha[i][x] == 0)
				break;
		}
		minimo = min(mindir, minesq);
		printf("%d\n", minimo-1);
	}
	return 0;
}



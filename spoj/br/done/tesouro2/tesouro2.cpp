#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>

#define rep(i,n) for(i=0;i<(n);i++)
#define INF 0x3f3f3f3f

using namespace std;

int peso[1010], d[1010], grafo[1010][1010], grau[1010], n, k;
int vis[1010], ordem[1010], grafo2[1010][1010], grau2[1010];

void dfs(int a)
{
	int i;
	vis[a] = k;
	for(i=0;i<grau[a];i++) if(!vis[grafo[a][i]]) dfs(grafo[a][i]);
	ordem[k--] = a;
}

int maxcaminho(int a)
{
	int i, tmax = 0;
	for(i=0;i<grau2[a];i++) tmax = max(tmax, (d[grafo2[a][i]] + peso[a]));
	return tmax;
}

int main()
{
	int i, j, tmax, n, c, p, m;
	while(scanf("%d", &n) && n)
	{
		k = n+1;
		for(i=0;i<=n+1;i++)
		{
			vis[i] = 0;
			grau[i] = 1;
			grau2[i] = 1;
			d[i] = 0;
			peso[i] = 0;
			grafo[0][i] = i;
			grafo[i][0] = n+1;
			grafo2[n+1][i] = i;
		}
		grafo[n+1][0] = 0;
		grau[n+1] = 0;
		grau[0] = n+1;
		grau2[n+1] = n+1;
		grau2[0] = 0;
		peso[n+1] = 1;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d", &peso[i], &m);
			for(j=0;j<m;j++) 
			{
				scanf("%d", &p);
				grafo[i][grau[i]++] = p;
				grafo2[p][grau2[p]++] = i;
			}
		}
		dfs(0);

		/*
		   for(i=0;i<n+2;i++)
		   {
		   printf("%d ## ", i);
		   for(j=0;j<grau2[i];j++) printf("%d ", grafo2[i][j]);
		   printf("\n");
		   }

		   printf("\n");
		   for(i=0;i<n+2;i++)
		   {
		   printf("%d ## ", i);
		   for(j=0;j<grau[i];j++) printf("%d ", grafo[i][j]);
		   printf("\n");
		   }
		 */

		//for(i=0;i<n+2;i++) printf("%d ", ordem[i]);
		//printf("\n");
		for(i=1;i<n+2;i++) d[ordem[i]] = maxcaminho(ordem[i]);
		//rep(i,n+2) printf("%d ", d[i]-1);
		printf("%d\n", d[n+1]-1);
	}
	return 0;
}



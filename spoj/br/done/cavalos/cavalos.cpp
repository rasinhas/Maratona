#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <cassert>

#define INF 0x3f3f3f3f
#define SOURCE (0)
#define SINK (m+n+1)
#define PESSOA(k) (k+1)
#define CAVALO(k) (k+m+1)

#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int m, n, k;
int matadj[210][210], pai[210], vis[210];

void dfs(int v)
{
	int i;
	vis[v] = 1;
	if(v == 0)
	{
		for(i=0;i<m+n+2;i++)
		{
			if(matadj[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if (vis[SINK]) return;
			}
		}
	}
	else
	{
		for(i=m+n+1;i>=0;i--)
		{
			if(matadj[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if (vis[SINK]) return;
			}
		}
	}
}

int fluxo()
{
	int k, p, i, ret=0;
	while(1)
	{
		for(i=0;i<m+n+2;i++) vis[i]=0, pai[i]=-1;
		dfs(SOURCE);
		if(!vis[SINK]) break;
		for(k=SINK; pai[k]!=-1; k=pai[k]) matadj[pai[k]][k]--, matadj[k][pai[k]]++;
		ret++;
	}
	return ret;
}

int main()
{
	int i, j, u, v, flux, t=1;
	while(scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for(i=0;i<n+m+2;i++)
		{
			for(j=0;j<n+m+2;j++) matadj[i][j] = 0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d", &flux);
			matadj[CAVALO(i)][SINK] = flux;
		}
		for(i=0;i<m;i++) matadj[SOURCE][PESSOA(i)] = 1;
		for(i=0;i<k;i++)
		{
			scanf("%d %d", &u, &v);
			u--; v--;
			matadj[PESSOA(v)][CAVALO(u)] = 1;
		}
		/*for(i=0;i<n+m+2;i++)
		  {
		  for(j=0;j<n+m+2;j++)
		  {
		  printf("%d ",matadj[i][j]);
		  }
		  printf("\n");
		  }*/
		printf("Instancia %d\n", t++);
		printf("%d\n\n", fluxo());
	}
	return 0;
}




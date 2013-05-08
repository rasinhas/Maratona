#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

#define INF 0x3f3f3f3f
#define SOURCE (0)
#define SINK (2*n+1)
#define A(k) (k+1)
#define B(k) (n+k+1)
#define MAXVERT (2*n+2)

#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int matadj[210][210], pai[210], vis[210];
int n;

void dfs(int v)
{
	int i;
	vis[v] = 1;
	if(v == SOURCE)
	{
		for(i=1;i<SINK;i++)
		{
			if(matadj[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if(vis[SINK]) return;
			}
		}
	}
	else
	{
		for(i=SINK;i>=0;i--)
		{
			if(matadj[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if(vis[SINK]) return;
			}
		}
	}
}

int fluxo()
{
	int k, p, i, ret=0;
	while(1)
	{
		for(i=0;i<MAXVERT;i++) vis[i]=0, pai[i]=-1;
		dfs(SOURCE);
		if(!vis[SINK]) break;
		for(k=SINK; pai[k]!=-1; k=pai[k]) matadj[pai[k]][k]--, matadj[k][pai[k]]++;
		ret++;
	}
	return ret;
}

int main()
{
	int i, j, k, t, p, x, a;
	scanf("%d", &t);
	for(i=1;i<=t;i++)
	{
		printf("Instancia %d\n", i);
		scanf("%d", &n);
		for(j=0;j<(MAXVERT);j++)
		{
			for(k=0;k<(MAXVERT);k++) matadj[j][k] = 0;
		}
		for(j=0;j<n;j++)
		{
			matadj[SOURCE][A(j)] = 1;
			matadj[B(j)][SINK] = 1;
			scanf("%d", &p);
			for(k=0;k<p;k++)
			{
				scanf("%d", &x);
				x--;
				matadj[A(j)][B(x)] = 1;
			}
		}
		a = fluxo();
		if(a == n)
			printf("pair programming\n\n");
		else
			printf("extreme programming\n\n");
	}
	return 0;
}




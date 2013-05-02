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
#define ONIBUS(k) (k+n+1)

#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int m, n;
int matadj[210][210], pai[210], vis[210], horario[110], copia[210][210];

int clock(char *hora)
{
	int tempo = 0;
	tempo += (hora[0]-48)*1000;
	tempo += (hora[1]-48)*100;
	tempo += (hora[3]-48)*10;
	tempo += (hora[4]-48);
	return tempo;
}

void dfs(int v)
{
	int i;
	vis[v] = 1;
	if(v == 0)
	{
		for(i=0;i<m+n+2;i++)
		{
			if(copia[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if(vis[SINK]) return;
			}
		}
	}
	else
	{
		for(i=m+n+1;i>=0;i--)
		{
			if(copia[v][i] && !vis[i])
			{
				pai[i] = v;
				dfs(i);
				if(vis[SINK]) return;
			}
		}
	}
}

int fluxo(int a)
{
	int k, p, i, j, ret=0;
	for(i=0;i<m;i++)
		copia[ONIBUS(i)][SINK] = a;
	/*for(k=0;k<n+m+2;k++)
	  {
	  for(j=0;j<n+m+2;j++)
	  {
	  printf("%d ",copia[k][j]);
	  }
	  printf("\n");
	  }
	  printf("\n");*/
	while(1)
	{
		for(i=0;i<m+n+2;i++) vis[i]=0, pai[i]=-1;
		dfs(SOURCE);
		if(!vis[SINK]) break;
		for(k=SINK; pai[k]!=-1; k=pai[k]) copia[pai[k]][k]--, copia[k][pai[k]]++;
		ret++;
	}
	return ret;
}

int main()
{
	int i, j, k, l, t, u, tempo, a, p, v, f;
	int hi, lo, mid;
	char hora[7];
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &n, &m);
		for(j=0;j<n+m+2;j++)
		{
			for(k=0;k<n+m+2;k++) matadj[j][k] = 0;
		}
		for(j=0;j<m;j++)
		{
			scanf("%s", hora);
			horario[j] = clock(hora);
		}
		for(j=0;j<n;j++)
		{
			scanf("%d", &u);
			matadj[SOURCE][PESSOA(j)] = 1;
			for(k=0;k<u;k++)
			{
				scanf("%s", hora);
				tempo = clock(hora);
				for(l=0;l<m;l++)
				{
					if(horario[l] == tempo) matadj[PESSOA(j)][ONIBUS(l)] = 1;
				}
			}
		}
		hi = n;
		lo = 0;
		while(lo < hi)
		{
			mid = (hi + lo)/2;
			for(j=0;j<n+m+2;j++)
			{
				for(k=0;k<n+m+2;k++) copia[j][k] = matadj[j][k];
			}
			a = fluxo(mid);
			if(a < n)
				lo = mid+1;
			else
				hi = mid;
		}
		printf("%d\n", lo);
	}
	return 0;
}



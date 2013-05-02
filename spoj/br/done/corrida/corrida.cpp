#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>

#define INF 0x3f3f3f3f

using namespace std;

int peso[200][200], d[200], grafo[200][200], grau[200], n;
int vis[200];

inline void dijkstra(int s)
{
	int u, v, i;
	d[s]=0;
	priority_queue<pair<int,int> > Q; 
	Q.push(make_pair<int,int>(-d[s],s)); 
	while(!Q.empty())
	{      
		u=Q.top().second;
		if(u == n+s)
			return;
		Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for(i=0; i<grau[u]; i++)
		{
			v=grafo[u][i];
			if(d[v]>d[u]+peso[u][v])
			{
				d[v]=d[u]+peso[u][v];
				Q.push(make_pair<int,int>(-d[v],v));
			}
		}
	}
}

int main()
{
	int i, j, k, m, u, v, c, t, minimo;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &n, &m);
		for(j=0;j<2*n;j++)	grau[j]=0;
		for(j=0;j<m;j++)
		{
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			peso[u][v+n] = c;
			peso[v+n][u] = c;
			peso[u+n][v] = c;
			peso[v][u+n] = c;
			grafo[u][grau[u]++] = v+n;
			grafo[v][grau[v]++] = u+n;
			grafo[u+n][grau[u+n]++] = v;
			grafo[v+n][grau[v+n]++] = u;
		}
		minimo = INF;
		for(j=0;j<n;j++)
		{
			for(k=0;k<2*n;k++) d[k] = INF, vis[k] = 0;
			dijkstra(j);
			if(d[n+j] < minimo) minimo = d[n+j];
		}
		if(minimo == INF) printf("impossivel\n");
		else printf("%d\n", minimo);
	}
	return 0;
}



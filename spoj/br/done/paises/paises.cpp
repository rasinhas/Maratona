#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>

using namespace std;

int peso[500][500], d[500], grafo[500][500], grau[500];
int vis[500];

void dijkstra(int s)
{
	int u, v, i;
	d[s] = 0;
	priority_queue<pair<int,int> > Q; 
	Q.push(make_pair<int,int>(-d[s],s)); 
	while(!Q.empty())
	{      
		u=Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(i=0;i<grau[u];i++)
		{
			v = grafo[u][i];
			if(d[v]>d[u]+peso[u][v])
			{
				d[v] = d[u]+peso[u][v];
				Q.push(make_pair<int,int>(-d[v],v));
			}
		}
	}
}

int main()
{
	int n, e, h, x, y, i, j, K, o, dist;
	while(scanf("%d %d", &n, &e) && n)
	{
		for(i=0;i<n;i++) grau[i] = 0;
		for(i=0;i<e;i++)
		{
			scanf("%d %d %d", &x, &y, &h);
			x--; y--;
			peso[x][y] = h;
			grafo[x][grau[x]++] = y;
			for(j=0;j<grau[y];j++)
			{
				if(grafo[y][j]==x)
				{
					peso[x][y] = 0;
					peso[y][x] = 0;
					break;	
				}
			}
		}
		scanf("%d", &K);
		for(i=0;i<K;i++)
		{
			for(j=0;j<n;j++)
			{
				d[j] = 1000000000;
				vis[j] = 0;
			}
			scanf("%d %d", &o, &dist);
			dijkstra(o-1);
			if(d[dist-1] == 1000000000) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n", d[dist-1]);
		}
		printf("\n");
	}
	return 0;    
}



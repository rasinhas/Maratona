#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int peso[110][110], d[110], grafo[110][110], grau[110];
int vis[110];
int mai, ret;

inline void dijkstra(int s)
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
		mai = max(mai, d[u]);
	}
}

int main()
{
	int i, j, n, m, u, v, c;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++) grau[i] = 0;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d", &u, &v, &c);
		peso[u][v] = peso[v][u] = c;
		grafo[v][grau[v]++] = u;
		grafo[u][grau[u]++] = v;
	}
	ret = INF;
	for(i=0;i<n;i++)
	{
		mai = 0;
		for(j=0;j<n;j++)
		{
			d[j] = INF;
			vis[j] = 0;
		}
		dijkstra(i);	
		ret = min(mai, ret);
	}
	printf("%d\n", ret);
	return 0;
}



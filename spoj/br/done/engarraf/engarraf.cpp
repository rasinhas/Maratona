#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0xffffff
#define rep(i,n) for(i=0;i<(n);i++)

using namespace std;

typedef pair <int, int> pii;

int main()
{
	int i, j,  v1, v2, p, end, init, aux, n, m;
	int pesos[110][110], d[100], adj[110][110], grau[110], vis[100]; 
	priority_queue <pii, vector <pii>, greater <pii> > fila;
	pii a;
	while(scanf("%d %d", &n, &m) && n)
	{
		for(i=0;i<n;i++) 
		{
			for(j=0;j<n;j++)
			{
				pesos[i][j] = 0;
				adj[i][j] = -1;
			}
			vis[i] = 0;
			grau[i] = 0;
			d[i] = INF;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d", &v1, &v2, &p);
			v1--; v2--;
			pesos[v1][v2] = p;
			adj[v1][grau[v1]++] = v2;
		}
		scanf("%d %d", &init, &end);
		init--; end--;
		d[init] = 0;
		fila.push(make_pair(d[init], init));
		while(!fila.empty())
		{
			a = fila.top();
			fila.pop();
			if(vis[a.second]) continue;
			vis[a.second]++;
			for(i=0;i<grau[a.second];i++)
			{
				aux = adj[a.second][i];
				if(d[a.second]+pesos[a.second][aux] < d[aux])
				{
					d[aux] = d[a.second]+pesos[a.second][aux];
					fila.push(make_pair(d[aux],aux));
				}
			}
		}
		if(d[end] == INF)
			printf("-1\n");
		else
			printf("%d\n", d[end]);
	}
	return 0;
}




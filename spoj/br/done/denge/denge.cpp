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

int main()
{
	queue <int> fila;
	int i, j, n, x, y, men, dist, a, t=1, p;
	int adj[100][100], grau[100], vis[100], d[100];
	while(scanf("%d", &n) && n)
	{
		for(i=0;i<n;i++) grau[i] = 0;
		for(i=0;i<(n-1);i++)
		{
			scanf("%d %d", &x, &y);
			x--; y--;
			adj[x][grau[x]++] = y;
			adj[y][grau[y]++] = x;
		}
		men = INF;
		for(i=0;i<n;i++)
		{
			dist = 0;
			d[i] = 0;
			for(j=0;j<n;j++) vis[j] = 0;
			fila.push(i);
			vis[i] = 1;
			while(!fila.empty())
			{
				a = fila.front();
				fila.pop();
				for(j=0;j<grau[a];j++)
				{
					if(!vis[adj[a][j]])
					{
						fila.push(adj[a][j]);
						d[adj[a][j]] = d[a] + 1;
						dist = max(dist, d[adj[a][j]]);
						vis[adj[a][j]] = 1;
					}
				}
			}
			if(dist < men)
			{
				men = dist;
				p = i+1;
			}
		}
		printf("Teste %d\n%d\n\n", t++, p);
	}
	return 0;
}




#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int val[8] = {3, 2, 3, 2, 2, 3, 2, 3};
int d[1010][1010], grid[1010][1010], g, r, c, rx, ry, sx, sy;

void Astar()
{
	pair<int,int> u, v;
	int i, len, j, x, y, alagado, k;
	priority_queue<pair<pair<int,int>,pair<int,int> > > Q; 
	d[rx][ry] = 0;
	g = 0;
	Q.push(make_pair<pair<int,int>,pair<int,int> >(make_pair(-g,d[rx][ry]),make_pair(rx,ry))); 
	while(!Q.empty())
	{      
		u = Q.top().second;
		Q.pop();
		if(u.first == sx && u.second == sy)
			break;
		for(i=0;i<8;i++)
		{
			v = make_pair(u.first-dx[i], u.second-dy[i]);
			x = v.first;
			y = v.second;
			alagado = 0;
			k = 0;
			if(grid[x][y] == -1 && grid[u.first][u.second] == -1) k = 1;
			else if(grid[x][y] != -1 && grid[u.first][u.second] == -1) alagado = 1;
			if(!k)
			{
				if(x > 0 && y > 0 && x <= c && y <= r)
				{
					if(d[x][y] > d[u.first][u.second] + val[i] + alagado)
					{
						d[x][y] = d[u.first][u.second] + val[i] + alagado;
						g = d[x][y] - 1.609*(sx-x+sy-y);
						Q.push(make_pair<pair<int,int>, pair<int,int> >(make_pair(-g,-d[x][y]), v));
					}
				}
			}
		}
	}
}

int main()
{
	int i, w, j, k, x1, x2, y1, y2;
	while(scanf("%d %d", &c, &r) && c)
	{
		scanf("%d %d %d %d", &rx, &ry, &sx, &sy);
		scanf("%d", &w);
		for(i=1;i<=c;i++) for(j=1;j<=r;j++) d[i][j] = INF, grid[i][j] = 0;
		for(i=0;i<w;i++)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for(j=x1;j<=x2;j++) for(k=y1;k<=y2;k++) grid[j][k] = -1;
		}
		Astar();
		if(d[sx][sy] == INF)
			printf("impossible\n");
		else
			printf("%d\n", d[sx][sy]);
	}
	return 0;
}



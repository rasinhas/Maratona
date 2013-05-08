#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int grafo[2][600][600], d[3][600], vis[3][600];
int n, m;

void dijkstra(int src, int dest, int k)
{
    int i, a;
    priority_queue<pair<int,int> > f;
    d[k][src]=0;
    f.push(make_pair(0,src));
    while(!f.empty())
    {
        a = f.top().second;
        f.pop();
        if(vis[k][a]) continue;
        vis[k][a] = 1;
        for(i=0;i<n;i++)
        {
            if(grafo[k%2][a][i] && !vis[k][i])
            {
                d[k][i] = min(d[k][i],d[k][a]+grafo[k%2][a][i]);
                f.push(make_pair(-d[k][i],i));
            }
        }
        if(a == dest) break;
    }
}

int main()
{
    int i, j, v, u, p, dmax;
    int src, dest;
    while(scanf("%d%d", &n, &m) && n)
    {
        scanf("%d%d", &src, &dest);
        for(i=0;i<n;i++)
        {
            d[0][i]=inf;
            d[1][i]=inf;
            d[2][i]=inf;
            vis[0][i]=0;
            vis[1][i]=0;
            vis[2][i]=0;
            for(j=0;j<n;j++)
            {
                grafo[0][i][j]=0;
                grafo[1][i][j]=0;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d", &v, &u, &p);
            grafo[0][v][u] = p;
            grafo[1][u][v] = p;
        }
        dijkstra(src, dest, 0);
        dmax = d[0][dest];
        dijkstra(dest, src, 1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[0][i]+d[1][j]+grafo[0][i][j]==dmax) grafo[0][i][j] = 0;
            }
        }
        dijkstra(src,dest, 2);
        if(d[2][dest]==inf) printf("-1\n");
        else printf("%d\n", d[2][dest]);
    }
    return 0;
}

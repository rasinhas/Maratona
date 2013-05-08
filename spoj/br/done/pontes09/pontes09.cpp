#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    int i, u, v, c, a, len, n, m;
    int p[1020][1020], d[1020], vis[1020];
    vector <int> adj[1020];
    priority_queue <pair <int,int> > fila;
    scanf("%d%d", &n, &m);
    memset(vis,0,(n+2)*sizeof(int));
    for(i=0;i<n+2;i++)
    {
        d[i] = inf;
        adj[i].clear();
        memset(p[i],0,(n+2)*sizeof(int));
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(v);
        adj[v].push_back(u);
        p[u][v] = c;
        p[v][u] = c;
    }
    fila.push(make_pair(0,0));
    d[0] = 0;
    while(!fila.empty())
    {
        a = fila.top().second;
        fila.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        len = adj[a].size();
        for(i=0;i<len;i++)
        {
            if(!vis[adj[a][i]])
            {
                d[adj[a][i]] = min(d[a] + p[a][adj[a][i]], d[adj[a][i]]);
                fila.push(make_pair(-d[adj[a][i]], adj[a][i]));
            }
        }
        if(vis[n+1]) break;
    }
    printf("%d\n", d[n+1]);
    return 0;
}

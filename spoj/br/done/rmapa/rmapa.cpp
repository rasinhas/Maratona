#include <stdio.h>
#include <string.h>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m, u, v, sum, i, len, c, a;
    priority_queue <pair<int,int> > fila;
    pair <int, int> b;
    vector <int> adj[600];
    int p[600][600], vis[600];
    scanf("%d %d", &n, &m);
    memset(vis,0,n*sizeof(int));
    for(i=0;i<n;i++) memset(p[i],0,n*sizeof(int));
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d", &u, &v, &c);
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        p[u][v] = p[v][u] = c;
    }
    sum = 0;
    fila.push(make_pair(0,0));
    while(!fila.empty())
    {
        b = fila.top();
        fila.pop();
        a = b.second;
        if(vis[a]) continue;
        sum -= b.first;
        vis[a] = 1;
        len = adj[a].size();
        for(i=0;i<len;i++) if(!vis[adj[a][i]]) fila.push(make_pair(-p[a][adj[a][i]], adj[a][i]));
    }
    printf("%d\n", sum);
    return 0;
}

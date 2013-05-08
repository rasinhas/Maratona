#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector <int> adj[400];
int custo[400][400];
int vis[400], n;

int prim()
{
    int sum = 0;
    int fail=0, i, u, v;
    priority_queue <pair<int,int> > fila;
    for(i=0;i<n;i++)
    {
        if(i>0 && vis[i] == 0)
        {
            fail = 1;
            break;
        }
        if(vis[i]) continue;
        fila.push(make_pair(0, i));
        while(!fila.empty())
        {
            u = fila.top().second;
            if(vis[u])
            {
                fila.pop();
                continue;
            }
            sum -= fila.top().first;
            fila.pop();
            vis[u] = 1;
            for(i=0;i<adj[u].size();i++)
            {
                v = adj[u][i];
                fila.push(make_pair(-custo[u][v], v));
            }
        }
    }
    return fail == 0 ? sum : -1;
}

int main()
{
    int p, e, u, v, t;
    int i, j;
    int pedr[50];
    int pd[220];
    memset(pd,0,sizeof(pd));
    memset(custo,0,sizeof(custo));
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d", &n, &p, &e);
    for(i=0;i<p;i++)
    {
        scanf("%d", &pedr[i]);
    }
    pd[0] = 1;
    for(i=0;i<p;i++)
    {
        for(j=0;j<100;j++)
        {
            pd[j+pedr[i]] += pd[j];
        }
    }
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d", &u, &v, &t);
        u--; v--;
        if(pd[t] > 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            custo[u][v] = custo[v][u] = pd[t];
        }
    }
    printf("%d\n",prim());
    return 0;
}

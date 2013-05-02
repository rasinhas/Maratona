#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

vector <int> adj[10300];
vector <int> adjp[10300];
queue <int> fila;
int vis[10300];
int time_s=1;

int dfs(int u, int pai)
{
    int menor = vis[u] = time_s++;
    int len, i, m;
    len = adj[u].size();
    for(i=0;i<len;i++)
    {
        if(!vis[adj[u][i]])
        {
            m = dfs(adj[u][i], u);
            menor = min(menor,m);
            if(vis[u]<m)
            {
                adjp[u].push_back(adj[u][i]);
                adjp[adj[u][i]].push_back(u);
            }
        }
        else if(adj[u][i]!=pai)
        {
            menor = min(menor, vis[adj[u][i]]);
        }
    }
    return menor;
}

int main()
{
    int r, c, q, u, v;
    int i, conex, len, j;
    while(scanf("%d%d%d", &r, &c, &q) && r != 0)
    {
        for(i=0;i<r;i++)
        {
            adj[i].clear();
            adjp[i].clear();
        }
        conex = 0;
        memset(vis,0,r*sizeof(int));
        for(i=0;i<c;i++)
        {
            scanf("%d%d", &u, &v);
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        memset(vis,0,r*sizeof(int));
        for(i=0;i<r;i++)
        {
            if(!vis[i])
            {
                fila.push(i);
                vis[i] = ++conex;
            }
            while(!fila.empty())
            {
                u = fila.front();
                fila.pop();
                len = adjp[u].size();
                for(j=0;j<len;j++)
                {
                    if(!vis[adjp[u][j]])
                    {
                        fila.push(adjp[u][j]);
                        vis[adjp[u][j]] = conex;
                    }
                }
            }
        }
        for(i=0;i<q;i++)
        {
            scanf("%d%d", &u, &v);
            u--; v--;
            if(vis[u] == vis[v]) printf("Y\n");
            else printf("N\n");
        }
        printf("-\n");
    }
    return 0;
}

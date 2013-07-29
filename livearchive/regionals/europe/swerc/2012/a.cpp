#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <utility>
#define INF 0x3f3f3f3f

using namespace std;

vector <int> adj[600];
int vis[600], n;

int bfs(int p)
{
    int v, u, pi;
    queue <pair<int,int> > q;
    q.push(make_pair(p,-1));
    vis[p] = 1;
    while(!q.empty())
    {
        v = q.front().first;
        pi = q.front().second;
        // pq aqui funciona?
        vis[v] = vis[pi]+1;
        q.pop();
        for(int i=0;i<adj[v].size();i++)
        {
            u = adj[v][i];
            if(vis[u] && u != pi) return vis[u]+vis[v]-1;
            if(!vis[u])
            {
                // e aqui não?
                //vis[u] = vis[v]+1;
                q.push(make_pair(u,v));
            }
        }
    }
    return INF;
}


int main()
{
    int ret;
    int c, m, u, v, t;
    int i, j;
    scanf("%d", &c);
    for(int t=0;t<c;t++)
    {
        scanf("%d%d", &n, &m);
        for(i=0;i<n;i++) adj[i].clear();
        ret = INF;
        for(i=0;i<m;i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(i=0;i<n;i++)
        {
            memset(vis,0,n*sizeof(int));
            ret = min(ret,bfs(i));
        }
        printf("Case %d: ", t+1);
        if(ret == INF) printf("impossible\n");
        else printf("%d\n", ret);
    }
    return 0;
}


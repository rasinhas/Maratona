#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

const long long inf = 1000000000000;
long long d[251];
int vis[251];
vector <int> adj[251];
pair<int,int> edge[25001];
int cost[251][251];
int n, m;

long long dijkstra(int u)
{
    priority_queue <pair<int,int> > q;
    d[u] = 0;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        u = q.top().ss;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=0;i<adj[u].size();i++) 
        {
            int v = adj[u][i];
            if(!vis[v] && d[v] > d[u] + cost[u][v])
            {
                d[v] = d[u] + cost[u][v];
                q.push(make_pair(-d[v],v));
            }
        }
    }
    return d[n-1];
}

int main()
{
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) d[i] = inf;
    for(int i=0;i<m;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[i] = make_pair(a,b);
        cost[a][b] = cost[b][a] = c;
    }
    int dz = dijkstra(0);
    long long r = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            d[j] = inf;
            vis[j] = 0;
        }
        cost[edge[i].ff][edge[i].ss] *= 2;
        cost[edge[i].ss][edge[i].ff] *= 2;
        r = max(r,dijkstra(0)-dz);
        cost[edge[i].ff][edge[i].ss] /= 2;
        cost[edge[i].ss][edge[i].ff] /= 2;
    }
    printf("%lld\n", r);
    return 0;
}

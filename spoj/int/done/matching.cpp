#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define MAXV 100005
#define MAXE 150005
#define cow(v) (v)
#define bull(v) (v+n)
#define nil 0
#define inf 0x3f3f3f3f

using namespace std;

int n, m;
int match[MAXV], dist[MAXV];
vector <int> adj[MAXV];

bool bfs()
{
    int u, v;
    queue <int> q;
    for(int i=0;i<=n;i++)
    {
        if(match[i] == nil)
        {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = inf;
    }
    dist[nil] = inf;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u!=nil)
        {
            for(int i=0;i<adj[u].size();i++)
            {
                v = adj[u][i];
                if(dist[match[v]] == inf)
                {
                    dist[match[v]] = dist[u]+1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (dist[nil]!=inf);
}

bool dfs(int u)
{
    int i, v;
    if(u!=nil)
    {
        for(int i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            if(dist[match[v]] == dist[u]+1)
            {
                if(dfs(match[v]))
                {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = inf;
        return false;
    }
    return true;
}

int hopcroft_karp()
{
    int matching = 0;
    while(bfs()) for(int i=1;i<=n;i++) if(match[i] == nil && dfs(i)) matching++;
    return matching;
}

int main()
{
    int p, u, v;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=0;i<p;i++)
    {
        scanf("%d%d", &u, &v);
        adj[cow(u)].pb(bull(v));
    }
    printf("%d\n", hopcroft_karp());
    return 0;
}

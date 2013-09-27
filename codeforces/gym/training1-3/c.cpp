#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;

int adj[2222][2222];
int adj2[2222][2222];
int vis[2222], l[2222], o=0;
int ve[2222][2222];
vector <pii> b;
vector <pair<pii,int> > e;
int n, m, fs;

int dfsb(int u, int p)
{
    l[u]=vis[u]=++o;
    for(int i=0;i<n;i++)
    {
        if(adj2[u][i])
        {
            if(i != p)
            {
                if(!vis[i]) l[u] = min(l[u],dfsb(i,u));
                else l[u] = min(l[u],vis[i]);
            }
        }
    }
    if(p >= 0 && l[u] >= vis[u]) b.pb(mp(u,p));
    return l[u];
}

int dfs(int u, int p, int s)
{
    int f=0;
    if(vis[u] == 0)
    {
        vis[u] = 1;
        for(int i=0;i<n;i++) if(i != p && adj[u][i]) f = dfs(i,u,s);
        vis[u] = 2;
    }
    else if(u == s) 
    {
        f = 1;
        fs = 1;
    }
    else if(fs == 1) f = 1;
    if(p >= 0 && adj[u][p] == adj[p][u] && !ve[p][u])
    {
        if(f) e.pb(mp(mp(p,u),1));
        else e.pb(mp(mp(u,p),1));
    }
    if(p >= 0) ve[p][u] = ve[u][p] = 1;
    return f;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a][b] = 1;
        adj2[a][b] = adj2[b][a] = 1;
        if(c == 2) adj[b][a] = 1;
    }
    dfsb(0,-1);
    for(int i=0;i<b.size();i++)
    {
        if(adj[b[i].x][b[i].y] == adj[b[i].y][b[i].x]) e.pb(mp(b[i],2));
        adj[b[i].x][b[i].y] = adj[b[i].y][b[i].x] = 0;
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) if(!vis[i])
    {
        fs = 0;
        dfs(i, -1, i);
    }
    for(int i=0;i<e.size();i++) printf("%d %d %d\n",e[i].x.x+1,e[i].x.y+1,e[i].y);
    return 0;
}

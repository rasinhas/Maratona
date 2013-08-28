#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

int g[111111], vis[111111], imp[111111];
int cc=0;
vector <int> adj[111111];

int dfs(int u)
{
    vis[u] = 1;
    imp[cc] += g[u]%2;
    for(int i=0;i<adj[u].size();i++) if(!vis[adj[u][i]]) dfs(adj[u][i]);
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--, b--;
        g[a]++, g[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && g[i]) 
        {
            dfs(i);
            cc++;
        }
    }
    int ret = 0;
    if(cc == 1) ret = imp[0]/2;
    else 
    {
        ret += cc;
        for(int i=0;i<cc;i++) ret += max(0,imp[i]/2-1);
    }
    cout << ret << endl;
    return 0;
}

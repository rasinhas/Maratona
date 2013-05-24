#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define sz size()

using namespace std;

vector <int> adj[1001];
int vis[1001];
int cnt;

void dfs(int u)
{
    vis[u] = 1;
    cnt ++;
    for(int i=0;i<adj[u].sz;i++)
    {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    int n, a, b;
    while(cin >> n && n)
    {
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("(%d,%d)", &a, &b);
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(0);
        cout << cnt << endl;
        for(int i=0;i<1000;i++) adj[i].clear();
        memset(vis,0,sizeof(vis));
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define src ((v)+(c))
#define snk ((v)+(c))+1
#define w(i) ((v)+(i))

using namespace std;

int v, c;
int adj[1111][1111], pai[1111], vis[1111];
string d[555];

bool match(string k, string p)
{
    int c[30];
    memset(c,0,sizeof(c));
    for(int i=0;i<k.size();i++) c[k[i]-'a']++;
    for(int i=0;i<p.size();i++) 
    {
        c[p[i]-'a']--;
        if(c[p[i]-'a'] < 0) return 0;
    }
    return 1;
}

int dfs(int u, int p)
{
    int r = 0;
    vis[u] = 1;
    if(vis[snk]) r = 1;
    else for(int i=0;i<=snk;i++)
    {
        if(adj[u][i] && !vis[i]) r = dfs(i,u);
        if(r) break;
    }
    if(r == 1 && p != -1) swap(adj[p][u],adj[u][p]);
    return r;
}

int flow()
{
    int f=0;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        dfs(src,-1);
        if(!vis[snk]) break;
        f++;
    }
    return f;
}

int main()
{
    while(scanf("%d%d", &v, &c) != EOF)
    {
        string p;
        memset(adj,0,sizeof(adj));
        for(int i=0;i<v;i++) 
        {
            cin >> d[i];
            adj[src][i] = 1;
        }
        for(int i=0;i<c;i++)
        {
            cin >> p;
            adj[w(i)][snk] = 1;
            for(int j=0;j<v;j++) if(match(d[j],p)) adj[j][w(i)] = 1;
        }
        cout << flow() << endl;
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector <int> adj[10100];
int vis[10100];
int conex;

void dfs(int v)
{
    int len = adj[v].size();
    int u;
    vis[v] = conex;
    for(int i=0;i<len;i++)
    {
        u = adj[v][i];
        if(!vis[u]) dfs(u);
    }
}

int main()
{
    int l, b, init[10100], fin[10100], u, v, i, cnt[10100], f;
    scanf("%d%d", &l, &b);
    for(i=0;i<l;i++) scanf("%d", &init[i]);
    for(i=0;i<l;i++) scanf("%d", &fin[i]);
    for(i=0;i<b;i++)
    {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,0,l*sizeof(int));
    conex = 1;
    for(i=0;i<l;i++)
    {
        if(!vis[i]) dfs(i);
        conex++;
    }
    for(i=0;i<l;i++)
    {
        if(init[i] != fin[i]) cnt[vis[i]]++; 
    }
    f = 1;
    for(i=0;i<conex;i++)
    {
        if(cnt[i]%2) f=0;
    }
    if(!f) printf("N\n");
    else printf("S\n");
    return 0;
}

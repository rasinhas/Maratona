//SOLUÇÃO USANDO GRAFO - DFS//
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

int n;
vector <int> adj[200100];
map <int,int> ind;
int vis[200100];

int dfs(int u, int ini, int s)
{
    int j, ret=1;
    if(vis[u]) return 1;
    vis[u] = 1;
    for(j=0;j<adj[u].size();j++)
    {
        if(!vis[adj[u][j]]) ret = dfs(adj[u][j],ini,s+1);
        if(adj[u][j] == ini && s > 2 && s < n) return 0;
        if(ret == 0) return 0;
    }
    return ret;
}

int main()
{
    int cnt;
    int k, u, v, ret, i;
    while(scanf("%d%d", &n, &k) && n)
    {
        cnt = 1;
        ret = 1;
        memset(vis,0,2*k*sizeof(int));
        ind.clear();
        for(i=0;i<2*k+1;i++) adj[i].clear();
        for(i=0;i<k;i++)
        {
            scanf("%d%d", &u, &v);
            if(!ind[u])
            {
                ind[u] = cnt;
                cnt++;
            }
            if(!ind[v])
            {
                ind[v] = cnt;
                cnt++;
            }
            if(adj[ind[u]].size() == 0) adj[ind[u]].push_back(ind[v]);
            else if(adj[ind[u]].size() == 1 && adj[ind[u]][0] != ind[v]) adj[ind[u]].push_back(ind[v]);
            else if(adj[ind[u]].size() == 2 && adj[ind[u]][0] != ind[v] && adj[ind[u]][1] != ind[v]) ret = 0;
            if(adj[ind[v]].size() == 0) adj[ind[v]].push_back(ind[u]);
            else if(adj[ind[v]].size() == 1 && adj[ind[v]][0] != ind[u]) adj[ind[v]].push_back(ind[u]);
            else if(adj[ind[v]].size() == 2 && adj[ind[v]][0] != ind[u] && adj[ind[v]][1] != ind[u]) ret = 0;
        }
        for(i=1;i<cnt;i++)
        {
            if(!ret) break;
            if(!vis[i]) ret = dfs(i,i,1);
        }
        if(ret) printf("Y\n");
        else printf("N\n");
    }
	return 0;
}

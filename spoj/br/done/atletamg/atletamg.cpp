#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define InF 0x3f3f3f3f

using namespace std;

int n, u, m[10][10], adj[10][10], vis[20], ord[20], comp[20];
vector <int> g[20];

int init(int n) { return 2*n; }
int end(int n) { return 2*n+1; }

int dfscycle(int v)
{
    int q;
    vis[v] = 1;
    for(int i=0;i<g[v].size();i++)
    {
        q = g[v][i];
        if(vis[q] == 1) return 1;
        if(!vis[q] && dfscycle(q)) return 1;
    }
    vis[v] = 2;
    return 0;
}

int cycle()
{
    int i;
    for(i=0;i<u;i++) vis[i] = 0;
    for(i=0;i<u;i++) if(!vis[i] && dfscycle(i)) return 1;
    return 0;
}

void build_graph(int liar)
{
    int i, j;
    for(i=0;i<u;i++) g[i].clear();
    for(i=0;i<n;i++) for(j=0;j<n;j++) adj[i][j] = 0;
    for(i=0;i<n;i++)
    {
        g[init(i)].push_back(end(i));
        if(i == liar) continue;
        for(j=0;j<n;j++) if(m[i][j]) adj[i][j] = adj[j][i] = 1;
    }
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(adj[i][j])
    {
        g[init(i)].push_back(end(j));
        g[init(j)].push_back(end(i));
    }
}

int dfs(int a, int b)
{
    int i;
    if(a >= n) return 1;
    if(b >= n) return dfs(a+1, a+2);
    if(adj[a][b]) return dfs(a, b+1);

    g[end(a)].push_back(init(b));
    if(!cycle() && dfs(a, b+1)) return 1;
    g[end(a)].pop_back();

    g[end(b)].push_back(init(a));
    if(!cycle() && dfs(a, b+1)) return 1;
    g[end(b)].pop_back();

    return 0;
}

bool truth(int n) 
{
    build_graph(n);
    if(dfs(0, 1)) return true;
    return false;
}

int main()
{
    int i, j, k, p;
    while(scanf("%d", &n) && n)
    {
        u = 2*n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) m[i][j] = 0;
            scanf("%d", &k);
            for(j=0;j<k;j++) scanf("%d", &p), m[i][p-1] = 1;
        }
        if(truth(n)) printf("nenhum mentiroso\n");
        else
        {
            for(i=n-1;i>=0;i--)
            {
                if(truth(i))
                {
                    printf("%d\n", i+1);
                    break;
                }
            }
        }
    }
    return 0;
}



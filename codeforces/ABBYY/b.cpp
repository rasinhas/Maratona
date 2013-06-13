#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define pb push_back

using namespace std;

set <int> s;
set <int>::iterator it;
vector <int> adj[2000];
int vis[2000];
int cx = 0;
int px = 0;
int x;
int cc;

int ach[2000];

int dfs(int u, int s)
{
    if(u == x)
    {
        px = s;
        cx = cc;
    }
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        return dfs(v, s+1);
    }
    return s;
}

int main()
{
    int n, a[2000];
    int sz[2000];
    cin >> n >> x;
    cc = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] > 0) adj[a[i]].pb(i);
    }
    for(int i=1;i<=n;i++) if(!a[i]) sz[cc++] = dfs(i, 1);
    sz[cx] = 100000;
    sort(sz,sz+cc);
    int ma = px;
    ach[px] = 1;
    for(int i=0;i<cc-1;i++)
    {
        for(int j=ma;j>=px;j--)
        {
            if(ach[j]) 
            {
                ach[j+sz[i]] = 1;
                ma = max(ma,j+sz[i]);
            }
        }
    }
    for(int i=px;i<=ma;i++) if(ach[i]) cout << i << endl;
    return 0;
}

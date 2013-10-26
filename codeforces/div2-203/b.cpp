#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int t[111111], a[111111];
int vis[111111], d[111111], g[111111];
vector <int> adj[111111];
vector <int> ans;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!vis[v] && t[v] == 0) dfs(v);
        d[u] = max(d[u],d[v]+1);
    }
}

void track(int u)
{
   for(int i=0;i<adj[u].size();i++) 
   {
       int v = adj[u][i];
       if(vis[v] == 1) track(v);
   }
   ans.push_back(u);
}

int main()
{
    int n, p;
    cin >> n;
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++) 
    {
        cin >> a[i];
        a[i]--;
        g[a[i]]++;
        if(g[a[i]] > 1) vis[a[i]]=2;
        if(a[i] >= 0) adj[i].push_back(a[i]);
    }
    for(int i=0;i<n;i++) if(!vis[i] && t[i] == 1) dfs(i);
    int m = *max_element(d,d+n);
    for(int i=0;i<n;i++) if(d[i] == m)
    {
        track(i);
        break;
    }
    cout << ans.size() << endl << ans[0]+1;
    for(int i=1;i<ans.size();i++) cout << " " << ans[i]+1;
    cout << endl;
    return 0;
}

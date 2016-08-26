#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int vis[111111];
vector <pii> adj[111111]; 
vector <int> ans;

int dfs(int u, int isp)
{
    int s = 0;
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i].first;
        int t = adj[u][i].second;
        if(!vis[v]) s = max(s,dfs(v,t));
    }
    if(s == 0 && isp == 1) ans.push_back(u+1); 
    if(isp) s = 1;
    return s;
}

int main()
{
    int n, x, y, t;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> x >> y >> t;
        x--; y--; t--;
        adj[x].push_back(make_pair(y,t));
        adj[y].push_back(make_pair(x,t));
    }
    dfs(0, 0);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#define s(x) x+m
#define c(x) x
#define app(x) x+m+n
#define pb push_back
#define sz size()

using namespace std;

map <string,int> apps_id;
vector <int> adj[1000];
bool vis[1000];
int m, n, cnt;

void dfs(int u)
{
    vis[u] = 1;
    if(u >= m && u < m+n) cnt++; // eh um servidor
    for(int i=0;i<adj[u].sz;i++)
    {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    int a, ret;
    string name;
    while(cin >> n >> m && n && m)
    {
        for(int i=0;i<n;i++)
        {
            cin >> a;
            for(int j=0;j<a;j++)
            {
                cin >> name;  
                if(!apps_id.count(name)) apps_id[name] = app(apps_id.sz);
                adj[apps_id[name]].pb(s(i));
            }
        }
        for(int i=0;i<m;i++)
        {
            cin >> a;
            for(int j=0;j<a;j++)
            {
                cin >> name;  
                if(!apps_id.count(name)) apps_id[name] = app(apps_id.sz);
                adj[c(i)].pb(apps_id[name]);
            }
        }
        ret = 0;
        for(int i=0;i<m;i++)
        {
            memset(vis,0,sizeof(vis));
            cnt = 0;
            dfs(c(i));
            ret += cnt;
        }
        cout << ret << endl;
        apps_id.clear();
        for(int i=0;i<m+n+100;i++) adj[i].clear();
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a[222222], f[222222], fp[222222], no[222222];
vector <int> adj[222222], sol;
vector <pair<int,int> > g;

void dfsd(int u, int p, int l)
{
    int c = 0;
    g.push_back(make_pair(l,u));
    if(p >= 0) a[u] = (a[u] == 0 ? a[p] : a[u]);
    if(adj[u].size() == 0)
    {
        f[u] = 1;
        if(a[u] == 1) fp[u] = 1;
    }
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        dfsd(v,u,l+1);
        if(a[v] == 1) c++;
        f[u] += f[v];
        fp[u] += fp[v];
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0;i<s.size();i++) a[i] = (s[i] == '+' ? 1 : (s[i] == '-' ? -1 : 0));
    for(int i=1;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    dfsd(0, -1, 0);
    sort(g.begin(),g.end());
    for(int i=0;i<n;i++)
    {
        int id = g[i].second;
        if(no[id])
        {
            for(int i=0;i<adj[id].size();i++) no[adj[id][i]] = 1;
        }
        else if(fp[id] == f[id])
        {
            sol.push_back(id+1);
            for(int i=0;i<adj[id].size();i++) no[adj[id][i]] = 1;
        }
    }
    sort(sol.begin(),sol.end());
    cout << sol.size() << endl;
    if(sol.size())
    {
        cout << sol[0];
        for(int i=1;i<sol.size();i++) cout << " " << sol[i];
        cout << endl;
    }

    return 0;
}

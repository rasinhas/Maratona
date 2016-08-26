#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <cmath>
#include <numeric>
#define ff first
#define ss second

using namespace std;

vector<pair<int,int> > h;
int adj[22][22];
int p[22];

int dfs(int u)
{
    if(p[u]) return p[u];
    int m = 0;
    for(int i=0;i<h.size();i++)
    {
        if(adj[u][i]) m = max(m,dfs(i));
    }
    return p[u] = m+1;
}

int main()
{
    int t, a, b;
    cin >> t;
    while(t--)
    {
        h.clear();
        memset(adj,0,sizeof(adj));
        memset(p,0,sizeof(p));
        while(cin >> a >> b && (a|b) != 0) h.push_back(make_pair(a,b));
        sort(h.begin(),h.end());
        for(int i=0;i<h.size();i++)
        {
            for(int j=0;j<i;j++) if(h[j].ss <= h[i].ff) adj[j][i] = 1;
        }
        int m = 0;
        for(int i=0;i<h.size();i++) m = max(m,dfs(i));
        cout << m << endl;
    }
    return 0;
}

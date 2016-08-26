#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define ff first
#define ss second

using namespace std;

vector <pair<pair<int,int>,pair<int,int> > > adj[4444];
vector <pair<int,int> > inter[4444];
map <pair<int,pair<int,int> >,int> vis;

pair<int,int> intersect(int l, int r, int nl, int nr)
{
    if(r < nl || nr < l) return make_pair(0,0);
    else return make_pair(max(l,nl),min(r,nr));
}

void bfs()
{
    queue <pair<int,pair<int,int> > > q;
    q.push(make_pair(0,inter[0][0]));
    while(!q.empty())
    {
        int u = q.front().ff;
        int l = q.front().ss.ff;
        int r = q.front().ss.ss;
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].ff.ff;
            int e = adj[u][i].ff.ss;
            int nl = adj[u][i].ss.ff;
            int nr = adj[u][i].ss.ss;
            pair<int,int> n = intersect(l,r,nl,nr);
            if(vis[make_pair(e,n)]) continue;
            vis[make_pair(e,n)] = 1;
            if((n.ff|n.ss) != 0)
            {
                q.push(make_pair(v,n));
                inter[v].push_back(n);
            }
        }
    }
}

int best(int u)
{
    int s = 0;
    for(int i=0;i<inter[u].size();i++) s = max(s,inter[u][i].ss-inter[u][i].ff+1);
    return s;
}

int main()
{
    int n, m, a, b, l, r;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> l >> r;
        a--; b--;
        adj[a].push_back(make_pair(make_pair(b,i),make_pair(l,r)));
    }
    inter[0].push_back(make_pair(1,1000000));
    bfs();
    if(inter[n-1].size() == 0) cout << "Nice work, Dima!" << endl;
    else cout << best(n-1) << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define src ((n)+(r))
#define snk ((n)+(r))+1
#define w(i) ((r)+(i))
#define mp make_pair

using namespace std;

struct pt {
    int x, y;
};

pt re[111], o;
int adj[222][222], vis[222], pai[222];
int cost;
int n, r;

int mod(int a) { return a > 0 ? a : -a; }

void print()
{
    for(int i=0;i<=snk;i++)
    {
        for(int j=0;j<=snk;j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void dijkstra(int u)
{
    pai[u] = -1;
    priority_queue <pair<int,pair<int,int> > > q;
    q.push(mp(0,mp(u,-1)));
    while(!q.empty())
    {
        int v = q.top().second.first;
        int pi = q.top().second.second;
        int d = q.top().first;
        q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        pai[v] = pi;
        for(int i=0;i<=snk;i++) if(adj[v][i]!=0 && !vis[i]) q.push(mp(d-adj[v][i],mp(i,v)));
    }
}

int flow()
{
    int f=0;
    cost = 0;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        dijkstra(src);
        if(!vis[snk]) break;
        f++;
        int p = snk;
        while(pai[p] != -1)
        {
            cost += adj[pai[p]][p];
            adj[p][pai[p]] = -adj[pai[p]][p];
            adj[pai[p]][p] = 0;
            p = pai[p];
        }
    }
    return f;
}

int main()
{
    while(scanf("%d%d", &r, &n) != EOF)
    {
        memset(adj,0,sizeof(adj));
        for(int i=0;i<r;i++)
        {
            cin >> re[i].x >> re[i].y;
            adj[src][i] = 1;
        }
        for(int i=0;i<n;i++)
        {
            cin >> o.x >> o.y;
            for(int j=0;j<r;j++) adj[j][w(i)] = mod(re[j].x-o.x) + mod(re[j].y-o.y);
            adj[w(i)][snk] = 1;
        }
        flow();
        cout << cost-2*n << endl;
    }
    return 0;
}

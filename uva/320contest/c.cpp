#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#define ff first
#define ss second

using namespace std;

typedef pair <int,int> pii;
typedef pair<double,int> pdi;

pair<int,pii> coord[222];
// vertex , type of path
vector <pii> adj[222];
int pi[222], vis[222];
double cost[222][222], dis[222];

void dijkstra(int a, int b)
{
    priority_queue<pdi> q;
    q.push(make_pair(0,a));
    dis[a] = 0;
    pi[a] = -1;
    while(!q.empty())
    {
        int u = q.top().ss;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        if(vis[b]) break;
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].ff;
            if(!vis[v])
            {
                if(dis[v] > dis[u]+cost[u][v])
                {
                    dis[v] = dis[u]+cost[u][v];
                    pi[v] = u;
                    q.push(make_pair(-dis[v],v));
                }
            }
        }
    }
}

double euc(int a, int b)
{
    return sqrt((coord[a].ff-coord[b].ff)*(coord[a].ff-coord[b].ff)+(coord[a].ss.ff-coord[b].ss.ff)*(coord[a].ss.ff-coord[b].ss.ff)+(coord[a].ss.ss-coord[b].ss.ss)*(coord[a].ss.ss-coord[b].ss.ss));
}

int main()
{
    int n, m, a, b, z=0;
    while(cin >> n >> m && !cin.eof())
    {
        if(z) cout << endl;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cost[i][j] = 1000000000000000000;
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<n;i++) 
        {
            cin >> coord[i].ff >> coord[i].ss.ff >> coord[i].ss.ss;
            coord[i].ff *= 5;
        }
        for(int i=0;i<m;i++)
        {
            string s;
            cin >> a >> b >> s;
            int k;
            if(s[0] == 'w') k = 0;
            else if(s[0] == 's') k = 1;
            else if(s[0] == 'l') k = 2;
            else k = 3;
            // 4 = reverse escalator
            adj[a].push_back(make_pair(b,k));
            if(k == 3) adj[b].push_back(make_pair(a,4));
            else adj[b].push_back(make_pair(a,k));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int v = adj[i][j].ff;
                int t = adj[i][j].ss;
                if(t == 0) cost[i][v] = min(cost[i][v],euc(i,v));
                else if(t == 1) cost[i][v] = min(cost[i][v],euc(i,v));
                else if(t == 2) cost[i][v] = min(cost[i][v],1.0);
                else if(t == 3) cost[i][v] = min(cost[i][v],1.0);
                else cost[i][v] = min(cost[i][v],3*euc(i,v));
            }
        }
        int q;
        cin >> q;
        for(int i=0;i<q;i++) 
        {
            cin >> a >> b;
            memset(vis,0,sizeof(vis));
            memset(pi,0,sizeof(pi));
            for(int i=0;i<n;i++) dis[i] = 10000000000;
            dijkstra(a,b);
            stack<int> s;
            s.push(b);
            int k = b;
            while(pi[k]!=-1)
            {
                s.push(pi[k]);
                k = pi[k];
            }
            cout << s.top();
            s.pop();
            while(!s.empty()) 
            {
                cout << " " << s.top();
                s.pop();
            }
            cout << endl;
        }
        z++;
    }
    return 0;
}

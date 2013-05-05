#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

int vis[200];
int a[200], x[200], y[200];
int dist[200];
int n, d;

int mod(int k) { return k > 0 ? k: -k; }

int dijkstra(int u)
{
    int m, v, t, p;
    priority_queue <pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0,u));
    while(!q.empty())
    {
        v = q.top().second;
        m = q.top().first;
        vis[v] = 1;
        if(vis[0]) return m;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                t = d*(mod(x[v]-x[i])+mod(y[v]-y[i]));
                p = m+((t < a[i]) ? 0 : (t-a[i]));
                if(dist[i] > p)
                {
                    q.push(make_pair(p, i));
                    dist[i] = p;
                }
            }
        }
    }
}

int main()
{
    int ret;
    cin >> n >> d;
    for(int i=0;i<n;i++) dist[i] = 0x3f3f3f3f;
    for(int i=1;i<n-1;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    ret = dijkstra(n-1);
    cout << ret << endl;
    return 0;
}

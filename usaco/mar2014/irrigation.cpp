#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int x[2222], y[2222], adj[2001][2001], vis[2222];
int n, c;

int cost(int i, int j) { return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]); }

ll prim() {
    priority_queue <pii> q;
    ll ret = 0;
    int v = 0;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int u = q.top().ss;
        if(vis[u]) {
            q.pop();
            continue;
        }
        ret -= q.top().ff;
        q.pop();
        v++;
        vis[u] = 1;
        for(int i=0;i<n;i++) if(adj[u][i] && !vis[i]) q.push(make_pair(-adj[u][i],i));
    }
    return (v == n ? ret : -1);
}

int main()
{
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);
    cin >> n >> c;
    for(int i=0;i<n;i++) scanf("%d%d", &x[i], &y[i]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(cost(i,j) >= c) adj[i][j] = cost(i,j);
    cout << prim() << endl;
    return 0;
}

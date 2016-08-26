#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

int n, m, mi;
vector <pii> adj[555555];
int d[555555], vis[555555];

void dijkstra(int k) {
    for(int i=0;i<n;i++) d[i]=1000000000;
    priority_queue<pii> q;
    q.push(pii(0, k));
    d[k]=0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i].first;
            int dx = adj[u][i].second;
            if(d[v] > d[u] + dx) {
                d[v] = d[u] + dx;
                q.push(pii(-d[v], v));
            }
        }
    }
}

int main() {
    cin>>n;
    m = 0;
    int a;
    for(int i=1;i<n;i++) {
        scanf("%d", &a);
        int j = (i+1);
        if(i==n-1) j=1;
        adj[i].push_back(pii(j, a));
        adj[j].push_back(pii(i, a));
    }
    for(int i=1;i<n;i++) {
        scanf("%d", &a);
        adj[0].push_back(pii(i, a));
        adj[i].push_back(pii(0, a));
    }
    dijkstra(0);
    mi = 0;
    for(int i=0;i<n;i++) {
        if(d[i] >= d[mi]) mi = i;
    }
    m = 0;
    memset(vis,0,sizeof(vis));
    dijkstra(mi);
    mi = 0;
    for(int i=0;i<n;i++) {
        if(d[i] >= d[mi]) mi = i;
    }
    cout << d[mi] << endl;
    return 0;
}

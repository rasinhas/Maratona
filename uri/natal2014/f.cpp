#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <pii> adj[44444];
int vis[444444];

int prim() {
    int s = 0;
    priority_queue <pii> q;
    q.push(mp(0,0));
    while(!q.empty()) {
        int u = q.top().ss;
        int d = -q.top().ff;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        s += d;
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i].ff;
            int dd = adj[u][i].ss;
            if(!vis[v]) {
                q.push(mp(-dd,v));
            }
        }
    }
    return s;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && n) {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<m;i++) {
            int a, b, p;
            scanf("%d%d%d", &a, &b, &p);
            adj[a].push_back(mp(b,p));
            adj[b].push_back(mp(a,p));
        }
        cout << prim() << endl;
    }
    return 0;
}


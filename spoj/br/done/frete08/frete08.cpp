#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > adj[11111];
int vis[11111];

int prim() {
    int s=0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if(vis[u]) continue;
        s -= d;
        vis[u] = 1;
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i].first;
            if(!vis[v]) {
                q.push(make_pair(-adj[u][i].second,v));
            }
        }
    }
    return s;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    cout << prim() << endl;
    return 0;
}

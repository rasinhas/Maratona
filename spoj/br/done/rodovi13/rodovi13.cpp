#include <bits/stdc++.h>

using namespace std;

vector <int> adj[2][11111];
int vis[2][11111], v[2];

void dfs(int u, int idx) {
    vis[idx][u] = 1;
    v[idx]++;
    for(int i=0;i<adj[idx][u].size();i++) {
        int v = adj[idx][u][i];
        if(!vis[idx][v]) dfs(v,idx);
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        a--; b--;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }
    dfs(0,0);
    dfs(0,1);
    cout << ((v[0] == n && v[1] == n) ? 'S' : 'N') << endl;
    return 0;
}

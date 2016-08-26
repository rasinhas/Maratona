#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> adj[55555];
int vis[55555];

void dfs(int u) {
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) { 
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cc=0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i);
            cc++;
        }
    }
    cout << cc << endl;
    return 0;
}

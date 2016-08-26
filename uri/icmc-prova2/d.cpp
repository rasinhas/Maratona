#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[111111];
int vis[111111];
int ok;

void dfs(int u) {
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(vis[v] == 1) ok = 0;
        if(!vis[v]) dfs(v);
    }
    vis[u] = 2;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        ok = 1;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            adj[i].clear();
        }
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
        }
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
        if(ok) cout << "NAO" << endl;
        else cout << "SIM" << endl;
    }
    return 0;
}


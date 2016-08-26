#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int x[111], y[111];
vector <int> adj[111];
int vis[111];

void dfs(int u) {
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d %d", &x[i], &y[i]);
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(x[i] == x[j] || y[i] == y[j]) adj[i].push_back(j), adj[j].push_back(i);
    int cc = 0;
    for(int i=0;i<n;i++) if(!vis[i]) {
        cc++;
        dfs(i);
    }
    cout << cc-1 << endl;
    return 0;
}


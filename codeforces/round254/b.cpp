#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int adj[55][55];
int vis[55], s[55];
int cc, n;

void dfs(int u) {
    vis[u] = cc;
    s[cc]++;
    for(int i=0;i<n;i++) {
        if(adj[u][i] && !vis[i]) dfs(i);
    }
}

int main() {
    int m;
    cin >> n >> m;
    cc = 1;
    int a, b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i);
            cc++;
        }
    }
    int pow = 0;
    for(int i=1;i<cc;i++) {
        pow += s[i]-1;
    }
    cout << (1ll<<pow) << endl;
    return 0;
}


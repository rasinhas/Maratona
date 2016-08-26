#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int vis[55555], ad[55555];

void dfs(int u) {
    vis[u] = 1;
    if(!vis[ad[u]]) dfs(ad[u]);
}

int main() {
    int n, t, a;
    cin >> n >> t;
    t--;
    for(int i=0;i<n-1;i++) {
        scanf("%d", &a);
        ad[i] = i+a;
    }
    dfs(0);
    cout << (vis[t] ? "YES" : "NO") << endl;
    return 0;
}


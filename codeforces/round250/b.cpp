#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int vis[111111];

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int r = 0;
    for(int i=0;i<n;i++) {
        queue <pair<int,int> > q;
        q.push(make_pair(i,a[i]));
        memset(vis,0,sizeof(vis));
        while(!q.empty()) {
            int u = q.front().ff;
            int mm = q.front().ss;
        }
    }
    return 0;
}


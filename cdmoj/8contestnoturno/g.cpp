#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[111111];
int d[111111], vis[111111];
vector <int> ans;
queue <int> q;

int main() {
    int n, m, k, a, b;
    while(scanf("%d%d%d", &n, &k, &m) && n) {
        for(int i=1;i<=n;i++) adj[i].clear();
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<k;i++) {
            cin >> a;
            vis[a] = 1;
            d[a] = 1;
            q.push(a);
        }
        for(int i=0;i<m;i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int mm = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++) {
                int v = adj[u][i];
                if(!vis[v]) {
                    vis[v] = 1;
                    d[v] = d[u]+1;
                    q.push(v);
                    mm = max(mm,d[v]);
                }
            }
        }
        ans.clear();
        for(int i=1;i<=n;i++) if(d[i] == mm) ans.push_back(i);
        cout << ans[0];
        for(int i=1;i<ans.size();i++) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}


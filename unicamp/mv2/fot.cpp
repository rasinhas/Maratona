#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[1111111], ans;
queue <int> q[2];
int vis[1111111], g[1111111];

int main()
{
    int n, k, a, b;
    cin >> n >> k;
    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        g[a]++;
        g[b]++;
    }
    for(int i=0;i<n;i++) if(g[i] == 1) q[0].push(i);
    int idx = 0, ml = k/2;
    for(int l=0;l<ml && !q[idx].empty();l++) {
        while(!q[idx].empty()) {
            int u = q[idx].front();
            q[idx].pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i=0;i<adj[u].size();i++) {
                int v = adj[u][i];
                if(!vis[v]) {
                    g[v]--;
                    if(g[v] == 1) q[1-idx].push(v);
                }
            }
            ans.push_back(u+1);
        }
        idx = 1-idx;
    }
    if(k%2) {
        for(int i=0;i<n;i++) if(!vis[i]) {
            ans.push_back(i+1);
            break;
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

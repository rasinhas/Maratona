#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111], p[1111];
vector <int> adj[1111];
vector <pair<pii,int> > v;
int vis[1111];

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
        int mc = -1, pos = -1, mb = -1;
        for(int j=0;j<n;j++) {
            if(vis[j]) continue;
            int nc = 0, c = 0;
            for(int k=0;k<adj[j].size();k++) if(!vis[adj[j][k]]) {
                nc += a[adj[j][k]];
                c++;
            }
            if(a[j]*c >= mb) {
                if(a[j]*c > mb) {
                    mb = a[j]*c;
                    mc = nc;
                    pos = j;
                }
                else if(nc < mc) {
                    mc = nc;
                    pos = j;
                }
            }
        }
        vis[pos] = 1;
        r += mc;
    }
    cout << r << endl;
    return 0;
}


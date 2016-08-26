#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t[333][333];
int v[333][333];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n, m, p;

int in(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

int go() {
    priority_queue <pair<pii,pii> > q;
    q.push(mp(mp(0,t[0][0] == 1 ? 1 : 0),mp(0,0)));
    while(!q.empty()) {
        int x = q.top().ss.ff;
        int y = q.top().ss.ss;
        int k = q.top().ff.ss;
        int d = -q.top().ff.ff;
        q.pop();
        if(k == p) return d;
        if(v[x][y] >= k) continue;
        v[x][y] = k;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(in(nx,ny)) {
                if(t[nx][ny] == k+1) q.push(mp(mp(-d-1,k+1),mp(nx,ny)));
                else q.push(mp(mp(-d-1,k),mp(nx,ny)));
            }
        }
    }
}

int main() {
    cin >> n >> m >> p;
    memset(v,-1,sizeof(v));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> t[i][j];
    cout << go() << endl;
    return 0;
}


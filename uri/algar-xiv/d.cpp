#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int vis[555][555];
string t[555];
int md, pi, pj;
int n, m;

int in(int r, int c) { return r >= 0 && c >= 0 && r < n && c < m; }

void bfs(int r, int c) {
    queue<pair<pii,int> > q;
    q.push(mp(mp(r,c),0));
    while(!q.empty()) {
        r = q.front().ff.ff;
        c = q.front().ff.ss;
        int d = q.front().ss;
        q.pop();
        if(vis[r][c]) continue;
        vis[r][c] = 1;
        if(d > md) {
            md = d;
            pi = r;
            pj = c;
        }
        for(int i=0;i<4;i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(in(nr,nc) && !vis[nr][nc] && t[nr][nc] == '.') q.push(mp(mp(nr,nc),d+1));
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &m) && n) {
        for(int i=0;i<n;i++) cin >> t[i];
        memset(vis,0,sizeof(vis));
        md = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(t[i][j] == '.') {
            bfs(i,j);
            break;
        }
        memset(vis,0,sizeof(vis));
        md = 0;
        bfs(pi,pj);
        cout << md << endl;
    }
    return 0;
}


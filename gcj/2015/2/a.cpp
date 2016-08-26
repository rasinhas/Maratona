#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string g[111];
int r, c, x, y;
int vis[111][111][4];
int res[111][111];
int sg[111][111];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int sign;

int dir(char c) {
    if(c == '^') return 0;
    if(c == '>') return 1;
    if(c == 'v') return 2;
    if(c == '<') return 3;
    return -1;
}

int go(int x, int y, int d) {
    if(x >= r || y >= c || x < 0 || y < 0) return 0;
    if(d == -1) d = dir(g[x][y]);
    if(vis[x][y][d] && res[x][y] == -1) return 1;
    vis[x][y][d] = 1;
    if(g[x][y] != '.') {
        sg[x][y] = 1;
        if(dir(g[x][y]) != d) d = dir(g[x][y]);
    }
    res[x][y] = go(x+dx[d],y+dy[d],d);
    if(x+dx[d] < r && x+dx[d] >=0 && y+dy[d] < c && y+dy[d] >= 0) sg[x][y] += sg[x+dx[d]][y+dy[d]];
    return res[x][y];
}

int solve(int x, int y) {
    if(g[x][y] == '.') return 0;
    if(go(x,y,-1) == 1) return 0;
    return 2;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> r >> c;
        for(int i=0;i<r;i++) cin >> g[i];
        memset(vis,0,sizeof(vis));
        memset(res,-1,sizeof(res));
        memset(sg,0,sizeof(sg));
        int best = 2;
        int ts = 0;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(g[i][j] != '.') {
            ts++;
            if(!vis[i][j][dir(g[i][j])]) {
                best = min(solve(i,j),best);
            }
        }
        int sign = 0;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) sign = max(sign,sg[i][j]);
        printf("Case #%d: ", t);
        if(ts == 0) cout << "0" << endl;
        else if(best == 2) {
            if(sign > 1) cout << "1" << endl;
            else cout << "IMPOSSIBLE" << endl;
        }
        else printf("%d\n", best);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int inf = (int)1e9;

int r, c;
int adj[111][111][4];
int vis[111][111][4][2];
int d[111][111];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool in(int x, int y) { return (x >= 0 && y >= 0 && x < r && y < c); }

void dijkstra(int ox, int oy) {
    priority_queue <pair<int,pair<pair<int,int>, pair<int,int> > > > q;
    q.push(mp(0,mp(mp(ox,oy),mp(0,0))));
    while(!q.empty()) {
        int x = q.top().ss.ff.ff;
        int y = q.top().ss.ff.ss;
        int dir = q.top().ss.ss.ff;
        int acc = q.top().ss.ss.ss;
        int dist = -q.top().ff;
        q.pop();
        if(vis[x][y][dir][acc]) continue;
        if(acc == 0) d[x][y] = min(d[x][y],dist);
        vis[x][y][dir][acc] = 1;
        if(acc == 1) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(in(nx,ny) && adj[x][y][dir] > 0) {
                if(!vis[nx][ny][dir][0]) q.push(mp(-dist-2*adj[x][y][dir],mp(mp(nx,ny),mp(dir,0))));
                if(!vis[nx][ny][dir][1]) q.push(mp(-dist-adj[x][y][dir],mp(mp(nx,ny),mp(dir,1))));
            }
        } else {
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(in(nx,ny) && adj[x][y][i] > 0) {
                    if(!vis[nx][ny][i][0]) q.push(mp(-dist-2*adj[x][y][i],mp(mp(nx,ny),mp(i,0))));
                    if(!vis[nx][ny][i][1]) q.push(mp(-dist-2*adj[x][y][i],mp(mp(nx,ny),mp(i,1))));
                }
            }
        }
    }
}

int main() {
    int t = 1;
    int r1, c1, r2, c2;
    while(cin >> r >> c >> r1 >> c1 >> r2 >> c2 && r) {
        r1--; c1--; r2--; c2--;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<r-1;i++) {
            for(int j=0;j<c-1;j++) {
                cin >> adj[i][j][0];
                adj[i][j+1][2] = adj[i][j][0];
            }
            for(int j=0;j<c;j++) {
                cin >> adj[i][j][1];
                adj[i+1][j][3] = adj[i][j][1];
            }
        }
        for(int j=0;j<c-1;j++) {
            cin >> adj[r-1][j][0];
            adj[r-1][j+1][2] = adj[r-1][j][0];
        }
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) d[i][j] = inf;
        printf("Case %d: ", t++);
        dijkstra(r1,c1);
        if(d[r2][c2] == inf) cout << "Impossible" << endl;
        else cout << d[r2][c2] << endl;
    }
    return 0;
}

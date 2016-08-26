#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[3333];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int df[3333][3333], ds[3333][3333], v[3333][3333];
int n, m;
int in(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

void gof() {
    queue <pii> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j] == 'F') {
        q.push(make_pair(i,j));
        df[i][j] = 0;
    }
    while(!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        if(v[x][y]) continue;
        v[x][y] = 1;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(in(nx,ny) && !v[nx][ny] && s[nx][ny] != '#' && df[x][y]+1 < df[nx][ny] ) {
                df[nx][ny] = df[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

void gos(int x, int y) {
    queue <pii> q;
    q.push(make_pair(x,y));
    ds[x][y] = 0;
    while(!q.empty()) {
        x = q.front().ff;
        y = q.front().ss;
        q.pop();
        if(v[x][y]) continue;
        v[x][y] = 1;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(in(nx,ny) && !v[nx][ny] && s[nx][ny] != '#' && ds[x][y]+1 < df[nx][ny]) {
                ds[nx][ny] = ds[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) df[i][j] = ds[i][j] = 1e9;
        memset(v,0,sizeof(v));
        gof();
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j] == 'S') gos(i,j);
        int exit = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j] == 'E' && ds[i][j] != 1e9) exit = 1;
        if(!exit) cout << "N" << endl;
        else cout << "Y" << endl;
    }
    return 0;
}


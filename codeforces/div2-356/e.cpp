#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string t[555];
int c[555][555];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int sz[555*555];
int n, m;
int dp[555][555];
int vis[555*555];

int in(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }

void go(int x, int y, int cc) {
    c[x][y] = cc;
    sz[cc]++;
    for(int i=0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(in(nx,ny) && t[nx][ny] == '.' && c[nx][ny] == 0) go(nx,ny,cc);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> t[i];
    int cc = 1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(t[i][j] == '.' && c[i][j] == 0) go(i,j,cc++);
    }
    for(int i=0;i<n;i++) {
        dp[0][i] = dp[0][i-1] + (t[0][i] == 'X' ? 1 : 0);
        dp[i][0] = dp[i-1][0] + (t[i][0] == 'X' ? 1 : 0);
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (t[i][j] == 'X' ? 1 : 0);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    int b = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            memset(vis,0,sizeof(vis));
            int st = 0;
            if(i > 0) for(int k=0;k<n;k++) if(c[i-1][j+k] != 0 && !vis[c[i-1][j+k]]) {st += sz[c[i-1][j+k]]; vis[c[i-1][j+k]] = 1;}
            if(j > 0) for(int k=0;k<n;k++) if(c[i+k][j-1] != 0 && !vis[c[i+k][j-1]]) {st += sz[c[i+k][j-1]]; vis[c[i+k][j-1]] = 1;}
            if(i+m < n) for(int k=0;k<n;k++) if(c[i+m][j+k] != 0 && !vis[c[i+m][j+k]]) {st += sz[c[i+m][j+k]]; vis[c[i+m][j+k]] = 1;}
            if(j+m < n) for(int k=0;k<n;k++) if(c[i+k][j+m] != 0 && !vis[c[i+k][j+m]]) {st += sz[c[i+k][j+m]]; vis[c[i+k][j+m]] = 1;}
            if(i > 0 && j > 0) if(c[i-1][j-1] != 0 && !vis[c[i-1][j-1]]) {st += sz[c[i-1][j-1]]; vis[c[i-1][j-1]] = 1;}
            if(i > 0 && j+m < n) if(c[i-1][j+m] != 0 && !vis[c[i-1][j+m]]) {st += sz[c[i-1][j+m]]; vis[c[i-1][j+m]] = 1;}
            if(i+m < n && j > 0) if(c[i+m][j+1] != 0 && !vis[c[i+m][j-1]]) {st += sz[c[i+m][j-1]]; vis[c[i+m][j-1]] = 1;}
            if(i+m < n && j+m < n) if(c[i+m][j+m] != 0 && !vis[c[i+m][j+m]]) {st += sz[c[i+m][j+m]]; vis[c[i+m][j+m]] = 1;}
            cout << i << " " << j << " " << st << endl;
            st += dp[i+m-1][j+m-1] - (j > 0 ? dp[i+m-1][j-1] : 0)  - (i > 0 ? dp[i-1][j+m-1]: 0)  + (i > 0 && j > 0 ? dp[i-1][j-1] : 0);
            b = max(b,st);
        }
    }
    cout << b << endl;
    return 0;
}


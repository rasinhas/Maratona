#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string t[55];
int dp[52][52][10020], vv[52][52][10020];
int r, c;
vector <pii> loc[55];
string s;
const int MAX = 1000000000;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
vector <pii> adj[51][51];
int d[51][51][51][51];
int vis[51][51];

int decodechar(char c) {
    if(c >= 'A' && c <= 'Z') return c-'A';
    else if(c >= '0' && c <= '9') return c-'0'+26;
    else if(c == '-') return 36;
    else return 37;
}

int solve() {
    priority_queue <pair<pii,pii> > q;
    q.push(mp(mp(0,0),mp(0,0)));
    while(!q.empty()) {
        int x = q.top().ss.ff;
        int y = q.top().ss.ss;
        int pos = q.top().ff.ss;
        int dd = -q.top().ff.ff;
        q.pop();
        if(vv[x][y][pos]) continue;
        vv[x][y][pos] = 1;
        if(pos == s.size()) return dd;
        int next = decodechar(s[pos]);
        for(int i=0;i<loc[next].size();i++) {
            int nx = loc[next][i].ff, ny = loc[next][i].ss;
            int nd = dd + d[x][y][nx][ny] + 1;
            if(!vv[nx][ny][pos+1] && nd < dp[nx][ny][pos+1]) {
                q.push(mp(mp(-nd,pos+1),mp(nx,ny)));
                dp[nx][ny][pos+1] = nd;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for(int i=0;i<r;i++) cin >> t[i];
    cin >> s;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) for(int k=0;k<r;k++) for(int l=0;l<c;l++) d[i][j][k][l] = MAX;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) d[i][j][i][j] = 0;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) for(int k=0;k<4;k++) {
        int ni = i, nj = j;
        loc[decodechar(t[i][j])].push_back(mp(i,j));
        while(t[ni][nj] == t[i][j]) { 
            ni += dx[k]; nj += dy[k]; 
            if(ni == r || ni < 0 || nj == c || nj < 0) break;
        }
        if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
            d[i][j][ni][nj] = 1;
            adj[i][j].push_back(mp(ni,nj));
        }
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        queue <pii> q;
        q.push(mp(i,j));
        memset(vis,0,sizeof(vis));
        while(!q.empty()) {
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            for(int k=0;k<adj[x][y].size();k++) {
                int nx = adj[x][y][k].ff, ny = adj[x][y][k].ss;
                if(!vis[nx][ny]) {
                    q.push(mp(nx,ny));
                    d[i][j][nx][ny] = min(d[i][j][nx][ny],d[i][j][x][y] + 1);
                }
            }
        }
    }
    s += '*';
    for(int k=0;k<=s.size();k++) for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j][k] = MAX;
    /*
    for(int i=0;i<loc[decodechar(s[0])].size();i++) {
        int nx = loc[decodechar(s[0])][i].ff, ny = loc[decodechar(s[0])][i].ss;
        dp[nx][ny][1] = d[0][0][nx][ny]+1;
    }
    for(int i=1;i<s.size();i++) {
        for(int j=0;j<loc[decodechar(s[i-1])].size();j++) {
            int x = loc[decodechar(s[i-1])][j].ff, y = loc[decodechar(s[i-1])][j].ss;
            for(int k=0;k<loc[decodechar(s[i])].size();k++) {
                int nx = loc[decodechar(s[i])][k].ff, ny = loc[decodechar(s[i])][k].ss;
                dp[nx][ny][i+1] = min(dp[nx][ny][i+1],dp[x][y][i] + d[x][y][nx][ny] + 1);
            }
        }
    }
    int best = MAX;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) best = min(best,dp[i][j][s.size()]);
    */
    cout << solve() << endl;
    return 0;
}

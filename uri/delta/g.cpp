#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;

string s[111];
int ok, n, m, k;
int dc[] = {0,1,-1,0};
int dr[] = {1,0,0,-1};
char car[] = {'^', '<', '>', 'v'};
int vis[111][111];

void bfs(int r, int c) {
    queue <pair<pii,int> > q;
    q.push(mp(mp(r,c),k));
    while(!q.empty()) {
        int r = q.front().ff.ff;
        int c = q.front().ff.ss;
        int t = q.front().ss;
        q.pop();
        if(vis[r][c] >= t) continue;
        vis[r][c] = t;
        if(c == 0 || r == 0 || r == n-1 || c == m-1) {
            ok = 1;
            return;
        }
        for(int i=0;i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(vis[nr][nc] < t && s[nr][nc] == car[i]) q.push(mp(mp(nr,nc),t));
            if(vis[nr][nc] < t-1 && s[nr][nc] == car[3-i] && t > 0) q.push(mp(mp(nr,nc),t-1));
        }
    }
}

int main() 
{
    while(scanf("%d%d%d", &n, &m, &k) && n) {
        ok = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j] = -1;
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j] == 'x') bfs(i,j);
        cout << (ok ? "Sim" : "Nao") << endl;
    }
    return 0;
}

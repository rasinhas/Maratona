#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
string s[111];
int d[100][100][100][100];
int vis[111][111]
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
vector <pii> dots;

int bfs(int r, int c) {
    queue<int> q;
    q.push_back(mp(r,c));
    vis[r][c] = r*m + c;
    while(!q.empty()) {
        int u = q.front().ff;
        int v = q.front().ss;
        q.pop();
        for(int i=0;i<8;i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nc < 0 || nr < 0 || nr >= n || nc >= m) continue;
            if(s[nr][nc] != '#' && vis[nr][nc] != r*m + c) {
                d[r][c][nr][nc] = d[r][c][u][v] + 1;
                q.push(mp(nr,nc));
                vis[nr][nc] = r*m + c;
            }
        }
    }
}

// não funciona
/*
*____
_____
____*
_____
*____
*/
int prim() {
    priority_queue <pii> q;
}

int main() {
    while(scanf("%d%d", &n, &m) && n) {
        dots.clear();
        for(int i=0;i<n;i++) cin >> s[i];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) for(int j=i+1;j<m;j++) {
            if(s[i][j] != '#') bfs(i,j);
            if(s[i][j] == '*') dots.push_back(mp(i,j));
        }
        int r = prim();
        if(r == -1) printf("impossivel\n");
        else printf("%d\n", r);
    }
    return 0;
}


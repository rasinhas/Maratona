#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <queue>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> trip;

int n, m;
int h[555][555], w[555][555], vis[555][555], dp[555][555];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

bool in(int r, int c) { return r >= 0 && c >= 0 && r < n && c < m; }

int mod(int a) { return a > 0 ? a : -a; }

int solve(int r, int c)
{
    int d, mwd=0;
    priority_queue <trip> q;
    q.push(mp(0,mp(r,c)));
    dp[r][c] = 0;
    while(!q.empty())
    {
        r = q.top().ss.ff;
        c = q.top().ss.ss;
        d = -q.top().ff;
        q.pop();
        if(vis[r][c]) continue;
        vis[r][c] = 1;
        dp[r][c] = d;
        if(w[r][c]) mwd = max(mwd,d);
        for(int i=0;i<4;i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(in(nr,nc) && !vis[nr][nc])
            {
                int gd = max(d,mod(h[r][c]-h[nr][nc]));
                q.push(mp(-gd,mp(nr,nc)));
            }
        }
    }
    return mwd;
}

int main()
{
    ifstream in("ccski.in");
    ofstream out("ccski.out");
    int r;
    in >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) in >> h[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) in >> w[i][j];
    for(int i=0;i<n;i++)
    {
        int ok = 0;
        for(int j=0;j<m;j++) if(w[i][j] == 1) 
        {
            r = solve(i,j);
            ok = 1;
            break;
        }
        if(ok) break;
    }
    out << r << endl;
    return 0;
}



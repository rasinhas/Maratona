#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define inf 1000000000

using namespace std;

int n, m;
string g[555];
int dx[] = {0,1};
int dy[] = {1,0};
int d[555][555], mp[555][555], vis[555][555];
pair<int,int> leftmost[555][555], upmost[555][555];

bool in(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

struct vertex {
    int x, y, p, gl, gu, cg;
    vertex(int x=0, int y=0, int p=0, int gl=0, int gu=0, int cg=1) 
    {
        this->x = x;
        this->y = y;
        this->p = p;
        this->gl = gl;
        this->gu = gu;
        this->cg = cg;
    }
};

void precalc()
{
    for(int i=0;i<n;i++) leftmost[i][0] = make_pair(i,0);
    for(int i=0;i<n;i++) for(int j=1;j<m;j++)
    {
        if(g[i][j-1] == '#') leftmost[i][j] = make_pair(i,j);
        else leftmost[i][j] = leftmost[i][j-1];
    }
    for(int i=0;i<m;i++) upmost[0][i] = make_pair(0,i);
    for(int i=0;i<m;i++) for(int j=1;j<n;j++)
    {
        if(g[j-1][i] == '#') upmost[j][i] = make_pair(j,i);
        else upmost[j][i] = upmost[j-1][i];
    }
}

void dfs(int x, int y, int ix, int iy)
{
    vis[x][y] = 1;
    for(int i=0;i<2;i++)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if((ix|iy) == 0) d[nx][ny] = d[x][y]+1;
        if(in(nx,ny) && !vis[nx][ny] && g[nx][ny] != '#') dfs(nx,ny,ix,iy);
        mp[x][y] = max(mp[x][y],mp[nx][ny]+1);
    }
}

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> g[i];
        precalc();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) d[i][j] = -inf;
        d[0][0] = 1;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) dfs(i,j,i,j);
        int ret = mp[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j] == '.')
                {
                    int nx = leftmost[i][j].first, ny = leftmost[i][j].second;
                    if(i && d[i-1][j] == d[i][j]-1 && g[i-1][j] == '.') ret = max(ret,d[i][j]+(j-ny)+mp[nx+1][ny]);
                    nx = upmost[i][j].first, ny = upmost[i][j].second;
                    if(j && d[i][j-1] == d[i][j]-1 && g[i][j-1] == '.') ret = max(ret,d[i][j]+(i-nx)+mp[nx][ny+1]);
                }
            }
        }
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}

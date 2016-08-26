#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string t[8];
int vis[2][11][11];
int dx[] = {2,2,-2,-2};
int dy[] = {2,-2,2,-2};

int in(int x, int y) { return (x >= 0 && x < 8 && y >= 0 && y < 8); }

void go(int x, int y,int idx, int k)
{
    vis[idx][x][y] |= (1<<(k));
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(in(nx,ny) && !vis[idx][nx][ny]) go(nx,ny,idx,1-k);
    }
}

int main()
{
    int z;
    cin >> z;
    while(z--)
    {
        int k = 0, f = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<8;i++) cin >> t[i];
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++) if(t[i][j] == 'K') go(i,j,k++,0);
        }
        for(int i=0;i<8;i++) for(int j=0;j<8;j++) if(vis[0][i][j] == vis[1][i][j] && vis[0][i][j] > 0 && t[i][j] != '#') f = 1;
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

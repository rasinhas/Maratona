#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string maze[555];
int vis[555][555];
int m, n, k, ok=0;

bool in(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in(nx,ny) && maze[nx][ny] == '.' && !vis[nx][ny]) dfs(nx,ny);
    }
    if(!ok)
    {
        maze[x][y] = 'X';
        k--;
        if(k == 0) ok = 1;
    }
}

int main()
{
    cin >> n >> m >> k;
    if(k == 0) ok = 1;
    for(int i=0;i<n;i++) cin >> maze[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        if(maze[i][j] == '.')
        {
            dfs(i,j);
            break;
        }
    }
    for(int i=0;i<n;i++) cout << maze[i] << endl;
    return 0;
}

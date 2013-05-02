#include <stdio.h>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

int main()
{
    int i, j, grid[20][20], d[20][20], px, py, m, n, dist;
    queue <pair<int,int> > fila;
    pair <int,int> a;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++)
    {
        memset(grid[i],0,m*sizeof(int));
        memset(d[i],-1,m*sizeof(int));
        for(j=0;j<m;j++)
        {
            scanf("%d", &grid[i][j]);
            if(grid[i][j] == 3) a = make_pair(i,j);
        }
    }
    fila.push(a);
    d[a.first][a.second] = 0;
    while(!fila.empty())
    {
        a = fila.front();
        fila.pop();
        for(i=0;i<4;i++)
        {
            px = a.first+dx[i];
            py = a.second+dy[i];
            if(px >= 0 && px < n && py >= 0 && py < m)
            {
                if(grid[px][py] == 1 && d[px][py] == -1)
                {
                    d[px][py] = d[a.first][a.second]+1;
                    fila.push(make_pair(px,py));
                }
                else if(grid[px][py] == 0)
                {
                    dist = d[a.first][a.second]+1;
                    while(!fila.empty()) fila.pop();
                    break;
                }
            }
        }
    }
    printf("%d\n", dist);
    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int in(int u, int v) { return (u>=0 && v >=0 && u<3 && v<3); }

int main()
{
    char grid[53][53];
    int v = 0, wc, bc, n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<=n+1;i++) grid[i][0] = grid[i][m+1] = 'W';
    for(int i=0;i<=m+1;i++) grid[0][i] = grid[n+1][i] = 'W';
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf(" %c ", &grid[i][j]);
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++)
        {
            wc = bc = 0;
            for(int k=0;k<4;k++)
            {
                if(grid[i+dx[k]][j+dy[k]] == 'B') bc++;
                else wc++;
            }
            if(grid[i][j] == 'B' && wc == 4) v = 1;
            else if(grid[i][j] == 'W'&& bc >= 3) v = 1;
            if(v) break;
        }
    }
    if(v) printf("NO\n");
    else printf("YES\n");
    return 0;
}

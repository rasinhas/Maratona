#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};

int main()
{
    char grid[200][200];
    int used[26];
    int n, m, px, py, ret=0;
    char c;
    scanf("%d%d %c", &n, &m, &c);
    memset(used,0,sizeof(used));
    for(int i=0;i<n;i++) scanf("%s", grid[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == c)
            {
                for(int k=0;k<4;k++)
                {
                    px = i+dx[k];
                    py = j+dy[k];
                    if(px >= 0 && py >= 0 && px < n && py < m) if(grid[px][py] != '.' && grid[px][py] != c) 
                    {
                        if(!used[grid[px][py]-'A'])
                        {
                            used[grid[px][py]-'A'] = 1;
                            ret++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}

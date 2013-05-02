#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    priority_queue <pair<int,pair<int,int> > > f;
    pair <int,int> a;
    int grafo[110][110];
    int vis[110];
    int x, y, z, m, n, teste=1;
    int i, j;
    while(scanf("%d%d", &n, &m) && n)
    {
        for(i=0;i<n;i++)
        {
            vis[i] = 0;
            for(j=0;j<n;j++) grafo[i][j] = 0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;y--;
            grafo[x][y] = z;
            grafo[y][x] = z;
        }
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                f.push(make_pair(0,make_pair(i,i)));
                while(!f.empty())
                {
                    a = f.top().second;
                    f.pop();
                    if(!vis[a.second])
                    {
                        if(a.second != i)
                        {
                            grafo[a.first][a.second] = -1;
                            grafo[a.second][a.first] = -1;
                        }
                        for(j=0;j<n;j++)
                        {
                            if(grafo[a.second][j] && !vis[j])
                            {
                                f.push(make_pair(-grafo[a.second][j],make_pair(a.second,j)));
                            }
                        }
                    }
                    vis[a.second] = 1;
                }
            }
        }
        printf("Teste %d\n", teste++);
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(grafo[i][j]==-1) printf("%d %d\n", i+1, j+1);
            }
        }
        printf("\n");
    }
    return 0;
}

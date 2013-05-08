#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int a, b, n, m, times, i, j;
    int mat[1010][1010];
    int visited[1010];
    queue <int> fila;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a-1][b-1]=1;
        mat[b-1][a-1]=1;
    }
    for(i=0;i<n;i++) visited[i]=0;
    times=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            fila.push(i);
            while(!fila.empty())
            {
                a=fila.front();
                fila.pop();
                for(j=0;j<n;j++)
                {
                    if(mat[a][j] && !visited[j])
                    {
                        fila.push(j);
                        visited[j]=1;
                    }
                }
            }
            times++;
        }
    }
    printf("%d\n",times);
    return 0;
}

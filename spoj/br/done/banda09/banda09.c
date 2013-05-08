#include <stdio.h>
#include <string.h>
#define max(a,b) (a) > (b) ? a : b

int amiz[110][110];
int pd[110][110][110];

int main()
{
    int i, j, k, p1, p2, p3;
    int x, y, am, n, m, val, f;
    scanf("%d%d", &n, &m);
    memset(amiz,0,n*n*sizeof(int));
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d", &x, &y, &am);
        amiz[x][y] = am;
        amiz[y][x] = am;
    }
    val = 0;
    for(i=1;i<=n;i++)
    {
        pd[i][0][0] = 0;
        for(j=i+1;j<=n;j++)
        {
            pd[i][j][0] = pd[i][0][0] + amiz[i][j];
            for(k=j+1;k<=n;k++)
            {
                pd[i][j][k] = pd[i][j][0] + amiz[i][k] + amiz[j][k];
                if(pd[i][j][k] >= val)
                {
                    val = pd[i][j][k];
                    p1 = i; p2 = j; p3 = k;
                }
            }
        }
    }
    printf("%d %d %d\n", p1, p2, p3);
    return 0;
}

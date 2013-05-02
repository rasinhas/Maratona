#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int acumulado[1010][1010];
int n;

int solve(int b)
{
    int i, ac;
    for(i=n-b-1;i>=0;i--)
    {
        if(acumulado[i][b] < 0) acumulado[i][b+1] += acumulado[i][b];
        else if(i != 0)acumulado[i-1][b] += acumulado[i][b];
    }
    if(acumulado[0][b] > 0) ac = acumulado[0][b];
    else ac=0;
    if(b==n-1) return ac;
    return ac + solve(b+1);
}

int main()
{
    int i, j;
    while(scanf("%d", &n) && n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                acumulado[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<i+1;j++)
            {
                scanf("%d", &acumulado[i-j][j]);
            }
        }
        printf("%d\n", solve(0));
    }
	return 0;
}

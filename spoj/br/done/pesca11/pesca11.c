#include <stdio.h>

int main()
{
    int mat[101][101];
    int n, xi, xf, yi, yf;
    int i, j, k, sum=0;
    scanf("%d", &n);
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d", &xi, &xf, &yi, &yf);
        xi--,xf--,yi--,yf--;
        for(j=xi;j<xf;j++)
        {
            for(k=yi;k<yf;k++)
            {
                mat[j][k]=1;
            }
        }
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            sum+=mat[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}

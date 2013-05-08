#include <stdio.h>

int main()
{
    int mat[510][510];
    int i, j, x, y, n, ret;
    scanf("%d", &n);
    for(i=0;i<501;i++)
    {
        for(j=0;j=501;j++)
        {
            mat[i][j]=0;
        }
    }
    ret=0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &x, &y);
        mat[x][y]++;
        if(mat[x][y]>1) ret=1;
    }
    printf("%d\n",ret);
    return 0;
}

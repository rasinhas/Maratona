#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int mat[201][201];
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int n, m, pint=0;

int dfs(int x, int y)
{
    int i, x2, y2;
    mat[x][y]=1;
    pint++;
    for(i=0;i<8;i++)
    {
        x2 = x+dx[i];  
        y2 = y+dy[i];
        if(((x2>=0 && x2<n) && (y2>=0 &&y2 <m)) && (mat[x2][y2]==0))
        {
            dfs(x2,y2);
        }
    }
}

int main()
{
    int i, j, x, y, k, a, b;
    scanf("%d %d %d %d %d", &n, &m, &x, &y ,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &a, &b);
        mat[a-1][b-1]=1;
    }
    dfs(x-1,y-1);
    printf("%d\n",pint);
	return 0;
}

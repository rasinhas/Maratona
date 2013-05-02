#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int main()
{
    int i, j, n, ret, suml, sumc, sumd;
    int mat[1010][1010];
    int val[1000010];
    scanf("%d",&n);
    ret=1;
    rep(i,n)
    {
        rep(j,n)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]>1000000) ret=0;
            else val[mat[i][j]]=1;
        }
    }
    for(i=1;i<=n*n;i++) if(val[i]==0) ret=0;
    if(ret!=0)
    {
        sumd=0;
        ret--;
        rep(i,n)
        {
            sumc=0;
            suml=0;
            rep(j,n)
            {
                if(i==0) ret += mat[i][j];
                else suml += mat[i][j];
                sumc += mat[j][i];
            }
            if((suml!=ret && i!=0) || sumc!=ret)
            {
                ret=0;
                break;
            }
            sumd += mat[i][i];
       }
       if(sumd!=ret) ret=0;
    }
    printf("%d\n",ret);
	return 0;
}

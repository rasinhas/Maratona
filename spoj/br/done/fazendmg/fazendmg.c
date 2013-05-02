#include <stdio.h>
#define max(a,b) a > b ? a : b

int tab[1700][1700];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

int main()
{
    int a, p, x, y, l, c, i, j, k, n, m;
    while(scanf("%d", &n) && n)
    {
        a=0;
        p=0;
        m=0;
        for(j=0;j<1600;j++)
        {
            for(k=0;k<1600;k++)
            {
                tab[j][k] = 0;
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d", &x, &y, &l, &c);
            x++;y++;
            m = max(m,(max(x+l,y+c)));
            for(j=x;j<x+l;j++)
            {
                for(k=y;k<y+c;k++)
                {
                    tab[j][k] = 1;
                }
            }
        }
        for(i=0;i<m+3;i++)
        {
            for(j=0;j<m+3;j++)
            {
                if(tab[i][j]==1) a++;
                else
                {
                    for(k=0;k<4;k++)
                    {
                        if(i+dx[k]>=0 && j+dy[k]>=0 && tab[i+dx[k]][j+dy[k]]==1) p++;
                    }
                }
            }
        }
        printf("%d %d\n", a, p);
    }
    return 0;
}

#include <stdio.h>
#define min(a,b) a < b ? a : b 

int main()
{
    int val[110];
    int pd[10500];
    int n, x, y;
    int v1, v2, tot;
    int i, j ,teste=1, m, M;
    char ret;
    while(scanf("%d %d %d", &x, &y, &n) && x)
    {
        tot=x+y;
        ret='N';
        for(i=0;i<n;i++)
        {
            scanf("%d", &val[i]);
            tot += val[i];
        }
        if(tot%2!=1)
        {
            v1 = tot/2-x;
            v2 = tot/2-y;
            m = min(v1,v2);
            M = 0;
            pd[0]=1;
            for(i=1;i<=m;i++) pd[i]=0;
            for(i=0;i<n;i++)
            {
                for(j=(min(m,M));j>=0;j--)
                {
                    if(pd[j] && j+val[i]<=m) pd[j+val[i]]=1;
                }
                M += val[i];
            }
            if(pd[m]) ret='S';
        }
        printf("Teste %d\n%c\n\n", teste++, ret);
    }
    return 0;
}

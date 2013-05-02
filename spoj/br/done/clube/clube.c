#include <stdio.h>
#include <string.h>
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

int main()
{
    int m, n, l, k, i, j, t, p, a;
    int p1, p2, t1, t2;
    int tab1[10100], tab2[10100];
    while(scanf("%d%d", &m, &n) && m)
    {
        p = max(m,n);
        t1=0;
        t2=0;
        p1=-1;
        p2=-1;
        scanf("%d", &l);
        scanf("%d", &k);
        memset(tab1,0,sizeof(tab1));
        memset(tab2,0,sizeof(tab2));
        tab1[0] = 0x3f3f3f3f;
        tab2[0] = 0x3f3f3f3f;
        for(i=0;i<k;i++)
        {
            scanf("%d", &t);
            tab1[t]++;
            tab2[t]++;
        }
        if((m*100)%l==0)
        {
            p1 = (m*100)/l;
            for(i=0;i<n;i++)
            {
                if(!p1) break;
                if(i==n-i) a = min(p1,tab1[i]/2);
                else a = min(p1,min(tab1[i],tab1[n-i]));
                if(i==0) t1 += a;
                else t1 += 2*a;
                p1 -= a;
                tab1[i] -= a;
                tab1[n-i] -= a;
            }
        }
        if((n*100)%l==0)
        {
            p2 = (100*n)/l;
            for(i=0;i<m;i++)
            {
                if(!p2) break;
                if(i==m-i) a = min(p2,tab2[i]/2);
                else a = min(p2,min(tab2[i],tab2[m-i]));
                if(i==0) t2 += a;
                else t2 += 2*a;
                p2 -= a;
                tab2[i] -= a;
                tab2[m-i] -= a;
            }
        }
        if(p1 && p2) printf("impossivel\n");
        else if(p1 && !p2) printf("%d\n", t2);
        else if(!p1 && p2) printf("%d\n", t1);
        else printf("%d\n", min(t1,t2));
    }
    return 0;
}

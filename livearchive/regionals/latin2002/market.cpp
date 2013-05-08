#include <stdio.h>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

double pd[101][100001];

int main()
{
    int i, j, m, n, l;
    int list[101], k[100001];
    double p[100001];
    while(scanf("%d%d", &m, &n) && m)
    {
        for(i=0;i<m;i++) for(j=0;j<n;j++) pd[i][j] = INF;
        for(i=0;i<m;i++) scanf("%d", &list[i]);
        for(i=0;i<n;i++) scanf("%d %lf", &k[i], &p[i]);
        l = 0;
        for(i=0;i<m;i++)
        {
            for(j=l;j<n;j++)
            {
                if(j>0) pd[i][j] = pd[i][j-1];
                if(k[j] == list[i])
                {
                    if(i == 0) pd[i][j] = min(pd[i][j],p[j]);
                    else pd[i][j] = min(pd[i][j],pd[i-1][j-1]+p[j]);
                }
                if(pd[i][j-1] == INF) l=j+1;
            }
        }
        /*
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++) 
            {
                if(pd[i][j] == INF) printf("%7c ",'X');
                else printf("%7.2lf ", pd[i][j]);
            }
            printf("\n");
        }
        */
        if(pd[m-1][n-1] == INF) printf("Impossible\n");
        else printf("%.2lf\n", pd[m-1][n-1]);
    }
    return 0;
}

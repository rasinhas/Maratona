#include <stdio.h>

using namespace std;

int p[3000], c[11];

int find(int i, int f)
{
    int v=0, pos;
    for(int j=i+1;j<=f;j++)
    {
        if(p[j] > v)
        {
            v = p[j];
            pos = j;
        }
    }
    return pos;
}

int main()
{
    int t, n, k, pos;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%d", &n);
        for(int j=0;j<11;j++) c[j] = 0;
        for(int j=0;j<n;j++) scanf("%d", &p[j]);
        printf("Case %d:", i+1);
        if(n < 11) printf(" go home!");
        else
        {
            pos = -1;
            for(k=0;k<11;k++)
            {
                pos = find(pos,n-11+k);
                printf(" %d", p[pos]);
            }
        }

        printf("\n");
    }
    return 0;
}

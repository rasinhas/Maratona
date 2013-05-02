#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>

using namespace std;

int bin[300];

int main()
{
    int t, n, q, p, m;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        memset(bin,0,sizeof(bin));
        scanf("%d%d", &n, &q);
        for(int j=0;j<n;j++) 
        {
            scanf("%d", &p);
            bin[p%(1<<8)] = 1;
        }
        for(int j=0;j<q;j++)
        {
            m = 0;
            scanf("%d", &p);
            for(int k=0;k<256;k++) if(bin[k]) m = max(m,p&k);
            printf("%d\n", m);
        }
    }
    return 0;
}

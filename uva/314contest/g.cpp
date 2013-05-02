#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, k, q, p, np, m;
    int *pos;
    int a[60000], s[60000], ac[60000];
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        printf("Case %d:\n", i+1);
        scanf("%d%d%d", &n, &k, &q);
        for(int j=0;j<k;j++)
        {
            scanf("%d", &a[j]);
            s[j] = a[j];
        }
        sort(s,s+k);
        ac[0] = s[0]-1;
        for(int j=1;j<k;j++) ac[j] = ac[j-1] + s[j] - s[j-1] - 1;
        for(int j=0;j<q;j++)
        {
            scanf("%d", &p);
            if(p<=k) printf("%d\n", a[p-1]);
            else if(p>s[k-1]) printf("%d\n", p);
            else
            {
                p = p - k - 1;
                pos = upper_bound(ac,ac+k,p);
                m = (pos - ac) - 1;
                printf("%d\n", s[m]+(p-ac[m])+1);
            }
        }
    }
    return 0;
}

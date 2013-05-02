#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int s, t, n, m, k;
    int p[110000];
    scanf("%d%d%d", &n, &s, &t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &p[i]);
    }
    k = s;
    m = 0;
    while(k != t)
    {
        k = p[k];
        m++;
        if(m > n) break;
    }
    if(m > n) printf("-1\n");
    else printf("%d\n", m);
    return 0;
}

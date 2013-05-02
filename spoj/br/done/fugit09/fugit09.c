#include <stdio.h>

int main()
{
    int i, n, d, ret=0;
    long long x=0, y=0, m;
    char c;
    scanf("%d %lld", &n, &m);
    for(i=0;i<n;i++)
    {
        scanf(" %c %d", &c, &d);
        if(c=='N') y+=d;
        else if(c=='S') y-=d;
        else if(c=='L') x+=d;
        else x-=d;
        if((x*x)+(y*y) > m*m) ret=1;
    }
    printf("%d\n", ret);
    return 0;
}

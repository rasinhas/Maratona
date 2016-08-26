#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    long long x, y, m, ret;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld", &x, &y);
        m = x-y+2;
        ret = 0;
        for(int j=y-1;j*j<=x+y;j++)
        {
            if(m%j == 0) { ret = j; break; }
        }
        if(ret) printf("%lld\n", ret);
        else printf("Impossible\n");
    }
    return 0;
}

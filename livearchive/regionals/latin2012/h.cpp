#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int a[360], n, h, m, i;
    memset(a,0,360*sizeof(int));
    for(i=0;i<720;i++)
    {
        h = (i/12 * 6)%360;
        m = (i*6)%360;
        a[min(mod(h-m),360-mod(h-m))] = 1;
    }
    while(scanf("%d", &n) != EOF)
    {
        if(a[n]) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

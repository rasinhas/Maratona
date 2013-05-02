#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, x, y, a[1000];
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        if(x > 0) a[x-1] = a[x-1]+(y-1);
        if(x < n) a[x+1] = a[x+1]+(a[x]-y);
        a[x] = 0;
    }
    for(int i=0;i<n;i++) printf("%d\n", a[i]);
    return 0;
}

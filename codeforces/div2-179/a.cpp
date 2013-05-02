#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, v, f, maxv;
    int a[2000];
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    maxv = (n%2 ? (n/2)+1 : n/2);
    f = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &v);
        a[v]++;
    }
    for(int i=0;i<1001;i++)
    {
        if(a[i] > maxv)
        {
            f = 1;
            break;
        }
    }
    if(f) printf("NO\n");
    else printf("YES\n");
    return 0;
}

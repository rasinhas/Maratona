#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, k, l, r, v;
    v = 0;
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &l, &r);
        v += r - l + 1;
    }
    printf("%d\n", (k - (v%k))%k);
    return 0;
}

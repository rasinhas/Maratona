#include <stdio.h>

using namespace std;

int main()
{
    int n, k, f, t;
    int m;
    m = -1000000000;
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &f, &t);
        if(t > k) f = f-(t-k);
        if(f > m) m = f;
    }
    printf("%d\n", m);
    return 0;
}

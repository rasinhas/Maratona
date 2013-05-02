#include <stdio.h>

int func(int n, int k)
{
    if(n<=k) return 1;
    else
    {
        if(n%2==1) return func(n/2,k) + func((n/2)+1,k);
        else return 2*func(n/2,k);
    }
}

int main()
{
    int n, k, ret;
    while(scanf("%d %d", &n, &k) && n)
    {
        printf("%d\n", func(n,k));
    }
    return 0;
}

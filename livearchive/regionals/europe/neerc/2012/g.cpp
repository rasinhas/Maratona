#include <iostream>
#include <cstdio>

using namespace std;

int a[66];

int solve(int i, int k)
{
    int ret;
    if(i == 1) return a[0]+1;
    if(i%2) ret = a[i-1];
    else ret = 1;
    for(int j=0;j<i-1;j++) if(!(j%2)) ret *= k;
    if(!(i%2))
    {
        if(a[i-1] == 0) return solve(i-1,k);
        return ret;
    }
    else
    {
        if(a[i-2] != 0)
        {
            if(a[i-1] == 0) return ret + solve(i-1,k);
            return ret + ret/a[i-1];
        }
        else return ret + solve(i-1,k);
    }
}

int main()
{
    long long n;
    int k;
    while(scanf("%lld %d", &n, &k) != EOF)
    {
        int i=0;
        while(n)
        {
            a[i++] = n%k;
            n /= k;
        }
        printf("%d\n", solve(i,k));
    }
    return 0;
}

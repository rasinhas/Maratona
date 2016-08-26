#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define mod 1000000007
#define mb 10

using namespace std;

typedef long long ll;

ll fexp(ll n, ll e)
{
    if(e == 0) return 1;
    if(e%2 == 0) return fexp((1ll * n * n)%mod,e/2);
    return (1ll * n * fexp(n,e-1))%mod;
}

int solve(int n, int m, int b)
{
    if(m < (1<<b)) return solve(min(n,(1<<b)-1),m,b-1);
    int l = fexp(3,(1<<b)-1);
    if(m >= n)
    {
        int x = n-(1<<b);
        int k = (x+2)*(x+1)/2;
    }
}

class WinterAndSnowmen{
    public:
    int getNumber(int n, int m)
    {
        int r = solve(n,m,mb);
        return r;
    }
};

int main()
{
    return 0;
}

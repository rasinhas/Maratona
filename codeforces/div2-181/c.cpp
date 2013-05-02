#include <stdio.h>
#include <iostream>
#define mod 1000000007

using namespace std;

bool beautiful[10001000];
long long fat[1000001], inv[1000001];

void mark(int k, int a, int b, int p)
{
    beautiful[k] = 1;
    if(p < 10000000)
    {
        mark((a*p)+k,a,b,p*10);
        mark((b*p)+k,a,b,p*10);
    }
}

int fexp(int n, int e)
{
    if(e == 0) return 1;
    if(e == 1) return n;
    if(e%2 == 0) return fexp((1ll*n*n)%mod,e/2);
    else return (1ll*n*fexp(n,e-1))%mod;
}

int main()
{
    int a, b, n;
    long long ret, k;
    cin >> a >> b >> n;
    mark(a,a,b,10);
    mark(b,a,b,10);
    ret = 0;
    fat[0] = 1;
    for(int i=1;i<1000001;i++) fat[i] = (i*fat[i-1])%mod;
    for(int i=0;i<1000001;i++) inv[i] = fexp(fat[i],mod-2);
    for(int i=0;i<=n;i++)
    {
        k = a*i + b*(n-i);
        if(beautiful[k]) ret = (ret+(((fat[n]*inv[i])%mod)*inv[n-i])%mod)%mod;
    }
    cout << ret << endl;
    return 0;
}

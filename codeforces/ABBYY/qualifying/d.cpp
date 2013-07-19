#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define mod 1000000007
#define ll long long

using namespace std;

int a[1000001];
ll f[1000001], fi[1000001];
ll pd[1000001];

ll fexp(ll n, ll e)
{
    if(e == 0) return 1;
    if(e == 1) return n;
    if(e%2 == 0) return fexp((1ll * n * n)%mod,e/2);
    return (1ll * n * fexp(n,e-1))%mod;
}

ll inv(ll n) { return fexp(n,mod-2); }

int main()
{
    int n, c1=0;
    cin >> n;
    f[0] = 1;
    pd[0] = 1;
    pd[1] = 1;
    for(int i=1;i<1000001;i++) f[i] = (f[i-1]*i)%mod;
    for(int i=0;i<1000001;i++) fi[i] = inv(f[i]);
    for(int i=2;i<1000001;i++) pd[i] = (pd[i-1] + ((i-1)*pd[i-2])%mod)%mod;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] == 1) c1++;
    }
    cout << (((pd[c1]*f[n])%mod)*fi[c1])%mod<< endl;
    return 0;
}

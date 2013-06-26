#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007

using namespace std;

typedef long long ll;

ll pow2[1010];
ll fat[1010];
ll finv[1010];

long long fexp(ll f, ll e)
{
    if(e == 0) return 1;
    else if(e == 1) return f;
    else if(e%2 == 0) return fexp((1ll*f*f)%mod,e/2);
    else return (1ll*f*fexp(f,e-1))%mod;
}

int main()
{
    int n, m, l, s;
    int p[1010];
    long long ret=1;
    cin >> n >> m;
    pow2[0] = 1;
    fat[0] = 1;
    finv[0] = fexp(fat[0],mod-2);
    for(int i=1;i<1001;i++)
    {
        pow2[i] = (pow2[i-1]*2)%mod;
        fat[i] = (fat[i-1]*i)%mod;
        finv[i] = fexp(fat[i],mod-2);
    }
    ret = fat[n-m];
    s = 0;
    for(int i=0;i<m;i++) cin >> p[i];
    sort(p,p+m);
    for(int i=0;i<m;i++)
    {
        if(i == 0) l = p[i]-1;
        else l = p[i]-p[i-1]-1;
        if(l == 0) continue;
        if(i > 0) ret = (ret*pow2[l-1])%mod;
        ret = (ret*finv[l])%mod;
        s++;
    }
    l = n-p[m-1];
    if(l > 0)
    {
        ret = (ret*finv[l])%mod;
        s++;
    }
    cout << ret << endl;
    return 0;
}

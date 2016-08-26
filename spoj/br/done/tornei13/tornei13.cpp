#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = (ll)1e9+7;
int n;
ll f[555555], fi[555555];

ll fexp(ll n, int e) {
    if(!e) return 1ll;
    if(e%2) return (n*fexp(n, e-1))%mod;
    else return fexp((n*n)%mod, e/2)%mod;
}

ll A(ll n, ll m) { 
    if(n < m) return 0;
    return f[n]*fi[n-m]%mod; 
}

ll wok(ll k, ll l) {
    ll r = ((1<<k)*A(l,(1<<k)-1))%mod;
    r = (r*(1<<(n-k)))%mod;
    r = (r*f[(1<<n)-(1<<k)])%mod;
    return r%mod;
}

int main() {
    int k, a, l=0;
    ll p;
    cin >> n >> k;
    cin >> a;
    f[0] = 1ll;
    for(int i=1;i<=(1<<17);i++) f[i] = (f[i-1]*i)%mod;
    for(int i=0;i<=(1<<17);i++) fi[i] = fexp(f[i],mod-2);
    for(int i=1;i<(1<<n);i++) {
        int h;
        scanf("%d", &h);
        if(h < a) l++;
    }
    k--;
    if(k == n) cout << wok(k,l) << endl;
    else cout << (((wok(k,l)-wok(k+1,l))%mod)+mod)%mod << endl;
    return 0;
}

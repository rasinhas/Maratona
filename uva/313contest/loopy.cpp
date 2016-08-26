#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 100001;
long long M = 7477777;
ll f[N], inv[N];

// R = C(N-1,4)*n² - 20*C(N+1,6);
ll exp(ll n, ll e) {
    if(e == 0) return 1;
    if(e&1) return (n*exp(n,e-1))%M;
    return exp((n*n)%M,(e>>1));
}

int main() {
    int T;
    cin >> T;
    ll i4 = exp(24,M-2);
    ll i6 = exp(720,M-2);
    for(int t=1;t<=T;t++) {
        ll n;
        ll ret;
        scanf("%lld", &n);
        if(n < 5) ret = 0;
        else ret = (((((((n*n%M)*(n-1)%M)*(n-2)%M)*(n-3)%M)*(n-4)%M)*i4%M) + M - ((((((20*(n+1)%M)*n%M)*(n-1)%M)*(n-2)%M)*(n-3)%M)*(n-4)%M)*i6%M)%M;
        printf("Case %d: %lld\n", t, ret);
    }
    return 0;
}

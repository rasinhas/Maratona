#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mod = 1e9+7;

ll exp(ll v, ll e) {
    if(e == 0) return 1ll;
    if(e%2) return (1ll*v*exp(v,e-1))%mod;
    return exp((1ll*v*v)%mod,e/2);
}

ll f[1111], inv[1111];
ll dp[1111];

int c(int a, int b) { return (a >= b ? (((f[a]*inv[b])%mod)*inv[a-b])%mod : 0); }

int main() {
    int b, g;
    f[0] = 1;
    for(int i=1;i<1001;i++) f[i] = (f[i-1]*i)%mod;
    for(int i=1;i<1001;i++) inv[i] = exp(f[i],mod-2);
    while(scanf("%d%d", &b, &g) && b && g) {
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        for(int i=2;i<=g;i++) {
            ll v = exp(i,b);
            for(int j=1;j<i;j++) {
                ll x = (dp[j]*c(i,j))%mod;
                v = (v+mod-x)%mod;
            }
            dp[i] = v;
        }
        cout << dp[g]%mod << endl;
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

ll exp(ll a, ll e, ll mod) 
{
    if(e==0) return 1ll;
    if(e%2) return (1ll*a*exp(a, e-1, mod))%mod;
    return (1ll*exp((a*a)%mod, e/2, mod))%mod;
}

pii fib(ll n, ll mod) 
{
    if(n==0) return pii(0, 1);
    pii p = fib(n/2, mod);
    ll a = p.first;
    ll b = p.second;
    ll c = (((2*a*b - a*a) % mod) + mod)%mod;
    ll d = (a*a + b*b) % mod;
    if(n%2 == 0) return pii(c, d);
    return pii(d, (c+d)%mod);
}

ll prime[1000]; int nprimes;
void sieve(int n) {
    nprimes = 1; prime[0] = 2; bool is_prime;
    for(int k=3;k<=n;k+=2) {
        is_prime = true;
        for(int j=0; j<nprimes && prime[j]*prime[j] <= k;++j)
            if (k%prime[j] == 0) {is_prime = false; break;}
        if ( is_prime ) prime[nprimes++] = k;
    }
}

ll pp[500]; int e[500]; int k;
void factor(int n) {
    k = 0;
    for(int j=0; prime[j]*prime[j] <= n; ++j) if ( n%prime[j]==0 ) {
        pp[k] = prime[j]; e[k] = 0;
        while ( n%prime[j]==0 ) { n/=prime[j]; e[k]++; }
        ++k;
    }
    if (n!=1) { pp[k]=n; e[k] =1; ++k;}
}

ll phi(int n)
{
    factor(n);
    ll r=n;
    for(int i=0;i<k;i++)
    {
        r /= pp[i];
        r *= pp[i]-1;
    }
    return r;
}

int main()
{
    ll T, n, p, a, b;
    cin >> T;
    sieve(1010);
    for(int t=1;t<=T;t++)
    {
        cin >> a >> b >> p >> n;
        a %= p;
        b %= p;
        printf("Case #%d: ", t);
        if(n == 1) cout << a << endl;
        else if(n < 30)
        {
            pii f=fib(n-2,1e18);
            cout << (1ll*exp(b,f.second,p)*exp(a,f.first,p))%p << endl;
        }
        else
        {
            ll v = phi(p);
            pii f=fib(n-2,v);
            cout << (1ll*exp(b,f.second+v,p)*exp(a,f.first+v,p))%p << endl;
        }
    }
    return 0;
}

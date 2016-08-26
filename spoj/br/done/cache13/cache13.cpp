#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll mod = (ll)1e9+7;

struct matrix {
    ll a, b, c, d;
    matrix(ll a=0, ll b=0, ll c=0, ll d=0): a(a), b(b), c(c), d(d) {}
    matrix operator *(matrix m) {
        return matrix((a*m.a+b*m.c)%mod, (a*m.b+b*m.d)%mod, (c*m.a+d*m.c)%mod, (c*m.b+d*m.d)%mod);
    }
};

ll f(ll n)
{
    n--;
    matrix r(1ll,0ll,0ll,1ll), m(5ll,-2ll,1ll,0ll); 
    while(n)
    {
        if(n%2) r = r*m;
        m = m*m;
        n /= 2ll;
    }
    return ((12ll*r.a+3ll*r.b)%mod+mod)%mod;
}

int main() 
{
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}

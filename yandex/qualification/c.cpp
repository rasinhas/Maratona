#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    ll n, ret;
    cin >> n;
    ll x = ((n >> 1)&1)^(n&1?1:n);
    cout << ((n+1)*n)/2 << " ";
    ret = 0;
    if(x == 0) cout << 0 << endl;
    else 
    {
        ll i = (63-__builtin_clzll(x));
        ll e = (n>>(i+1))+1;
        ll r = (n%(1<<i))+1;
        cout << (e*r) << endl;
    }
    return 0;
}

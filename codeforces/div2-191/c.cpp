#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#define pb push_back
#define sz size()
#define mp make_pair
#define mod 1000000007

using namespace std;

typedef long long ll;

vector <int> p;

ll fexp(ll n, ll e)
{
    if(e == 0) return 1;
    if(e == 1) return n;
    if(e%2 == 0) return fexp((n*n)%mod,e/2);
    return (n*fexp(n,e-1))%mod;
}

ll inv(ll n) { return fexp(n,mod-2); }

int main()
{
    string s;
    int k;
    ll ret = 0;
    cin >> s;
    cin >> k;
    for(int i=0;i<s.sz;i++) if(s[i] == '5' || s[i] == '0') p.pb(i);
    for(int i=0;i<p.sz;i++)
    {
        ll q = fexp(2,s.sz)%mod;
        ret = (ret + (((fexp(2,p[i]) * ((fexp(q,k)+mod-1)%mod))%mod) * inv((q+mod-1)%mod))%mod)%mod;
    }
    cout << ret << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#define mod 10000000000007

using namespace std;

typedef unsigned long long ll;

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        ll l, m, n, r=0, v=1;
        cin >> l >> m >> n;
        for(int i=0;i<m;i++) v = (v*(l*l-i))%mod;
        r = v;
        for(int i=m;i<n;i++) 
        {
            v = (v*(l*l-i))%mod;
            r = (r+v)%mod;
        }
        printf("Case %d: %lld\n", t, r);
    }
    return 0;
}

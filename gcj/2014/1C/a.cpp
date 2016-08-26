#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 1ll<<40;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        ll p, q;
        scanf("%lld/%lld", &p, &q);
        ll gcd = __gcd(p,q);
        p = p/gcd;
        q = q/gcd;
        ll d = m/q; 
        if(d*q != m) printf("Case #%d: Impossible\n", t);
        else {
            ll q11 = d*p;
            int i = 0;
            for(i=40;i>=0;i--) if((1ll<<i) <= q11) break;
            if(i == 41) printf("Case #%d: Impossible\n", t);
            else printf("Case #%d: %d\n", t, 40-i);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ll a, b;
    ll l, c;
    while(scanf("%lld%lld", &a, &b) != EOF) {
        l = c = 1;
        //f(x) = 4*((a-1)+(a-3)+(a-5)+(a-7)+...+(a-2*x+1)) = 4*(x*a - x*x)
        ll lo = 0, mi, hi = a/2;
        while(lo+1 < hi) {
            mi = (lo+hi)/2;
            ll v = 4*(a*mi-mi*mi);
            if(v > b) hi = mi;
            else lo = mi;
        }
        if(4*(a*hi-hi*hi) < b) lo = hi;
        l += lo; c += lo;
        b -= 4*(a*lo-lo*lo);
        a -= 2*lo;
        b--;
        if(b){
            if(b < a) c += b;
            else { 
                c += a-1;
                b -= a-1;
                if(b < a) l += b;
                else {
                    l += a-1;
                    b -= a-1;
                    if(b < a) c -= b;
                    else {
                        c -= a-1;
                        b -= a-1;
                        l -= b;
                    }
                }
            }
        }
        cout << l << " " << c << endl;
    }
    return 0;
}


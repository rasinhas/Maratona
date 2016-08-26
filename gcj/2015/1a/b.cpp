#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll M = 1e17;

ll m[1111];
int n, b;

ll calc(ll t) {
    ll v = b;
    if(t == -1) return 0;
    for(int i=0;i<b;i++) v += t/m[i];
    return v;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> b >> n;
        for(int i=0;i<b;i++) cin >> m[i];
        ll lo = 0, mi, hi = M;
        while(hi-lo > 1) {
            mi = (lo+hi)/2;
            ll v = calc(mi);
            if(v < n) lo = mi;
            else hi = mi;
        }
        if(calc(lo) >= n) hi = lo;
        int p = n-calc(hi-1);
        int r = 0;
        for(int i=0;i<b;i++) {
            if(hi%m[i] == 0) p--;
            if(p == 0) {
                r = (i+1);
                break;
            }
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int b[111111];

ll subs(int s) { return (1ll*(s+1)*s)/2; }

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, p;
        ll r = 0ll;
        cin >> n >> p;
        for(int i=0;i<n;i++) cin >> b[i];
        b[n] = 1e9+1;
        int s = 0, e = 0, l = 0, x = 0, cv = 0;
        while(s != n) {
            if(cv + b[x] > p) {
                if(e > s) {
                    r += (subs(e-s)-subs(l-s));
                    l = e;
                    cv -= b[s];
                    s++;
                } else {
                   s++;
                    e++;
                    x++;
                    l++;
                }
            } else {
                cv += b[x];
                x++;
                e++;
            }
        }
        printf("Case #%d: %lld\n", t, r);
    }
    return 0;
}

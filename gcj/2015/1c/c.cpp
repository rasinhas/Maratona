#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll a[1111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int c, d, v;
        cin >> c >> d >> v;
        for(int i=0;i<d;i++) cin >> a[i];
        a[d] = 1ll*1e10;
        ll maxv = 0;
        int pos = 0;
        ll cnt = 0;
        for(ll i=1;i<=v;i++) {
            if(i <= maxv) continue;
            if(a[pos] <= i) maxv += c*a[pos++];
            else {
                cnt++;
                maxv += 1ll*i*c;
            }
            i = maxv;
        }
        printf("Case #%d: %lld\n", t, cnt);
    }
    return 0;
}


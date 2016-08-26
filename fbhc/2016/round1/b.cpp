#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> pii;

int w[111111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int l, n, m;
        ll ret = 0ll, d;
        cin >> l >> n >> m >> d;
        for(int i=0;i<n;i++) cin >> w[i];
        ll lo = 0ll, hi = 1e16, mi;
        while(hi > lo+1) {
            mi = (lo+hi)/2;
            ll cnt = 0;
            for(int i=0;i<n;i++) {
                cnt += mi/w[i];
                // trick to avoid stupid overflows
                if(cnt >= l) break;
            }
            if(cnt >= l) hi = mi;
            else lo = mi;
        }
        priority_queue < pair<ll,int> > q;
        for(int i=0;i<n;i++) for(int j=1;j<=(hi/w[i]);j++) q.push(mp(-1ll*w[i]*j,0));
        int cnt = l, dry=m, wait=0;
        ll tt;
        while(cnt) {
            ll tt = -q.top().ff;
            int op = q.top().ss;
            q.pop();
            if(op == 0) {
                if(dry) q.push(mp(-tt-d,1));
                else wait++;
            } else {
                if(wait) {
                    wait--;
                    q.push(mp(-tt-d,1));
                }
                cnt--;
                if(cnt == 0) {
                    ret = tt;
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n", t, ret);
    }
    return 0;
}


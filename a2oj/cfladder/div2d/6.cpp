#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
ll n, m, k;

int check(ll u) {
    ll cnt = 0, t = 0;
    for(int i=1;i<=n;i++) {
        if(u/i <= m) {
            cnt += u/i;
            if(u%i == 0) t++;
        } else cnt += m;
    }
    if(cnt < k) return -1;
    if(cnt-t+1 > k) return 1;
    return 0;
}

int main() {
    cin >> n >> m >> k;
    ll lo = 1, hi = 3e11, mi;
    while(lo < hi) {
        mi = (lo+hi)/2;
        int v = check(mi);
        if(v < 0) lo = mi;
        else if(v > 0) hi = mi;
        else break;
    }
    cout << mi << endl;
    return 0;
}


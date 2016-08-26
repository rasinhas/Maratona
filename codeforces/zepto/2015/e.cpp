#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll a[11111111];
int n, q;

ll solve(ll s, int p) {
    ll m = 1e7;
    // testa posições de 0 a p
    for(int i=0;i<p;i++) {
    }
    return m;
}

int main() {
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i+n] = a[i+2*n] = a[i];
    }
    for(int i=1;i<3*n;i++) a[i] += a[i-1];
    for(int i=0;i<q;i++) {
        ll s;
        cin >> s;
        int p = *upper_bound(a,a+n,s);
        cout << solve(s,p-1) << endl;
    }
    return 0;
}


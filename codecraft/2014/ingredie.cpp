#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1000000000;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

ll d[111][111], st[11], c[3];
ll s, n, m;

ll solve(int msk, int g) {
    int l[9];
    ll dist, sz = 0, ret = inf;
    for(int i=0;i<s;i++) if(msk&(1<<i)) l[sz++] = st[i];
    sort(l,l+sz);
    if(sz > 0) {
        do {
            dist = d[c[g]][l[0]];
            for(int i=1;i<sz;i++) dist += d[l[i-1]][l[i]];
            ret = min(ret,dist);
        } while(next_permutation(l,l+sz));
    }
    else ret = 0;
    return ret;
}

ll go() {
    ll best = inf;
    for(int i=0;i<(1<<s);i++) {
        best = min(best,solve(i,0)+solve(((1<<s)-1-i),1));
    }
    return best;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = inf;
    for(int i=0;i<n;i++) d[i][i] = 0;
    for(int i=0;i<m;i++) {
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        d[a][b] = d[b][a] = min(d[a][b],k);
    }
    scanf("%lld", &s);
    for(int i=0;i<s;i++) scanf("%lld", &st[i]);
    scanf("%lld%lld", &c[0], &c[1]);
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    ll best = go();
    cout << best << endl;
    return 0;
}

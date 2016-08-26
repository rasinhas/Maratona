#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

pii f[1111];
ll dp[1111][1111];

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        for(int i=0;i<n;i++) cin >> f[i].ff;
        for(int i=0;i<n;i++) cin >> f[i].ss;
        sort(f,f+n,greater<pii>());
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -1e17;
        for(int i=0;i<=n;i++) dp[0][i] = f[i].ff;
        ll r = 0;
        for(int i=0;i<n;i++) r = max(r,dp[0][i]);
        for(int i=1;i<n;i++) {
           for(int j=i;j<n;j++) {
               dp[i][j] = max(dp[i-1][j-1] + f[j].ff + i*f[j].ss, dp[i][j-1] + (f[j].ff - f[j-1].ff) + i*(f[j].ss - f[j-1].ss));
               r = max(r,dp[i][j]);
           }
        }
        cout << r << endl;
    }
    return 0;
}


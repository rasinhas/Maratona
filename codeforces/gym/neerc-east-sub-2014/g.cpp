#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[2][301][2];
const ll mod = 1e9+7;

int main() {
    ll n, a, b, r=0;
    cin >> n >> a >> b;
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) for(int k=1;k<=(j ? b : a);k++) dp[(i+1)&1][k][j] = 0;
        for(int j=0;j<2;j++) {
            for(int k=1;k<=(j ? b : a);k++) {
                if(i == n) {
                    r += dp[i&1][k][j];
                    if(r > mod) r -= mod;
                    continue;
                }
                if(dp[i&1][k][j]) {
                    dp[(i+1)&1][k+1][j] += dp[i&1][k][j];
                    dp[(i+1)&1][k+1][j] %= mod;
                    dp[(i+1)&1][1][1-j] += dp[i&1][k][j];
                    dp[(i+1)&1][1][1-j] %= mod;
                }
            }
        }
    }
    cout << r << endl;
    return 0;
}


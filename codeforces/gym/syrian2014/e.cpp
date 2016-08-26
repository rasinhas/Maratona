#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int dp[55][55];

int go(int n, int k) {
    if(dp[n][k] != -1) return dp[n][k];
    if(n < k) return dp[n][k] = 0;
    int kk[55];
    memset(kk,0,sizeof(kk));
    for(int i=0;i<=n-k;i++) kk[go(i,k)^go(n-i-k,k)] = 1;
    for(int i=0;i<55;i++) if(kk[i] == 0) return dp[n][k] = i;
}

int main() {
    int T, n, k;
    cin >> T;
    memset(dp,-1,sizeof(dp));
    for(int t=1;t<=T;t++) {
        cin >> n >> k;
        printf("Case %d: %s\n", t, (go(n,k) ? "Winning" : "Losing"));
    }
    return 0;
}


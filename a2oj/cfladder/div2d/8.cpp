#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[111][111][2];
int n[2], k[2];
const ll mod = 1e8;

int solve(int n1, int n2, int next) {
    if(dp[n1][n2][next] != -1) return dp[n1][n2][next];
    if(next == 0 && n1 == 0) return 0;
    if(next == 1 && n2 == 0) return 0;
    ll r = 0;
    int m = (next ? n2 : n1);
    for(int i=1;i<=min(k[next],m);i++) {
        if(next) r += solve(n1,n2-i,1-next);
        else r += solve(n1-i,n2,1-next);
    }
    r %= mod;
    return dp[n1][n2][next] = r;
}

int main() {
    cin >> n[0] >> n[1] >> k[0] >> k[1];
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 1;
    cout << (solve(n[0],n[1],0)+solve(n[0],n[1],1))%mod << endl;
    return 0;
}


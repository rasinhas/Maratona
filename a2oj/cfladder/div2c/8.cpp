#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll memo[111][2];
const ll mod = 1e9+7;

ll solve(int n, int k, int d, int f, int p) {
    if(memo[n][f] != -1) return memo[n][f];
    ll r = 0ll;
    for(int i=1;i<min(d,n+1);i++) r = (r+solve(n-i,k,d,f, p+1))%mod;
    for(int i=d;i<=min(n,k);i++) r = (r+solve(n-i,k,d,1, p+1))%mod;
    return memo[n][f] = r;
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    memset(memo,-1,sizeof(memo));
    memo[0][0] = 0;
    memo[0][1] = 1;
    cout << solve(n,k,d,0, 0) << endl;
    return 0;
}


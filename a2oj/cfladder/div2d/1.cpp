#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 1e5+1;
ll dp[MAXN+10];
const ll mod = 1e9+7;

int main() {
    int t, k;
    cin >> t >> k;
    dp[0] = 1;
    for(int i=0;i<MAXN;i++) {
        dp[i+1] = (dp[i+1]+dp[i])%mod;
        if(i+k < MAXN) dp[i+k] = (dp[i+k]+dp[i])%mod;
    }
    for(int i=1;i<MAXN;i++) dp[i] = (dp[i]+dp[i-1])%mod;
    for(int i=0;i<t;i++) {
        int a, b;
        cin >> a >> b;
        cout << (dp[b]+mod-dp[a-1])%mod << endl;
    }
    return 0;
}


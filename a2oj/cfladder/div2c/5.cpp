#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111111];
// 0 o número não é escolhido
// 1 o número é escolhido
ll dp[111111][2];

int main() {
    int n, k, mk = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &k);
        mk = max(k,mk);
        a[k]++;
    }
    ll r = 0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=mk;i++) {
        if(a[i]) {
            dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = dp[i-1][0] + 1ll*i*a[i];
        } else dp[i][0] = dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        r = max(r,max(dp[i][0],dp[i][1]));
    }
    cout << r << endl;
    return 0;
}


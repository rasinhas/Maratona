#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
string a, b;

int solve(int p, int s) {
    int retp = 0, rets = 0;
    char col = '0';
    for(int i=p+1;i<s;i++) if(a[i] != b[i]) return 1e9;
    for(int i=p;i>=0;i--) {
        if(col == '0') {
            if(a[i] == b[i]) continue;
            else {
                col = b[i];
                retp++;
            }
        } else {
            if(b[i] == col) continue;
            else {
                col = b[i];
                retp++;
            }
        }
    }
    col = '0';
    for(int i=s;i<n;i++) {
        if(col == '0') {
            if(a[i] == b[i]) continue;
            else {
                col = b[i];
                rets++;
            }
        } else {
            if(b[i] == col) continue;
            else {
                col = b[i];
                rets++;
            }
        }
    }
    return max(retp, rets);
}

int dp[111111][2], ds[111111][2];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        cin >> a;
        cin >> b;
        dp[0][0] = (a[0] == b[0] ? 0 : 1e9);
        dp[0][1] = 1;
        for(int i=1;i<n;i++) {
            dp[i][1] = dp[i-1][1];
            if(b[i] != b[i-1]) dp[i][1]++;
            if(a[i] == b[i]) dp[i][0] = dp[i-1][0];
            else dp[i][0] = 1e9;
        }
        ds[n-1][0] = (a[n-1] == b[n-1] ? 0 : 1e9);
        ds[n-1][1] = 1;
        for(int i=n-2;i>=0;i--) {
            ds[i][1] = ds[i+1][1];
            if(b[i] != b[i+1]) ds[i][1]++;
            if(a[i] == b[i]) ds[i][0] = ds[i+1][0];
            else ds[i][0] = 1e9;
        }
        int best = 1e9;
        for(int i=-1;i<n;i++) for(int j=i+1;j<=n;j++) best = min(best,max(dp[i][1],ds[j][1]));
        /*int best = 1e9;
        for(int i=-1;i<n;i++) for(int j=i+1;j<=n;j++) best = min(best,solve(i,j));
        */
        printf("Case #%d: %d\n", t, best);
    }
    return 0;
}


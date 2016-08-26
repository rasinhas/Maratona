#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double dp[2][111], p[111];
int n;

double go(int msk) {
    double ret=0;
    for(int i=1;i<=n;i++) {
        double loc=0;
        if(msk&(1<<(i-1))) loc = p[i];
        for(int j=1;j<=n;j++) {
            if((msk&(1<<(j-1))) && j != i) loc *= (1-p[j]);
        }
        ret += loc;
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    double ret = 0, ret2 = 0;
    for(int i=0;i<(1<<n);i++) {
        ret2 = max(ret2,go(i));
    }
    cout << "#" << ret2 << endl;
    for(int i=1;i<=n;i++)
    {
        dp[1][i] = (1-p[i]);
        dp[0][i] = p[i];
        for(int j=0;j<i;j++) {
            dp[1][i] = max(dp[1][i], dp[1][j]*(1-p[i]));
            dp[0][i] = max(dp[0][i], dp[1][j]*p[i]+dp[0][j]*(1-p[i]));
        }
        ret = max(ret,dp[0][i]);
    }
    for(int i=0;i<=n;i++) printf("%.6lf %.6lf\n", dp[0][i], dp[1][i]); 
    printf("%.9lf\n",ret);
    return 0;
}


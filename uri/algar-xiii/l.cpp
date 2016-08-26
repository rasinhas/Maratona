#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll a[111][111], adj[111][111], dp[111][111], val[111][111];
string s[111];

int main()
{
    int n, m, k;
    while(scanf("%d%d", &n, &m) && n) {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lld", &a[i][j]);
        cin >> k;
        for(int i=0;i<k;i++) cin >> s[i];
        memset(val,0,sizeof(val));
        for(int i=0;i<k;i++) for(int j=0;j<k;j++) {
            adj[i][j] = 1;
            for(int l=0;l<m;l++) if(s[i][l] == s[j][l] && s[i][l] != '.') adj[i][j] = 0;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                for(int l=0;l<m;l++) {
                    if(s[j][l] == '+') val[i][j] += a[i][l];
                    if(s[j][l] == '-') val[i][j] -= a[i][l];
                }
                dp[i][j] = -1e9;
            }
        }
        for(int j=0;j<k;j++) dp[0][j] = val[0][j];
        for(int i=1;i<n;i++) {
            for(int j=0;j<k;j++) {
                for(int l=0;l<k;l++) {
                    if(adj[j][l] == 1) dp[i][l] = max(dp[i][l], dp[i-1][j] + val[i][l]);
                }
            }
        }
        ll ma = -1e8;
        for(int i=0;i<k;i++) ma = max(ma,dp[n-1][i]);
        cout << ma << endl;
    }
    return 0;
}

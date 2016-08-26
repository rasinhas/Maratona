#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mod = 1e9+7;
ll dp[2222][2222];
vector <int> dv[2222];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) if(i%j == 0) dv[i].push_back(j);
    for(int i=0;i<=n;i++) dp[i][1] = 1;
    for(int i=n;i>0;i--) {
        for(int j=1;j<=k;j++) {
            for(int l=0;l<dv[i].size();l++) {
                int nn = i/dv[i][l];
                dp[nn][j+1] = (dp[nn][j+1]+dp[i][j])%mod;
            }
        }
    }
    ll r = 0;
    for(int i=1;i<=n;i++) r = (r+dp[i][k])%mod;
    cout << r << endl;
    return 0;
}


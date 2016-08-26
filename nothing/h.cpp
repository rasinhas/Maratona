#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[55][55][511];
ll a[55][55];
const ll M = 1e9+7;
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {1,-1,1,0,-1,1,0,-1};

int main() {
    int T;
    int n, m, p, x, y;
    cin >> T;
    while(T--) {
        cin >> n >> m >> p;
        memset(dp,0,sizeof(dp));
        cin >> x >> y;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
            scanf("%lld", &a[i][j]);
            dp[i][j][0] = a[i][j];
        }
        for(int k=1;k<=p;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    dp[i][j][k] = a[i][j];
                    for(int l=0;l<8;l++) {
                        dp[i][j][k] += dp[i+dx[l]][j+dy[l]][k-1];
                        if(dp[i][j][k] > M) dp[i][j][k] %= M;
                    }
                }
            }
        }
        for(int k=0;k<=p;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    printf("%5lld", dp[i][j][k]);
                }
                cout << endl;
            }
            cout << endl << endl;
        }

        printf("%lld\n", dp[x][y][p]);
    }
    return 0;
}


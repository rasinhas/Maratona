#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;

ll d[1111][1111], dp[1111][1111];

int main() 
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF) {
        d[1][1] = 0;
        for(int i=2;i<=n;i++) scanf("%lld", &d[1][i]);
        for(int i=2;i<=k;i++) for(int j=i;j<=n;j++) d[i][j] = d[1][j] - d[1][i];
        for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) dp[i][j] = inf;
        for(int i=1;i<=n;i++) dp[1][i] = d[1][i];
        for(int i=2;i<=k;i++) for(int j=1;j<=n;j++) dp[i][j] = min(dp[i-1][j-1],dp[i][j-1]+d[j-1][j]);
        printf("%d\n", dp[k][n]);
    }
    return 0;
}

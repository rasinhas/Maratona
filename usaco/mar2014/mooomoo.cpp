#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100001;
const int inf = (int)1e9;

int v[111], f[111];
int dp[111111];

int main()
{
    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);
    int n, b, best = 0;
    int cv = 0;
    int ok = 1;
    cin >> n >> b;
    for(int i=0;i<b;i++) cin >> v[i];
    for(int i=0;i<N;i++) dp[i] = inf;
    dp[0] = 0;
    for(int i=0;i<n;i++) cin >> f[i];
    for(int i=0;i<N;i++) if(dp[i] != inf) {
        for(int j=0;j<b;j++) dp[i+v[j]] = min(dp[i+v[j]],dp[i]+1);
    }
    for(int i=0;i<n;i++) {
        if(f[i] < cv) ok = 0;
        if(dp[f[i]-cv] == inf) ok = 0;
        else best += dp[f[i]-cv];
        cv += f[i]-cv;
        cv = max(cv-1,0);
    }
    if(!ok) best = -1;
    cout << best << endl;
    return 0;
}

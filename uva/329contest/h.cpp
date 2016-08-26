#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pair<pii,int> bin[33];

int n, m, k;
int dp[33][33][33][333];

void go(int cb, int lb, int llb, int cc) {
    for(int i=cb+1;i<m;i++) {
        dp[i][cb][lb][cc+b[i].ss] = max(dp[i][cb][lb][cc+b[i].ss], b[i].ss.ss);
        go(i,cb,lb,cc+b[i].ss);
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n >> m >> k;
        pair<pii,int> b;
        for(int i=1;i<=m;i++) cin >> b[i].ff.ff >> b[i].ff.ss >> c[i].ss;
        sort(b+1,b+m+1);
        for(int i=0;i<k;i++) cin >> s[i] >> f[i];
        go(0,0,0,0);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector <int> a[222222];
int dp[222222], v[222222], in[222222];

void go(int u) {
    v[u] = dp[u] = 1;
    if(a[u].size() < 2) dp[u] = 1;
    else {
        for(int i=0;i<a[u].size();i++) {
            int x = a[u][i];
            if(in[x] > 1) {
                if(!v[x]) go(x);
                dp[u] = max(dp[u],1+dp[x]);
            }
        }
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        in[y]++;
    }
    int b = 0;
    for(int i=1;i<=n;i++) {
        if(!v[i]) {
            go(i);
            b = max(b,dp[i]);
        }
    }
    cout << b << endl;
    return 0;
}

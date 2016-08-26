#include <bits/stdc++.h>

using namespace std;

int a[222], b[222], c[222];
int dp[2222];
int n;

void bfs() {
    queue<int> q;
    for(int i=0;i<n;i++) {
        dp[a[i]] = 1;
        q.push(a[i]);
    }
    while(!q.empty()) {
        int u = q.front();
        if(u <=0) cout << u << endl;
        q.pop();
        for(int i=0;i<n;i++) {
            int v = u + a[i] - b[i];
            if(v - a[i] <= 0) continue;
            if(v > 0 && v <= 1000 && dp[v] == -1) {
                dp[v] = dp[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    while(scanf("%d", &n) && n){
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        for(int i=0;i<n;i++) scanf("%d", &b[i]);
        bfs();
        if(dp[100] == -1) printf("cavaleiro morreu\n");
        else printf("%d\n", dp[100]);
    }
    return 0;
}

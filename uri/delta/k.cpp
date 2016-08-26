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
const int inf = (int)1e9;

int adj[11][11], cost[11];
int n, m, t;
int dp[11][22][55];

int main() {
    while(scanf("%d%d%d", &n, &m, &t) && n) {
        int best = inf;
        for(int i=0;i<m;i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[make_pair(a,b)] = edge[make_pair(b,a)] = i;
            a--; b--;
            if(c <= t) adj[a][b] = adj[b][a] = c;
        }
        for(int i=0;i<n;i++) scanf("%d", &cost[i]);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<=t;k++) {
                }
            }
        }
    }
    return 0;
}

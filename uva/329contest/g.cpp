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

int adj[22][22], a[22];

void go(int v) {
    
}

int main() {
    int T;
    cin >> T;
    for(int t=1;T--;t++) {
        cin >> n >> m >> k;
        memset(a,0,sizeof(a));
        memset(adj,0,sizeof(adj));
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a][b] = adj[b][a] = 1;
        }
        for(int i=0;i<n;i++) {
            if(adj[1][i]) a[i]++;;
        }
        go(n-1);
        printf("Case #%d: %d", t, r);
    }
    return 0;
}

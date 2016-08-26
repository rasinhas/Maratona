#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int w[22][22];
int best[22], worst[22];
int n;
int vis;

void dfs(int u, int d) {
    if(!d) return;
    vis |= (1<<u);
    for(int i=0;i<n;i++) if(w[u][i] && !(vis&(1<<i))) dfs(i,d-1);
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) { cin >> w[i][j]; worst[i] = 1; best[i] = n; }
        int p = n, k = 0;
        while(p) { p/=2; k++;}
        for(int i=0;i<n;i++) {
            // calculating worst position
            for(int j=0;j<n;j++) {
                if(j == i) continue;
                if(!w[i][j]) { worst[i] = (n/2)+1; break; }
            }
            vis = 0;
            dfs(i, k);
            int l = n-__builtin_popcount(vis);
            if(l == 0) best[i] = 1;
            else if(l < 3) best[i] = 2;
            else if(l < 7) best[i] = 3;
            else if(l < 15) best[i] = 5;
            else if(l < 31) best[i] = 9;
            else best[i] = 17;
        }
        printf("Case #%d:\n", t);
        for(int i=0;i<n;i++) printf("%d %d\n", best[i], worst[i]);
    }
    return 0;
}


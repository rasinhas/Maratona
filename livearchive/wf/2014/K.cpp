#include <bits/stdc++.h>
using namespace std;

const int N=2e6+1;

int t[N][30], n, tree[N];

void update(int a, int v) {for(;a<=2*n;a+=a&-a) tree[a] = max(tree[a], v); }
int query(int a) { int ret=a; for(;a;a-=a&-a) ret = max(ret, tree[a]); return ret; }
 
int valid(int pos, int dest, int m) {
    for(int i=0;i<29;i++) if(m & (1<<i)) {
        pos = t[pos][i];
    }
    return pos >= dest;
}

int main() {
    int k;
    scanf("%d%d", &n, &k);
    for(int i=0;i<k;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(b < a) b += n;
        update(a, b+1);
    }
    for(int i=1;i<=2*n;i++) t[i][0] = query(i);
    t[2*n+1][0] = 2*n+1;
    for(int l=1;l<30;l++) for(int i=1;i<=2*n+1;i++) t[i][l] = t[t[i][l-1]][l-1];
    int ans=1e9;
    for(int i=1;i<=n;i++) {
        if(t[i][29] < i+n) continue;
        int l = 0;
        int r = k;
        while(l<r-1) {
            int m = (l+r)/2;
            if(valid(i, i+n, m)) r=m;
            else l=m;
        }
        ans = min(ans, r);
    }
    if(ans == 1e9) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}

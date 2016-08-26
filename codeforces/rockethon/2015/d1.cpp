#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

char rel[111][111];
int l[111], r[111];
int n, m;

int go(int u, int first, int last) {
    int lc = 0, rc = 0;
    int mr = n+1, ml = 0;
    if(first == last) return last;
    for(int j=1;j<=n;j++) {
        if(rel[u][j] == 'l') {
            lc++;
            ml = max(ml,j);
        }
        else if(rel[u][j] == 'r') {
            rc++;
            mr = min(mr,j);
        }
    }
    last = max(ml,last);
    if(ml >= mr) return -1;
    if(lc && rc) {
        l[u] = u+1;
        int k = go(u+1,u+1,ml);
        if(k == -1) return -1;
        r[u] = k+1;
        return go(k+1,k+1,last);
    } else if(lc || rc) {
        if(lc) l[u] = u+1;
        else r[u] = u+1;
        return go(u+1,u+1,last);
    } else {
        if(u >= last) return u;
        else {
            l[u] = u+1;
            return go(u+1,u+1,last);
        }
    }
}

void dfs(int u) {
    if(l[u] != -1) dfs(l[u]);
    printf("%d ", u);
    if(r[u] != -1) dfs(r[u]);
}

int main() {
    cin >> n >> m;
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    for(int i=0;i<m;i++) {
        int a, b;
        string c;
        cin >> a >> b >> c;
        if(c == "RIGHT") rel[a][b] = 'r';
        else rel[a][b] = 'l';
    }
    int r = go(1,1,n);
    if(r == -1) cout << "IMPOSSIBLE" << endl;
    else {
        dfs(1);
        cout << endl;
    }
    return 0;
}


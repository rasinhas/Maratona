#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[11111], g[11111], p[11111];
int n, fail;
queue <int> q;

void solve(int u) {
    if(g[u] < 0) return;
    if(g[a[u]] < 0) {
        fail = 1;
        return;
    }
    p[u] = a[u];
    p[a[u]] = u;
    g[u] = -1;
    g[a[u]] = -1;
    solve(a[a[u]]);
}

int main() {
    while(scanf("%d", &n) != EOF) {
        memset(g,0,sizeof(g));
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++) {
            scanf("%d", &a[i]);
            g[a[i]]++;
        }
        while(!q.empty()) q.pop();
        fail = 0;
        if(n%2 == 1) fail = 1;
        if(!fail) {
            while(1) {
                for(int i=1;i<=n;i++) if(g[i] == 0) q.push(i);
                if(q.empty()) {
                    int i;
                    for(i=1;i<=n;i++) if(g[i] > 0) solve(i);
                    break;
                }
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    g[u] = -1;
                    if(g[a[u]] < 0) fail = 1;
                    if(fail) break;
                    p[u] = a[u];
                    p[a[u]] = u;
                    g[a[u]] = -1;
                    g[a[a[u]]]--;
                }
                if(fail) break;
            }
        }
        if(fail) cout << "IMPOSSIBLE";
        else for(int i=1;i<=n;i++) {
            if(i>1) printf(" ");
            printf("%d", p[i]);
        }
        printf("\n");
    }
    return 0;
}


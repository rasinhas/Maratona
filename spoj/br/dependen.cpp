#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> dep[111];
int ndep[111];
int vis[111];

void solve(int u) {
    if(vis[u] == 1) return;
    int s = dep[u].size();
    vis[u] = 1;
    for(int i=0;i<dep[u].size();i++) {
        int v = dep[u][i];
        if(!vis[v]) solve(v); 
        s += ndep[v];
    }
    ndep[u] = s;
}

int main() {
    int n, a, t;
    while(scanf("%d", &n) && n) {
        memset(vis,0,sizeof(vis));
        memset(ndep,0,sizeof(ndep));
        for(int i=1;i<=n;i++) {
            scanf("%d", &t);
            dep[i].clear();
            for(int j=0;j<t;j++) {
                scanf("%d", &a);
                dep[i].push_back(a);
            }
        }
        for(int i=1;i<=n;i++) if(!vis[i]) solve(i);
        int m = *max_element(ndep,ndep+n+1);
        for(int i=1;i<=n;i++) {
            if(ndep[i] == m) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}


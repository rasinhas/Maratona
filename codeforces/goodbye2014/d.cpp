#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <pii> adj[111111];
vector <pair<pii,int> > edg;
map <pii,int> mte;
double times[111111];
ll vis[111111], under[111111];
ll n;

void go(int u, int p) {
    vis[u] = 1;
    under[u] = 1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i].ff;
        if(!vis[v]) {
            go(v, u);
            under[u] += under[v];
        }
    }
    if(p >= 0) times[mte[mp(u,p)]] = 6.0*((n-under[u])*(under[u]*(under[u]-1)) + under[u]*((n-under[u])*(n-under[u]-1)))/(1.0*n*(n-1)*(n-2));
}

int main() {
    int a, b, c, q;
    cin >> n;
    for(int i=0;i<n-1;i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
        edg.push_back(mp(mp(a,b),c));
        mte[mp(a,b)] = i;
        mte[mp(b,a)] = i;
    }
    go(0,-1);
    double p = 0;
    for(int i=0;i<n-1;i++) {
        p += 1ll*times[i]*edg[i].ss;
    }
    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> a >> b;
        double r = 0.0;
        a--;
        p -= 1ll*times[a]*edg[a].ss;
        p += 1ll*times[a]*b;
        edg[a].ss = b;
        r = 1.0*p;
        printf("%.6lf\n", r);
    }
    return 0;
}


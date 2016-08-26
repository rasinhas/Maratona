#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

pair<int,int> cast[1111], aux[1111];
vector <int> adj[1111];

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.ff - a.ss) > (b.ff - b.ss);
}

void go(int u, int p) {
    vector<pair<int,int> > k;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(v != p) {
            go(v,u);
            k.push_back(aux[v]);
        }
    }
    sort(k.begin(),k.end(),cmp);
    int need = 0, die = 0, alive = 0;
    for(int i=0;i<k.size();i++) {
        if(k[i].ff > alive) need += (k[i].ff-alive);
        die += k[i].ss;
        alive = need - die;
    }
    die += aux[u].ss;
    need = max(need+aux[u].ss, aux[u].ff);
    aux[u] = make_pair(need,die);
}

int main() {
    int n, t=1;
    while(cin >> n && n) {
        int a, b, c;
        for(int i=0;i<n;i++) {
            cin >> a >> b >> c;
            cast[i] = make_pair(max(a,b+c),b+c);
            adj[i].clear();
        }
        for(int i=1;i<n;i++) {
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int best = 1e9;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) aux[j] = cast[j];
            go(i,-1);
            best = min(best,aux[i].ff);
        }
        printf("Case %d: %d\n", t++, best);
    }
    return 0;
}

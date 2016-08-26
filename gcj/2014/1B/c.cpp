#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;

string s[55];
vector <int> adj[55];
int p[55];
int vis[55];
ll vmsk;
int n, m;

int dfs(int u, ll msk) {
    vmsk |= (1ll<<u);
    if((vmsk|msk) == (1ll<<n)-1) return 1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if((vmsk&(1ll<<v)) == 0 && (msk&(1ll<<v)) == 0) {
            int k = dfs(v,msk);
            if(k) return k;
        }
    }
    return 0;
}

ll valid(int cur, int idx, ll msk) {
    if(cur == -1) return msk;
    for(int i=0;i<adj[cur].size();i++) {
        int v = adj[cur][i];
        if(v == idx) {
            vmsk = 0;
            if(dfs(idx,msk)) {
                p[idx] = cur;
                return msk;
            }
            return -1;
        }
    }
    if(p[cur] != -1) return valid(p[cur],idx,(msk|(1ll<<cur)));
    return -1;
}

string solve(int idx) {
    int u = -1;
    string ret = "";
    vector <pair<string, int> > q;
    q.push_back(mp(s[idx],idx));
    p[idx] = -1;
    vis[idx] = 1;
    long long msk = 0;
    for(int i=0;i<n;i++) {
        sort(q.begin()+i,q.end());
        for(int j=i;j<q.size();j++) {
            ll m2 = valid(u, q[j].ss, msk);
            if(m2 != -1) {
                msk |= m2;
                swap(q[j],q[i]);
                break;
            }
        }
        u = q[i].ss;
        ret += q[i].ff;
        for(int j=0;j<adj[u].size();j++) {
            int v = adj[u][j];
            if(!vis[v]) {
                q.push_back(mp(s[v],v));
                vis[v] = 1;
            }
        }
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n >> m;
        for(int i=0;i<n;i++) {
            cin >> s[i];
            adj[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(p,0,sizeof(p));
        for(int i=0;i<m;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        string st=s[0];
        int idx=0;
        for(int i=0;i<n;i++) if(s[i] < st) {
            st = s[i];
            idx = i;
        }
        printf("Case #%d: ", t);
        cout << solve(idx) << endl;
    }
    return 0;
}

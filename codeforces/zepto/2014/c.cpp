#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string l[1111][11];
int d[1111][1111];
int vis[1111];
int fat[1111];
int n, m, k, w;
vector <int> v;

ll solve() {
    priority_queue<pair<pii,int> > q;
    ll r = 0;
    int vv = 0;
    for(int i=1;i<=k;i++) q.push(mp(mp(-(m*n), i),0));
    while(!q.empty()) {
        int u = q.top().ff.ss;
        int dd = -q.top().ff.ff;
        int p = q.top().ss;
        if(vv == k) return r;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        fat[u] = p;
        r += dd;
        vv++;
        v.push_back(u);
        for(int i=1;i<=k;i++) {
            if(!vis[i]) q.push(mp(mp(-d[i][u]*w,i),u));
        }
    }
    return r;
}

int main() {
    cin >> n >> m >> k >> w;
    for(int i=1;i<=k;i++) for(int j=0;j<n;j++) cin >> l[i][j];
    ll ret = m*n;
    for(int i=1;i<=k;i++) {
        for(int j=i+1;j<=k;j++) {
            for(int o=0;o<n;o++) {
                for(int p=0;p<m;p++) {
                    if(l[i][o][p] != l[j][o][p]) d[i][j]++, d[j][i]++;
                }
            }
        }
    }
    cout << solve() << endl;
    for(int i=0;i<k;i++) cout << v[i] << " " << fat[v[i]] << endl;
    return 0;
}


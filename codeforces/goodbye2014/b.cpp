#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[333], r[333];
string t[333];
vector <int> v[333], vv[333];
int vis[333];
int n, cc;

void go(int u) {
    vis[u] = cc;
    v[cc].push_back(u);
    vv[cc].push_back(p[u]);
    for(int i=0;i<n;i++) if(t[u][i] == '1' && !vis[i]) go(i);
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &p[i]);
    for(int i=0;i<n;i++) cin >> t[i];
    cc = 1;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            go(i);
            sort(vv[cc].begin(),vv[cc].end());
            sort(v[cc].begin(),v[cc].end());
            for(int i=0;i<v[cc].size();i++) r[v[cc][i]] = vv[cc][i];
            cc++;
        }
    }
    for(int i=0;i<n;i++) printf("%d ", r[i]);
    cout << endl;
    return 0;
}


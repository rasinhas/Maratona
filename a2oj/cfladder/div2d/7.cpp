#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[3333];
int w[3333];

void go(int u, int d) {
    if(d == 0) w[u]++;
    else {
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];
            go(v,d-1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    ll r = 0;
    for(int i=0;i<n;i++) {
        memset(w,0,sizeof(w));
        go(i,2);
        for(int j=0;j<n;j++) if(j != i) r += (w[j]*(w[j]-1))/2;
    }
    cout << r << endl;
    return 0;
}

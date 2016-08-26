#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string a[1111];
int vis[1111], cc;

void dfs(int u) {
    vis[u] = cc;
    for(int i=0;i<a[u].size();i++) {
        if(!vis[i] && a[u][i] == '1') dfs(i);
    }
}

int main() {
    int n;
    while(scanf("%d", &n) && n){
        cc = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cc++;
                dfs(i);
            }
        }
        int ok = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i != j && a[i][j] == '0' && vis[i] == vis[j]) ok = 0;
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(!ok) cout << "impossivel" << endl;
        else cout << cc << endl;
    }
    return 0;
}


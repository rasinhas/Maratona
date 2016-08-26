#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[444], adjt[444];
int vis[444], vist[444];

void dfs(int u) {
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    vis[u] = 2;
}

void dfst(int u) {
    vist[u] = 1;
    for(int i=0;i<adjt[u].size();i++) {
        int v = adjt[u][i];
        if(!vist[v]) dfst(v);
    }
    vist[u] = 2;
}

int main() {
    int n, m;
    char c;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> c;
        for(int j=0;j<m-1;j++) {
            if(c == '>') {
                adj[i*m+j].push_back(i*m+j+1);
                adjt[i*m+j+1].push_back(i*m+j);
            } else {
                adj[i*m+j+1].push_back(i*m+j);
                adjt[i*m+j].push_back(i*m+j+1);
            }
        }
    }
    for(int i=0;i<m;i++) {
        cin >> c;
        for(int j=0;j<n-1;j++) {
            if(c == 'v') {
                adj[j*m+i].push_back((j+1)*m+i);
                adjt[(j+1)*m+i].push_back(j*m+i);
            } else {
                adjt[j*m+i].push_back((j+1)*m+i);
                adj[(j+1)*m+i].push_back(j*m+i);
            }
        }
    }
    dfs(0); 
    dfst(0);
    int ok = 1;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(vis[i*m+j] == 0 || vist[i*m+j] == 0) ok = 0;
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}


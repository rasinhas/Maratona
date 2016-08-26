#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[111111];
int b[111111], d[2][111111];

void go(int u, int p) {
    if(p >= 0) {
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int k;
        cin >> b[i] >> k;
        for(int j=0;j<k;j++) {
            scanf("%d", &a); a--;
            adj[i].push_back(a);
        }
    }
    go(0,-1);
    for(int i=0;i<n;i++) {
        if(d[0][i] == 0) cout << "sober ";
        else if(d[0][i] == -1) cout << "unknown ";
        else cout << d[0][i] << " ";
        if(d[1][i] == 0) cout << "sober" << endl;
        else if(d[1][i] == -1) cout << "unknown" << endl;
        else cout << d[1][i] << endl;
    }
    return 0;
}


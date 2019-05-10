#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
typedef long long ll;

using namespace std;

int a[55][55], b[55][55], c[55][55], d[55][55];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> b[i][j];
        c[i][j] = min(a[i][j], b[i][j]);
        d[i][j] = max(a[i][j], b[i][j]);
    }
    int o = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m-1;j++) {
            if(c[i][j] >= c[i][j+1]) o = 0;
            if(d[i][j] >= d[i][j+1]) o = 0;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n-1;j++) {
            if(c[j][i] >= c[j+1][i]) o = 0;
            if(d[j][i] >= d[j+1][i]) o = 0;
        }
    }
    if(o) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}

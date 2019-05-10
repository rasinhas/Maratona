#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
typedef long long ll;

using namespace std;

vector <pair<ll,ll> > a;

int y[55];

int main() {
    int n, h, m, l, r, x;
    cin >> n >> h >> m;
    for(int i=0;i<n;i++) y[i] = h;
    for(int i=0;i<m;i++) {
        cin >> l >> r >> x;
        l--; r--;
        for(int j=l;j<=r;j++) y[j] = min(y[j],x);
    }
    int v = 0;
    for(int i=0;i<n;i++) v += y[i]*y[i];
    cout << v << endl;
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll mod = (int)1e9+7;
const int N = 1001;
ll f[1111];
ll c[1111][1111];

int main() {
    int t, n, k;
    cin >> t;
    f[0] = 1;
    for(int i=1;i<N;i++) f[i] = (f[i-1]*i)%mod;
    c[0][0] = 1;
    for(int i=1;i<N;i++) {
        c[i][0] = 1;
        for(int j=1;j<N;j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
        }
    }
    while(t--) {
        cin >> n >> k;
        cout << (f[k-1]*c[n-k+2][n-k-1])%mod << endl;
    }
    return 0;
}

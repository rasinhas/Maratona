#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll v[333333];

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF) {
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                int z;
                scanf("%d", &z);
                if(z%2) v[i] += (1ll<<(k-j-1));
            }
        }
        int ok = 1;
        if(n <= k) ok = 0;
        for(int i=0;i<k;i++) {
            ll m = -1, mi = -1;
            for(int j=i;j<n;j++) {
                if(v[j] > m) {
                    m = v[j];
                    mi = j;
                }
            }
            swap(v[i],v[mi]);
            if((v[i]&(1ll<<(k-i-1))) == 0) {
                ok = 0;
                break;
            }
            for(int j=i+1;j<n;j++) {
                if((v[j]&(1ll<<(k-i-1)))) v[j] ^= v[i];
            }
        }
        cout << (ok ? "N" : "S") << endl;
    }
    return 0;
}


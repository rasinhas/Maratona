#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T, k, c, s;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> k >> c >> s;
        printf("Case #%d:", t);
        if(s*c < k) cout << " IMPOSSIBLE" << endl;
        else {
            int v = 0;
            for(int i=0;i<(k+c-1)/c;i++) {
                ll p = 0ll, kk = 1ll;
                for(int j=0;j<c;j++) {
                    p += kk*v;
                    kk *= k;
                    v = min(v+1,k-1);
                }
                cout << " " << p+1;
            }
            cout << endl;
        }
    }
    return 0;
}


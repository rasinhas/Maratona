#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T;
    ll k, c, s;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> k >> c >> s;
        printf("Case #%d:", t);
        for(int i=0;i<k;i++) {
            ll v = 0ll, kk = 1ll;
            for(int j=0;j<c;j++) {
                v += kk*i;
                kk *= k;
            }
            printf(" %lld", v+1);
        }
        cout << endl;
    }
    return 0;
}


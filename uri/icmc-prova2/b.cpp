#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int q[11111], ck[11111];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int d, k, b;
        cin >> d >> k >> b;
        for(int i=0;i<k;i++) cin >> q[i];
        for(int i=0;i<b;i++) {
            ck[i] = 0;
            int n;
            cin >> n;
            for(int j=0;j<n;j++) {
                int aa, bb;
                cin >> aa >> bb;
                ck[i] += q[aa]*bb;
            }
        }
        int r = *min_element(ck,ck+b);
        cout << (int)d/r << endl;
    }
    return 0;
}


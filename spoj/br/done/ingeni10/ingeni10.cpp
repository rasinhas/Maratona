#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int tp[111111];

int mod(int x) { return x > 0 ? x : -x; }

int main() {
    int t, q;
    while(scanf("%d %d", &t, &q) && t) {
        int g;
        for(int i=0;i<t;i++) cin >> tp[i];
        if(t > 1) {
            g = 2*mod(tp[1]-tp[0]);
            for(int i=2;i<t;i++) g = __gcd(g,2*mod(tp[i]-tp[i-1]));
        }
        for(int i=0;i<q;i++) {
            int a, b;
            cin >> a >> b;
            if(i) cout << " ";
            if(t == 1) cout << (mod(tp[0]-a) == mod(tp[0]-b) ? "Y" : "N");
            else cout << ((mod(a-b)%g) == 0 ? "Y" : "N");
        }
        cout << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll c[111111];

ll integ(ll a, ll b) { return (1ll*b*b - 1ll*a*a); }

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        ll a, b, n;
        cin >> n >> a >> b;
        for(int i=0;i<n;i++) { cin >> c[i]; if(i) c[i] += c[i-1]; }
        ll v = c[n-1];
        ll ret = 0ll;
        int f = a/v, l=(b-1)/v;
        for(int i=0;i<n;i++) {
            ll s=0, e=c[i];
            if(i) s = c[i-1];
            int fn = f, ln = l;
            int k = l-f;
            if(a > f*v+s) k--;
            if(b < l*v+e) k--;
            ret += (k+1)*integ(0,e-s);
            if(a > f*v + s && a <= f*v+e) ret += integ(a-f*v-s,e-s);
            if(b < l*v + e && b >= l*v+s) ret += integ(0,b-l*v-s);
        }
        double dr = 1.0*ret/(2.0*(b-a));
        printf("Case #%d: %.9lf\n", t, dr);
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const double pi = acos(-1);

double x[444], y[444];

int main() {
    int t;
    cin >> t;
    while(t--) {
        double a, l;
        ll n;
        cin >> a >> l >> n;
        if(a > 359) a -= 360;
        if(a == 0) prinf("%.2lf %.2lf", l*n, 0.0);
        else {
            x[0] = y[0] = y[1] = 0;
            x[1] = l;
            double g = (1.0*a)*PI/180.0;
            int p = 360/__gcd(a,360);
            double ns = 0;
            for(int i=2;i<p;i++) {
                ns = hypot(x[i-1],y[i-1]);
            }
        }
    }
    return 0;
}


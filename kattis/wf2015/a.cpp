#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double v[1111111];

int main() {
    double p, a, b, c, d;
    int n;
    cin >> p >> a >> b >> c >> d >> n;
    for(int i=1;i<=n;i++) v[i] = p*(sin(a*i+b)+cos(c*i+d)+2.0);
    double big = v[1], best = 0.0;
    for(int i=2;i<=n;i++) {
        best = max(best,big-v[i]);
        big = max(big,v[i]);
    }
    printf("%.9lf\n", best);
    return 0;
}

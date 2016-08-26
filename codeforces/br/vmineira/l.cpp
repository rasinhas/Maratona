#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;
#define EPS 1e-6

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double pi = acos(-1);

int main() {
    double r = 0.0;
    int r1, r2;
    int p, n;
    double x=0.0, y=0.0, cr = 0.0;
    char z[3][33];
    while(scanf("%s %d.%d %s %d %s %d", z[0], &r1, &r2, z[1], &p, z[2], &n) != EOF) {
        int a = 10*r1+r2;
        r = 1.0*r1 + r2/10.0;
        int q = (a == 0 ? n : n%(3600/__gcd(a,3600)));
        double pp = 1.0*p;
        for(int i=0;i<q;i++) {
            x += pp*sin(1.0*(cr+(i+1.0)*r)*pi/180.0);
            y += pp*cos(1.0*(cr+(i+1.0)*r)*pi/180.0);
        }
        cr = (cr+r*(1.0*q));
    }
    printf("%.2lf %.2lf\n", x+EPS, y+EPS);
    return 0;
}



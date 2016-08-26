#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double pi = acos(-1);

int main() {
    double r;
    int p, n;
    double x=0.0, y=0.0;
    double ca = 0.0;
    char z[3][33];
    while(scanf("%s %lf %s %d %s %d", z[0], &r, z[1], &p, z[2], &n) != EOF) {
        for(int i=0;i<n;i++) {
            ca += r;
            while(ca >= 360.0) ca -= 360.0;
            x += p*sin(1.0*ca*pi/180.0);
            y += p*cos(1.0*ca*pi/180.0);
        }
    }
    printf("%.2lf %.2lf\n", x+EPS, y+EPS);
    return 0;
}


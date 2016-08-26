#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define INF 1e9
const double PI = acos(-1);

typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*PI;
    while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
    return a;
}

struct pt {
    double x, y;

    pt(double x=0, double y=0): x(x), y(y) {}

    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator ==(pt p) { return cmp(p) == 0; }
    bool operator !=(pt p) { return cmp(p) != 0; }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator >(const pt &p)const { return cmp(p) > 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    bool operator >=(const pt &p)const { return cmp(p) >= 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
};

pt pivot;

typedef vector<pt> polygon;

double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

double arg(pt p) { return atan2(p.y, p.x); }

bool clockwise(pt p, pt q) {
    double a = positive_angle(arg(p-pivot));
    double b = positive_angle(arg(q-pivot));
    if(cmpD(a, b) == 0) return abs(p, pivot) < abs(q, pivot);
    return a < b;
}

bool radial_lt(pt p, pt q) {
    pt P = p - pivot, Q = q - pivot;
    double R = P % Q;
    if(cmpD(R)) return cmpD(R) > 0;
    return cmpD(P*P, Q*Q) > 0;
}

int a;
pt pto[1111];
pt hull[1111];

int convex_hull() {
    int i, j=0, k, n=a;
    pivot = *min_element(pto,pto+a);
    sort(pto,pto+a, radial_lt);
    for(k=n-2; k>=0 && pto[0].prod(pto[k], pto[n-1]) == 0; k--) ;
    reverse((k+1) + pto,pto+n);
    for(i=0;i<n;i++) {
        while(j>1 && pto[i].prod(hull[j-1], hull[j-2]) <= 0) j--;
        hull[j++] = pto[i];
    }
    return j;
}

int main() {
    int d;
    while(scanf("%d%d", &a, &d) != EOF) {
        for(int i=0;i<a;i++) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            pto[i] = pt(x,y);
        }
        int k = convex_hull();
        double ret = 0;
        for(int i=0;i<k;i++) {
            ret += abs(hull[i],hull[(i+1)%k]);
        }
        printf("%.2lf\n", ret);
    }
    return 0;
}



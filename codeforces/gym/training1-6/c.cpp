#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-6
#define INF 1e9
const double PI = acos(-1);

using namespace std;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

double canonic_angle(double a) {
    a = a * PI / 180;
    while(cmpD(a) < -PI) a += 2*PI;
    while(cmpD(a, PI) >= 0) a -= 2*PI;
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
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

int main()
{
    pt p1, p2, p3, p4;
    int t;
    double a1, a2;
    cin >> t;
    while(t--)
    {
        cin >> p1.x >> p1.y >> a1;
        cin >> p3.x >> p3.y >> a2;
        a1 = 360 - a1 + 90;
        a2 = 360 - a2 + 90;
        if(a1 == 90 || a1 == 270) 
        {
            p2.x = p1.x;
            p2.y = p1.y+1;
        }
        else
        {
            p2.x = p1.x+1;
            p2.y = p1.y+tan(canonic_angle(a1));
        }
        if(a2 == 90 || a2 == 270)
        {
            p4.x = p3.x;
            p4.y = p3.y+1;
        }
        else
        {
            p4.x = p3.x+1;
            p4.y = p3.y+tan(canonic_angle(a2));
        }
        pt i = line_intersect(p1,p2,p3,p4);
        printf("%.4lf %.4lf\n", i.x, i.y);
    }
    return 0;
}

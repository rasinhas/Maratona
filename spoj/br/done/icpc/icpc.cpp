#include <stdio.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    friend ostream& operator <<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef pair<point, double> circle;

bool in_circle(circle C, point p)
{
    return cmp(abs(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r) 
{
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle(vector<point>& T) 
{
    int n = T.size();
    random_shuffle(T.begin(),T.end());
    circle C(point(), -INF);
    for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
        C = circle(T[i], 0);
        for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
            C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
            for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
                point o = circumcenter(T[i], T[j], T[k]);
                C = circle(o, abs(o - T[k]));
            }
        }
    }
    return C;
}

int main()
{
    vector <point> points;
    int n, teste=0, i;
    double x, y;
    circle circ;
    while(scanf("%d", &n) && n)
    {
        points.clear();
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf", &x, &y);
            points.push_back(point(x,y));
        }
        circ = spanning_circle(points);
        printf("Instancia %d\n%.2lf %.2lf %.2lf\n\n", ++teste, circ.first.x, circ.first.y, circ.second);
    }
    return 0;
}

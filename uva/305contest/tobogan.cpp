#include <iostream>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define EPS 1e-6

using namespace std;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

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
};

double abs(pt p, pt q) { return hypot(p.x-q.x, p.y-q.y); }

int ccw(pt p, pt q, pt r) { return cmpD((q-p) % (r-p)); }

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

bool between(pt p, pt q, pt r) { return ccw(p, q, r) == 0 && cmpD((p-q) * (r-q)) <= 0; }

double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a + project(p-a, b-a);
    if(between(a, pp, b)) return abs(p, pp);
    return min(abs(p, a), abs(p, b));
}

pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r;
    pt c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

bool seg_intersect(pt p, pt q, pt r, pt s) {
    pt a = line_intersect(p, q, r, s);
    if(a == pt(INF, INF)) return 0;
    return between(p, a, q) && between(r, a, s);
}

double dist_seg_seg(pt p, pt q, pt r, pt s) { 
    if(seg_intersect(p,q,r,s)) return 0;
    return min(min(dist_pt_seg(p ,r, s), dist_pt_seg(q, r, s)), min(dist_pt_seg(r, p, q), dist_pt_seg(s, p, q)));
}

int main()
{
    int n, l, h, i;
    double y1, x2, y2;
    double d1 ,d2, dist;
    pt reta[1010][2];
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d %d", &l, &h);
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf %lf", &y1, &x2, &y2);
            if(i%2 == 0) reta[i][0] = pt(0,y1);
            else reta[i][0] = pt(l,y1);
            reta[i][1] = pt(x2,y2);
        }
        dist = l - reta[0][1].x;
        for(i=1;i<n;i++)
        {
            if(i%2 == 0) d1 = l - reta[i][1].x;
            else d1 = reta[i][1].x;
            dist = min(dist,d1);
            d2 = dist_seg_seg(reta[i][0],reta[i][1],reta[i-1][0],reta[i-1][1]);
            dist = min(dist,d2);
        }
        printf("%.2lf\n", dist);
    }
	return 0;
}

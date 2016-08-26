#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#define EPS 1e-6
#define pb push_back
#define mp make_pair
#define sz size()

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
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    bool operator >=(const pt &p)const { return cmp(p) >= 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }

    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

pt project_pt_line(pt p, pt a, pt b) { return a + project(p-a, b-a); }

vector <pt> pts;

int vis[222222];

pt a, b, c, d;
int n, m;

int search(pt p, int l)
{
    int lo, hi, mi, r;
    lo = l*n;
    hi = n+(l*m)-1;
    for(int i=lo;i<hi;i++)
    {
        if(pts[i].x > p.x) return max(0,i-1);
    }
    while(lo < hi)
    {
        mi = (lo+hi)/2;
        if(pts[mi].x > p.x)
        {
            hi = mi-1;
            if(pts[mi-1] <= p.x) return mi-1;
        }
        else 
        {
            lo = mi+1;
            if(pts[mi+1] > p.x) return mi;
        }
    }
    return mi;
}

double prim(int a)
{
    double t = 0;
    priority_queue <pair<double,int> > q;
    q.push(mp(0.0,a));
    vis[a] = 1;
    while(!q.empty())
    {
        int u = q.top().second;
        double d = q.top().first;
        t -= d;
        vis[u] = 1;
        q.pop();
        if(u < n)
        {
            if(u > 0 && !vis[u-1]) q.push(mp(-hypot(pts[u].x-pts[u-1].x,pts[u].y-pts[u-1].y), u-1));
            if(u <= n && !vis[u+1]) q.push(mp(-hypot(pts[u].x-pts[u+1].x,pts[u].y-pts[u+1].y), u+1));
            pt p = project_pt_line(pts[u],c,d);
            int idx = search(p,0);
            if(idx > n && !vis[idx]) q.push(mp(-hypot(pts[u].x-pts[idx].x,pts[u].y-pts[idx].y), idx));
            if(idx <= n+m && !vis[idx+1]) q.push(mp(-hypot(pts[u].x-pts[idx].x,pts[u].y-pts[idx].y), idx+1));
        }
        else 
        {
            if(u > n) q.push(mp(-hypot(pts[u].x-pts[u-1].x,pts[u].y-pts[u-1].y), u-1));
            if(u <= n+m) q.push(mp(-hypot(pts[u].x-pts[u+1].x,pts[u].y-pts[u+1].y), u+1));
            pt p = project_pt_line(pts[u],a,b);
            int idx = search(p,1);
            if(idx >= 0 && !vis[idx]) q.push(mp(-hypot(pts[u].x-pts[idx].x,pts[u].y-pts[idx].y), idx));
            if(idx <= n && !vis[idx+1]) q.push(mp(-hypot(pts[u].x-pts[idx].x,pts[u].y-pts[idx].y), idx+1));
        }
    }
    return t;
}

int main()
{
    int T;
    cin >> T;
    for(int C=1;C<=T;C++)
    {
        double t;
        pts.clear();
        cin >> n >> m;
        cin >> a.x >> a.y >> b.x >> b.y;
        cin >> c.x >> c.y >> d.x >> d.y;
        for(int i=0;i<n;i++)
        {
            cin >> t;
            pts.pb(pt(a.x*t+b.x*(1-t), a.y*t+b.y*(1-t)));
        }
        sort(pts.begin(),pts.end());
        for(int i=0;i<m;i++)
        {
            cin >> t;
            pts.pb(pt(c.x*t+d.x*(1-t), c.y*t+d.y*(1-t)));
        }
        sort(pts.end()-m,pts.end());
        printf("%.3lf\n", prim(0));
    }
    return 0;
}

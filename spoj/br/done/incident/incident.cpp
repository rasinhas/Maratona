#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define EPS 1e-6
#define INF 1e9
const double PI = acos(-1);

using namespace std;

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
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
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) < *this && *this < max(p, q); }
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};
typedef pair<pt, pt> segment;
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

bool seg_intersect(pt p, pt q, pt r, pt s) {
    if(r.between(p, q) || s.between(p, q) || p.between(r, s) || q.between(r, s)) return true;
    pt a = line_intersect(p, q, r, s);
    return a.between(p, q) && a.between(r, s);
}

segment seg[55];
vector <pt> pto;
vector <int> adj[555];
double ds[555][555], dm[555];
int tp[555], vis[555];

int main()
{
    int t, m, c;
    while(scanf("%d%d%d",&t, &m, &c) != EOF)
    {
        for(int i=0;i<pto.size();i++) adj[i].clear();
        pto.clear();
        memset(ds,0,sizeof(ds));
        memset(tp,0,sizeof(tp));
        memset(vis,0,sizeof(vis));
        memset(dm,0,sizeof(dm));
        for(int i=0;i<m;i++)
        {
            cin >> seg[i].first.x >> seg[i].first.y >> seg[i].second.x >> seg[i].second.y;
            pto.push_back(seg[i].first);
            pto.push_back(seg[i].second);
        }
        for(int i=0;i<c+2;i++)
        {
            pt a;
            cin >> a.x >> a.y;
            tp[pto.size()] = 1;
            pto.push_back(a);
        }
        tp[pto.size()-1] = tp[pto.size()-2] = 0;
        for(int i=0;i<pto.size();i++) for(int j=i+1;j<pto.size();j++) 
        {
            int f = 0;
            for(int k=0;k<m;k++) if(seg_intersect(pto[i],pto[j],seg[k].first,seg[k].second)) f = 1;
            if(!f)
            {
                ds[i][j] = ds[j][i] = abs(pto[i],pto[j]);
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        priority_queue <pair<double,pair<int,int> > > q;
        q.push(make_pair(0.0,make_pair(pto.size()-2,t)));
        while(!q.empty())
        {
            double d = -q.top().first;
            int u = q.top().second.first;
            int lt = q.top().second.second;
            q.pop();
            if(vis[u]) continue;
            dm[u] = d;
            vis[u] = 1;
            if(vis[pto.size()-1]) break;
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i];
                if(!vis[v])
                {
                    if(tp[u]&tp[v] == 1 && lt > 0) q.push(make_pair(-d,make_pair(v,lt-1)));
                    q.push(make_pair(-(d+ds[u][v]),make_pair(v,lt)));
                }
            }
        }
        printf("%.1lf\n", dm[pto.size()-1]);
    }
    return 0;
}

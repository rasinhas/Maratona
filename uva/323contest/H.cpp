#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

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
    //true se o ponto em questao esta entre os pontos p e q
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    //true se o ponto esta a esquerda do segmento pq
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    //true se o ponto esta a direita do segmento pq
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

//determina o ponto de intersecao entre as retas pq e rs
pt line_intersect(pt p, pt q, pt r, pt s) {
    pt a=q-p, b=s-r, c(p%q, r%s);
    if(cmpD(a % b) == 0) return pt(INF, INF);
    return pt(pt(a.x, b.x) % c , pt(a.y, b.y) % c) / (a % b);
}

//true se os segmentos pq e rs tem intersecao, false cc
bool seg_intersect(pt p, pt q, pt r, pt s) {
    if(r.between(p, q) || s.between(p, q) || p.between(r, s) || q.between(r, s)) return true;
    pt a = line_intersect(p, q, r, s);
    return a.between(p, q) && a.between(r, s);
}

typedef pair<pt,pt> segm;
vector <pt> f, h;
vector <segm> wall;

int solve(pt s)
{
    vector <segm> seg;
    // criando todos os segmentos
    for(int i=0;i<wall.size();i++) seg.push_back(wall[i]);
    for(int i=0;i<h.size();i++)
    {
        if(s < h[i]) seg.push_back(make_pair(s,h[i]));
        else seg.push_back(make_pair(h[i],s));
    }
    priority_queue<pt> events;
    set <segm> T;
}

int main()
{
    int s, k, w;
    pt a, b;
    cin >> s >> k >> w;
    for(int i=0;i<k;i++)
    {
        cin >> a.x >> a.y;
        if(i < s) f.push_back(a);
        else h.push_back(a);
    }
    for(int i=0;i<w;i++)
    {
        cin >> a.x >> a.y >> b.x >> b.y;
        if(a < b) wall.push_back(make_pair(a,b));
        else wall.push_back(make_pair(b,a));
    }
    for(int i=0;i<s;i++)
    {
        cout << solve(f[i]) << endl;
    }
    return 0;
}

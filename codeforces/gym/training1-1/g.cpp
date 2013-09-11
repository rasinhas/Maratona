#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
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
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    bool operator >=(const pt &p)const { return cmp(p) >= 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }

    int prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

vector <pt> tree[11][1111];
vector <pt> ptos;
pair <pt,pt> pl;
pt inf(0,-0x3f3f3f3f);

void split(int l, pair<pt,pt> pl)
{
    for(int i=0;i<(1<<l);i++)
    {
        for(int j=0;j<tree[l][i].size();j++)
        {
            pt pto = tree[l][i][j];
            if(pto.right(pl.first,pl.second) == inf.right(pl.first,pl.second)) tree[l+1][2*i].push_back(pto);
            else tree[l+1][2*i+1].push_back(pto);
        }
    }
}

int main()
{
    int n, p;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int k, z;
        pt a;
        cin >> k;
        cin >> a.x >> a.y;
        ptos.push_back(a);
        for(int j=1;j<k;j++) cin >> z >> z;
    }
    tree[0][0] = ptos;
    cin >> p;
    for(int i=0;i<p;i++)
    {
        cin >> pl.first.x >> pl.first.y >> pl.second.x >> pl.second.y;
        split(i, pl);
    }
    vector <char> sol;
    for(int i=(1<<p)-1;i>=0;i--)
    {
        for(int j=0;j<tree[p][i].size();j++) for(int k=0;k<n;k++) if(tree[p][i][j] == ptos[k]) sol.push_back('A'+k);
        sort(sol.begin(),sol.end());
        for(int i=0;i<sol.size();i++) cout << sol[i];
        sol.clear();
    }
    cout << endl;
    return 0;
}

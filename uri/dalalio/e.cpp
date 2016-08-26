#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<double,int> pii;

int cmpD(int x, int y=0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

struct pt {
    int x, y;
    pt(int x=0, int y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(int c) { return pt(x*c, y*c); }
    pt operator /(int c) { return pt(x/c, y/c); }
    int operator *(pt p) { return x*p.x + y*p.y; }
    int operator %(pt p) { return x*p.y - y*p.x; }
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

double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }

pt b[111], p[111];
vector <pii> a[111];
int n, m;

ll solve(pt u, pt v) {
    int t[111];
    memset(t,0,sizeof(t));
    for(int i=0;i<m;i++) {
        int st;
        double au = angle(b[i],u,u+pt(1,0));
        double av = angle(b[i],v,v+pt(1,0));
        if(b[i].left(u, v)) {
            //if(av < au) av += 2*M_PI;
            st = (lower_bound(a[i].begin(), a[i].end(), mp(au, 0)) - a[i].begin());
            for(int j=st;a[i][j].ff<av;j=(j+1)) t[a[i][j].ss]++;
            //en = (upper_bound(a[i].begin(), a[i].end(), mp(angle(b[i],v,v+pt(1,0)), 0)) - a[i].begin());
        }
        else {
            //if(av > au) au += 2*M_PI;
            st = (lower_bound(a[i].begin(), a[i].end(), mp(av, 0)) - a[i].begin());
            for(int j=st;a[i][j].ff<au;j++) t[a[i][j].ss]++;
            //en = (upper_bound(a[i].begin(), a[i].end(), mp(angle(b[i],u,u+pt(1,0)), 0)) - a[i].begin());
        }
    }
    ll s = 0;
    for(int i=0;i<n;i++) s += (t[i]*t[i]);
    cout << u << " " << v << " " << s << endl;
    return s;
}

// tem algum erro no angle (quero um angulo entre 0 e 2pi)

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i=0;i<n;i++) scanf("%d%d", &p[i].x, &p[i].y);
        for(int i=0;i<m;i++) {
            scanf("%d%d", &b[i].x, &b[i].y);
            for(int j=0;j<n;j++) {
                a[i].push_back(mp(angle(p[j],b[i],p[j]+pt(1,0)),j));
                a[i].push_back(mp(2*M_PI+angle(p[j],b[i],p[j]+pt(1,0)),j));
                //cout << angle(p[j],b[i],p[j]+pt(1,0) << endl;
            }
            sort(a[i].begin(),a[i].end());
        }
        ll s = 0;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
            s += solve(p[i],p[j]);
        }
        cout << s/3 << endl;
    }
    return 0;
}


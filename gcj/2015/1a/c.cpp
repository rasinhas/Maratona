#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define sz size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define var(x) cerr << #x << " = " << x << endl;
#define EPS 1e-6

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long double PI = acos(-1);

int cmpD(long double x, long double y=0, long double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
    long double x, y;
    int i;
    pt(long double x=0, long double y=0, int i=0): x(x), y(y), i(i) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(long double c) { return pt(x*c, y*c); }
    pt operator /(long double c) { return pt(x/c, y/c); }
    long double operator *(pt p) { return x*p.x + y*p.y; }
    long double operator %(pt p) { return x*p.y - y*p.x; }
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

pt pivot;

typedef vector<pt> polygon;
pt pts[3333];
int best[3333];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> pts[i].x >> pts[i].y;
            pts[i].i = i;
        }
        for(int i=0;i<n;i++) best[i] = n-1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                int l = 0, r = 0;
                for(int k=0;k<n;k++) {
                    if(pts[k].right(pts[i],pts[j])) r++;
                    else if(pts[k].left(pts[i],pts[j])) l++;
                }
                best[i] = min(best[i],min(l,r));
            }
        }
        printf("Case #%d:\n", t);
        for(int i=0;i<n;i++) cout << best[i] << endl;
    }
    return 0;
}


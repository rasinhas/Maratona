#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fori(i, n) for(int i=0;i<(n);i++)
#define forr(i, ini, fim) for(int i=ini;i<=(fim);i++)
#define tr(T, i) for (typeof(T.begin()) i=T.begin(); i != T.end(); i++)
#define sz size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x"=" << x << endl)
#define EPS 1e-6
#define INF 1e9
const double PI = acos(-1);

typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

//retorna um angulo entre 0 e 2*PI
double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*PI;
    while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
    return a;
}

//recebe um angulo entre 0 e 360, retorna um angulo entre -PI e PI
double canonic_angle(double a) {
    a = a * PI / 180;
    while(cmpD(a) < -PI) a += 2*PI;
    while(cmpD(a, PI) >= 0) a -= 2*PI;
    return a;
}

//verifica se o angulo b esta entre os angulos a e c
bool between(double a, double b, double c) {
    a = positive_angle(a); b = positive_angle(b); c = positive_angle(c);
    int ret = b <= max(a, c) && b >= min(a, c);
    if(cmpD(fabs(c-a), PI) > 0) return 1 - ret;
    return ret;
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
    //true se o ponto em questao esta entre os pontos p e q
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    //true se o ponto esta a esquerda do segmento pq
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    //true se o ponto esta a direita do segmento pq
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

pt pivot;

typedef vector<pair<pt, pt> > vseg;
typedef vector<pt> polygon;
typedef pair<pt, pt> segment;

//retorna distancia entre dois pontos, se apenas um for passado, considera o outro a origem
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

//retorna o argumento do ponto p
double arg(pt p) { return atan2(p.y, p.x); }

//retorna o valor do menor angulo pqr
double angle(pt p, pt q, pt r) { pt u=p-q, v=r-q; return atan2(u % v, u * v); }

//retorna true se o angulo pqr eh maior que PI e false cc
bool large_angle(pt p, pt q, pt r) { return q.right(p, r); }

//retorna a projecao do ponto a no ponto b
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

//retorna a projecao do ponto p na reta ab
pt project_pt_line(pt p, pt a, pt b) { return a + project(p-a, b-a); }

//normaliza um vetor, retornando false caso ele seja o vetor nulo
bool normalize(pt &p) {
    double r = abs(p);
    if(!cmpD(r)) return false;
    p.x /= r; p.y /= r;
    return true;
}

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

string s[111];
double x1[111], yy[111], x2[111], y2[111];

int main() {
    vector <string> ans;
    double lx, ly, dx, dy;
    int n;
    while(scanf("%d", &n) && n) {
        cin >> lx >> ly;
        cin >> dx >> dy;
        double p1x = lx+1e3*dx, p1y = ly+1e3*dy;
        pt ini=pt(lx,ly), fi=pt(p1x,p1y);
        ans.clear();

        for(int i=0;i<n;i++) cin >> s[i] >> x1[i] >> yy[i] >> x2[i] >> y2[i];

        for(int i=0;i<n;i++) {
            if(seg_intersect(ini,fi,pt(x1[i],yy[i]),pt(x1[i],y2[i])) || seg_intersect(ini,fi,pt(x1[i],yy[i]),pt(x2[i],yy[i])) ||
               seg_intersect(ini,fi,pt(x2[i],y2[i]),pt(x1[i],y2[i])) || seg_intersect(ini,fi,pt(x2[i],y2[i]),pt(x2[i],yy[i]))) 
                ans.push_back(s[i]);
        }
        cout << ans[0];
        for(int i=1;i<ans.size();i++) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}


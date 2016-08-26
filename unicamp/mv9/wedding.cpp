#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

typedef pair<int,int> pii;

const int inf = (int)1e9;
int n;
double a[2];
pii pt[2][11111];

bool check(double l, int idx) {
    // 3 sets -> 2l pra baixo (negativo), 2l pra cima, l pra cima
    set <pii> h2l, l2l, hl, ll;
    // 2 sets auxiliares -> 1 pra 2l e 1 pra l
    set <pii> hax, hx;
    set <pii>::iterator it;
    int yl, yh1, yh2;
    // inserindo altura ymin(0) e ymax
    h2l.insert(pii(0,0));
    h2l.insert(pii(a[1-idx],0));
    hl.insert(pii(0,0));
    hl.insert(pii(a[1-idx],0));
    l2l.insert(pii(0,0));
    l2l.insert(pii(-a[1-idx],0));
    ll.insert(pii(0,0));
    ll.insert(pii(-a[1-idx],0));
    hax.insert(pii(0,0));
    hx.insert(pii(0,0));
    for(int i=0;i<=n;i++) {
        pii c = pt[idx][i];
        if(c.ff + 2*l <= a[idx]) {
            // remoções //
            // remoção no h2l e l2l
            while(1) {
                it = hax.end();
                it--;
                if((*it).ff - c.ff <= 2*l) break;
                //cout <<"###" <<  (*it).ff << " " << (*it).ss << " - " << ((*it).ff - c.ff) << endl;
                h2l.erase(pii((*it).ss,(*it).ff));
                l2l.erase(pii(-(*it).ss,(*it).ff));
                hax.erase(it);
            }
            // remoção no hl
            while(1) {
                it = hx.end();
                it--;
                if((*it).ff - c.ff <= l) break;
                //cout <<"###" <<  (*it).ff << " " << (*it).ss << " - " << ((*it).ff - c.ff) << endl;
                hl.erase(pii((*it).ss,(*it).ff));
                ll.erase(pii(-(*it).ss,(*it).ff));
                hx.erase(it);
            }
            // buscas pto na parte inferior//
            // menor ponto acima em l
            it = hl.upper_bound(pii(c.ss,c.ff));
            yh1 = (*it).ff;
            // menor ponto acima em 2l
            it = h2l.upper_bound(pii(c.ss,c.ff));
            yh2 = (*it).ff;
            // maior ponto abaixo em 2l
            it = l2l.lower_bound(pii(-c.ss,c.ff));
            yl = -(*it).ff;
            if(c.ff - yl <= l && yh1 - yl >= 2*l && yh2 - yl >= l) return 1;
            // buscas pto na parte superior//
            // menor ponto acima em l
            it = hl.upper_bound(pii(c.ss,c.ff));
            yh1 = (*it).ff;
            // maior ponto abaixo em l
            it = ll.lower_bound(pii(-c.ss,c.ff));
            yl = (*it).ff;
            // menor ponto acima de yl em 2l
            it = h2l.upper_bound(pii(yl,c.ff));
            yh2 = (*it).ff;
            if(yh1 - c.ff <= l && yh1 - yl >= 2*l && yh2 - yl >= l) return 1;
        }
        // inserçoes  //
        h2l.insert(pii(c.ss,c.ff));
        hax.insert(c);
        hl.insert(pii(c.ss,c.ff));
        hx.insert(c);
        l2l.insert(pii(-c.ss,c.ff));
    }
    return 0;
}

bool valid(double l) {
    if(check(l,0)) return 1;
    if(check(l,1)) return 1;
    return 0;
}

double solve(int nmi) {
    double lo=0, hi=min(a[0],a[1])/2, mi;
    for(int i=0;i<nmi;i++) {
        mi = (lo+hi)/2;
        if(valid(mi)) lo = mi;
        else hi = mi;
    }
    return 3*lo*lo;
}

int main() {
    while(scanf("%d%lf%lf", &n, &a[0], &a[1]) && n) {
        pt[0][n] = pii(0,0);
        pt[1][n] = pii(0,0);
        for(int i=0;i<n;i++) {
            cin >> pt[0][i].ff >> pt[0][i].ss;
            pt[1][i].ff = pt[0][i].ss;
            pt[1][i].ss = pt[0][i].ff;
        }
        sort(pt[0],pt[0]+n,greater<pii>());
        sort(pt[1],pt[1]+n,greater<pii>());
        //for(double i = 2;i<3;i+=0.05) cout << i << " " << check(i,1) << endl;
        //cout << check(3.0,1) << endl;
        // 31 resolve todos os casos menos o caso 4 (não sei qual o problema no caso 4)
        printf("%.2lf\n", solve(35));
    }
    return 0;
}

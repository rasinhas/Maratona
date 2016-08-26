#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii w[11111];

int mod(int a) { return a > 0 ? a : -a; }

int find(double v, int p) {
    int lo = 0, hi = p;
    while(lo+1 < hi) {
        int mi = (lo+hi)/2;
        if(v > w[mi].ff && v < w[mi].ss) return 1;
        else {
            if(v <= w[mi].ff) hi = mi;
            else lo = mi;
        }
    }
    int mi = (lo+hi)/2;
    if(v > w[mi].ff && v < w[mi].ss) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int p, bx, by;
        cin >> bx >> by;
        cin >> p;
        memset(w,0,sizeof(w));
        for(int i=0;i<p;i++) {
            scanf("%d%d", &w[i].ff, &w[i].ss);
            if(w[i].ff > w[i].ss) swap(w[i].ff,w[i].ss);
        }
        sort(w,w+p);
        int g;
        cin >> g;
        int r = 0;
        for(int i=0;i<g;i++) {
            int ax, ay;
            double y;
            cin >> ax >> ay;
            y = ay + 1.0*(by-ay)*ax/(ax-bx);
            r += find(y,p);
        }
        cout << r << endl;
    }
    return 0;
}


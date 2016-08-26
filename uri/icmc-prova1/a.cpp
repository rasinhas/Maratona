#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct team {
    string name;
    int gp, pts, w, idx;
};

map <string,int> id;
team tt[111];

bool cmp(team a, team b) {
    if(a.pts != b.pts) return a.pts > b.pts;
    else {
        if(a.w != b.w) return a.w > b.w;
        else {
            if(a.gp != b.gp) return a.gp > b.gp;
            else return a.idx < b.idx;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        id.clear();
        for(int i=0;i<n;i++) {
            cin >> tt[i].name;
            tt[i].gp = tt[i].pts = tt[i].w = 0;
            tt[i].idx = i;
            id[tt[i].name] = i;
        }
        for(int i=0;i<m;i++) {
            int a, b, ia, ib;
            string na, nb;
            cin >> a >> na >> b >> nb;
            ia = id[na];
            ib = id[nb];
            tt[ia].gp += a;
            tt[ib].gp += b;
            if(a > b) {
                tt[ia].pts += 3;
                tt[ia].w += 1;
            }
            if(a < b) {
                tt[ib].pts += 3;
                tt[ib].w += 1;
            }
            if(a == b) {
                tt[ia].pts += 1;
                tt[ib].pts += 1;
            }
        }
        sort(tt,tt+n,cmp);
        for(int i=0;i<n;i++) cout << tt[i].name << endl;
    }
    return 0;
}


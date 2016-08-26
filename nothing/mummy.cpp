#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii m[111111];
int n;

int check(int t) {
    set <pii> up, down;
    up.clear();
    down.clear();
    vector <pii> ev;
    for(int i=1;i<=n;i++) {
        ev.push_back(mp(m[i].ff-t-1,-i));
        ev.push_back(mp(m[i].ff+t,i));
    }
    sort(ev.begin(),ev.end());
    bool c = 0;
    for(int i=0;i<ev.size();i++) {
        if(ev[i].ss == 1) return 0;
        if(ev[i].ss == -1) c++;
        else {
            if(ev[i].ss < 0) {
                if(m[-ev[i].ss].ss >= 0) up.insert(mp(m[-ev[i].ss].ss,-ev[i].ss));
                if(m[-ev[i].ss].ss <= 0) down.insert(mp(m[-ev[i].ss].ss,-ev[i].ss));
            } else {
                if(m[ev[i].ss].ss >= 0) up.erase(mp(m[ev[i].ss].ss,ev[i].ss));
                if(m[ev[i].ss].ss <= 0) down.erase(mp(m[ev[i].ss].ss,ev[i].ss));
            }
        }
        if(c) {
            set<pii>::iterator it;
            if(up.size() == 0) return 1;
            int uc = (*up.begin()).ff;
            if(down.size() == 0) return 1;
            int dc = (*down.rbegin()).ff;
            if(uc - t > dc + t + 1) return 1;
        }
    }
}

int main() {
    int t=1;
    while(scanf("%d", &n) && n != -1) {
        n++;
        for(int i=2;i<=n;i++) scanf("%d %d", &m[i].ff, &m[i].ss);
        m[1] = pii(0,0);
        int lo = 1, hi = 1e7+1, mi;
        while(lo+1 < hi) {
            mi = (lo+hi)/2;
            if(check(mi)) lo = mi;
            else hi = mi;
        }
        printf("Case %d: ", t++);
        if(hi == 1e7+1) printf("never\n");
        else printf("%d\n", lo+1);
    }
    return 0;
}


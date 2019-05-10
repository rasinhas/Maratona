#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

vector<pair<int, int> > h, v;

int solve(vector <pair<int,int> > a) {
    sort(a.begin(),a.end());
    int best = 0, s = 0, ms = 0;
    for(int i=0;i<a.size();i++) if(a[i].ss == -1) s++;
    for(int i=0;i<a.size();i++) {
        s += a[i].ss;
        if(s > ms) {
            ms = s;
            best = a[i].ff;
        }
    }
    return best;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, q;
        cin >> n >> q;
        v.clear();
        h.clear();
        v.push_back(mp(0,0));
        v.push_back(mp(q,0));
        h.push_back(mp(0,0));
        h.push_back(mp(q,0));
        for(int i=0;i<n;i++) {
            int x, y;
            char c;
            cin >> x >> y >> c;
            if(c == 'N' || c == 'S') {
                int d = c == 'N' ? 1 : -1;
                v.push_back(mp(y+(c=='N'),d));
            } else {
                int d = c == 'E' ? 1 : -1;
                h.push_back(mp(x+(c=='E'),d));
            }
        }
        printf("Case #%d: %d %d\n", t, solve(h), solve(v));
    }
    return 0;
}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<double,double> pii;

vector <pii> b, b1, b2;

int main() {
    int n, w, u, v, t1, t2;
    cin >> n >> w >> u >> v >> t1 >> t2;
    for(int i=0;i<n;i++) {
        char c;
        int m, x;
        scanf(" %c %d", &c, &m);
        for(int j=0;j<m;j++) {
            int l, p;
            scanf("%d %d", &l, &p);
            double st, en;
            if(c == 'W') {
                if(p+l < 0) continue;
                if(p <= 0) st = 0;
                else st = (1.0*p)/u;
                en = (1.0*p+l)/u;
            } else {
                if(p-l > 0) continue;
                if(p >= 0) st = 0;
                else st = -(1.0*p)/u;
                en = (-(1.0*p)+l)/u;
            }
            st -= (i+1.0)*(1.0*w)/v;
            en -= i*(1.0*w)/v;
            if(st < 0) st = 0.0;
            if(en < st) en = st;
            b.push_back(mp(st,en));
        }
    }
    //for(int i=0;i<b.size();i++) cout << "$" << b[i].ff << " " << b[i].ss << endl;
    sort(b.begin(),b.end());
    b1.push_back(mp(t1,t1));
    for(int i=0;i<b.size();i++) {
        int st, en;
        if(b[i].ff >= t2) continue;
        else if(b[i].ff >= t1 && b[i].ff <= t2) st = b[i].ff;
        else st = t1;
        if(b[i].ss < t1) continue;
        else if(b[i].ss >= t1 && b[i].ss <= t2) en = b[i].ss;
        else en = t2;
        b1.push_back(mp(st,en));
    }
    b1.push_back(mp(t2,t2));
    //for(int i=0;i<b1.size();i++) cout << "#" << b1[i].ff << " " << b1[i].ss << endl;
    sort(b1.begin(),b1.end());
    int st=b[0].ff, en=b[0].ss;
    for(int i=1;i<b1.size();i++) {
        if(b1[i].ff <= en && b1[i].ss > en) en = b1[i].ss;
        else {
            b2.push_back(mp(st,en));
            st = b1[i].ff;
            en = b1[i].ss;
        }
    }
    b2.push_back(mp(st,en));
    //for(int i=0;i<b2.size();i++) cout << "@" << b2[i].ff << " " << b2[i].ss << endl;
    double best = 0.0;
    for(int i=1;i<b2.size();i++) best = max(best,b2[i].ff-b2[i-1].ss);    
    printf("%.9lf\n", best);
    return 0;
} 

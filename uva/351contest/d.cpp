#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef pair<int,int> pii;

map <string,int> id;
map <int,string> var;
double m[333][333], sol[333], val[333];
double mod(double a) { return a > 0 ? a : -a; }

int main() {
    int l, c;
    while(scanf("%d%d", &l, &c) != EOF) {
        int vc = 0;
        memset(m,0,sizeof(m));
        memset(sol,0,sizeof(sol));
        memset(val,0,sizeof(val));
        id.clear();
        var.clear();
        for(int i=0;i<l;i++) {
            for(int j=0;j<c;j++) {
                string v;
                cin >> v;
                if(!id.count(v)) {
                    id[v] = vc++;
                    var[id[v]] = v;
                }
                m[i][id[v]]++;
                m[l+j][id[v]]++;
            }
            scanf("%lf", &sol[i]);
        }
        for(int i=0;i<c;i++) scanf("%lf", &sol[l+i]);
        for(int i=0;i<vc;i++) {
            double mv = 0;
            int mvi = 0;
            for(int j=i;j<l+c;j++) {
                if(mod(m[j][i]) > mod(mv)) {
                    mv = m[j][i];
                    mvi = j;
                }
            }
            for(int j=0;j<vc;j++) swap(m[i][j],m[mvi][j]);
            swap(sol[i],sol[mvi]);
            for(int j=0;j<vc;j++) if(j != i) m[i][j] /= m[i][i];
            sol[i] /= m[i][i];
            m[i][i] = 1;
            for(int j=i+1;j<l+c;j++) {
                if(m[j][i] != 0) {
                    double a = m[j][i];
                    for(int k=i;k<vc;k++) {
                        m[j][k] -=  m[i][k]*a;
                    }
                    sol[j] -= a*sol[i];
                }
            }
        }
        for(int i=vc-1;i>=0;i--) {
            double r = sol[i];
            for(int j=vc-1;j>i;j--) r -= m[i][j]*val[j];
            val[i] = r;
        }
        map<string,int>::iterator it;
        for(it=id.begin();it!=id.end();it++) {
            cout << (it)->ff << " " << val[(it)->ss] << endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii p[2222];
map <int,int> d2;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, r = 0;
        cin >> n;
        for(int i=0;i<n;i++) cin >> p[i].ff >> p[i].ss;
        for(int i=0;i<n;i++) {
            d2.clear();
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                int k = (p[i].ff-p[j].ff)*(p[i].ff-p[j].ff) + (p[i].ss-p[j].ss)*(p[i].ss-p[j].ss);
                assert(k != 0);
                if(!d2.count(k)) d2[k] = 1;
                else d2[k]++;
            }
            for(map<int,int>::iterator it=d2.begin(); it!=d2.end();it++) r += (((*it).ss)*((*it).ss-1))/2;
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}

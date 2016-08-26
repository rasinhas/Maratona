#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[1111];
int sols[1111], mm, m, n;
int memo[(1<<10)+1];

int calc_nodes(int msk) {
    set <string> pref;
    for(int i=0;i<n;i++) {
        if((1<<i)&msk) {
            for(int j=0;j<=s[i].size();j++) pref.insert(s[i].substr(0,j));
        }
    }
    return memo[msk] = pref.size();
}

void go(int msk, int serv, int nodes) {
    int lef = n-__builtin_popcount(msk);
    if(lef == 0) return;
    if(serv == m) {
        int k = 0;
        for(int j=0;j<n;j++) if(((1<<j)&msk) == 0) k |= (1<<j);
        nodes += memo[k];
        mm = max(mm,nodes);
        sols[nodes]++;
        return;
    }
    for(int i=1;i<(1<<lef);i++) {
        int nmsk = 0;
        int p = 0;
        for(int j=0;j<n;j++) {
            if(((1<<j)&msk) == 0) {
                if((1<<p)&i) nmsk |= (1<<j);
                p++;
            }
        }
        go(msk|nmsk,serv+1,nodes+memo[nmsk]);
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> s[i];
        memset(sols,0,sizeof(sols));
        mm = 0;
        for(int i=1;i<(1<<n);i++) calc_nodes(i);
        if(m == 1) {
            mm = memo[(1<<n)-1];
            sols[mm]++;
        }
        else {
            for(int i=1;i<(1<<n);i++) go(i,2,memo[i]);
        }
        printf("Case #%d: %d %d\n", t, mm, sols[mm]);
    }
    return 0;
}


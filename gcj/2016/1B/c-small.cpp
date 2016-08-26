#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

map <string, int> f, s, x, y;
string a[33], b[33];
int best = 0;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        printf("Case #%d: ", t);
        int n;
        best = 0;
        cin >> n;
        f.clear();
        s.clear();
        for(int i=0;i<n;i++) {
            cin >> a[i] >> b[i];
            if(!f.count(a[i])) f[a[i]] = 1;
            else f[a[i]]++;
            if(!s.count(b[i])) s[b[i]] = 1;
            else s[b[i]]++;
        }
        for(int i=0;i<(1<<n);i++) {
            int ok = 1;
            x = f, y = s;
            for(int j=0;j<n;j++) {
                if((1<<j)&i) {
                   if(x[a[j]] == 1) ok = 0; 
                   else x[a[j]]--;
                   if(y[b[j]] == 1) ok = 0; 
                   else y[b[j]]--;
                }
                if(!ok) break;
            }
            if(ok) best = max(best,__builtin_popcount(i));
        }
        cout << best << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int m[1111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, r1=0, r2=0, r=0;
        cin >> n;
        for(int i=0;i<n;i++) cin >> m[i];
        for(int i=1;i<n;i++) {
            if(m[i] < m[i-1]) {
                r1 += (m[i-1]-m[i]);
                r = max(r,(m[i-1]-m[i]));
            }
        }
        int c = m[0];
        for(int i=1;i<n;i++) {
            r2 += min(r,c);
            c -= min(r,c);
            c = max(m[i],c);
        }
        printf("Case #%d: %d %d\n", t, r1, r2);
    }
    return 0;
}


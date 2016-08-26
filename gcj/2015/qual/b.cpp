#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[1111];

int main() {
    int T, d;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> d;
        for(int i=0;i<d;i++) cin >> p[i];
        sort(p,p+d,greater<int>());
        int m = p[0], best = m;
        for(int i=m;i>0;i--) {
            int cuts = 0;
            for(int j=0;j<d;j++) if(p[j] > i) cuts += (((p[j]+i-1)/i)-1);
            best = min(best,i+cuts);
        }
        printf("Case #%d: %d\n", t, best);
    }
    return 0;
}


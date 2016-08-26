#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int r, c, w;
        cin >> r >> c >> w;
        int ans = r*((c/w))-1;
        ans += w;
        if(c%w) ans++;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}


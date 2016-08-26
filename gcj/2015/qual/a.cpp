#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T, n;
    string s;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        cin >> s;
        int cur = 0;
        int r = 0;
        for(int i=0;i<s.size();i++) {
            if(cur < i) {
                r += (i-cur);
                cur = i;
            }
            cur += (s[i]-'0');
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int mod(int a) { return a > 0 ? a : -a; }

int main() {
    int n, p, r = 0;
    string s;
    cin >> n >> p;
    cin >> s;
    int f = 1e9, l = 0, ch = 0;
    for(int i=0;2*i<n;i++) {
        ch = min(mod(s[i]-s[n-i-1]),mod(26-mod((s[i]-s[n-i-1]))));
        r += ch;
        if(ch) {
            f = min(i,f);
            l = max(i,l);
        }
    }
    if(r == 0) cout << 0 << endl;
    else {
        p--;
        if(2*p >= n) p = n-p-1;
        cout << r + min(mod(l-p)+l-f, l-f+mod(p-f)) << endl;
    }
    return 0;
}


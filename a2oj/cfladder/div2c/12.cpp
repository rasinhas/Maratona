#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int pref[1111111];
ll f[1111111];

int main() {
    string s;
    ll a, b;
    int ok = 0;
    cin >> s;
    cin >> a >> b;
    ll cur = s[0]-'0';
    int n = s.size();
    for(int i=1;i<n;i++) {
        if(cur >= a) cur %= a;
        if(cur == 0 && s[i] != '0') pref[i] = 1;
        cur *= 10;
        cur += s[i]-'0';
    }
    f[0] = 1%b;
    for(int i=1;i<n;i++) f[i] = f[i-1]*10 % b;
    cur = s[n-1]-'0';
    for(int i=n-2;i>=0;i--) {
        if(cur >= b) cur %= b;
        if(cur == 0 && pref[i+1]) ok = i+1;
        cur = (cur+(s[i]-'0')*f[n-i-1]);
    }
    if(!ok) cout << "NO" << endl;
    else cout << "YES" << endl << s.substr(0,ok) << endl << s.substr(ok,n-ok) << endl;
    return 0;
}

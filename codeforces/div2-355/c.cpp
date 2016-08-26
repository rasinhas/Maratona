#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[111111][66];
ll z[64];
const ll m = 1e9+7;

int v(char c) {
    if(c >= '0' && c <= '9') return c-'0';
    else if(c >= 'A' && c <= 'Z') return 10+(c-'A');
    else if(c >= 'a' && c <= 'z') return 36+(c-'a');
    else if(c == '-') return 62;
    return 63;
}

int main() {
    string s;
    cin >> s;
    /*
    for(int i=1;i<s.size();i++) r &= v(s[i]);
    for(int i=0;i<64;i++) dp[1][i] = 1;
    for(int i=1;i<2*s.size();i++) {
        for(int j=0;j<64;j++) {
            for(int k=0;k<64;k++) dp[i+1][j&k] = (dp[i+1][j&k]+dp[i][j])%m;
        }
    }
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) {
        if(i&j == r) z = (z+(dp[s.size()][i]*dp[s.size()][j])%m)%m;
    }
    */
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) z[i&j]++;
    ll r = 1;
    for(int i=0;i<s.size();i++) {
        r = (r*z[v(s[i])])%m;
    }
    cout << r << endl;;
    return 0;
}


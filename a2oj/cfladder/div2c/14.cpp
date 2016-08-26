#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mod = 1e9+7;
string s[111];
int w[111], vis[111][26];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(!vis[i][s[j][i]-'A']) {
        w[i]++;
        vis[i][s[j][i]-'A'] = 1;
    }
    ll r = 1;
    for(int i=0;i<m;i++) r = (r*w[i])%mod;
    cout << r << endl;
    return 0;
}


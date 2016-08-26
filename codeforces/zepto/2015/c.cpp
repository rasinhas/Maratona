#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    ll r = 0;
    ll n = (c/wr);
    for(int i=n;i>=max(0ll,n-1000000);i--) {
        ll s = c - i*wr;
        r = max(r,i*hr + hb*(s/wb));
    }
    ll n = (c/wb);
    for(int i=n;i>=max(0ll,n-1000000);i--) {
        ll s = c - i*wb;
        r = max(r,i*hb + hr*(s/wr));
    }
    cout << r << endl;
    return 0;
}


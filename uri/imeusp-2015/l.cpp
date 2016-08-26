#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, r=1ll;
        cin >> a >> b;
        if(a+b == 0) r = 0;
        for(int i=0;i<a;i++) r *= 26;
        for(int i=0;i<b;i++) r *= 10;
        cout << r << endl;
    }
    return 0;
}


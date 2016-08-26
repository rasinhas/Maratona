#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll a[2222], l[2222], l2[2222];

ll mod(ll a) { return a > 0 ? a : -a; }

int main() {
    int n;
    cin >> n;
    for(int i=2;i<(1<<(n+1));i++) cin >> a[i];
    l[1] = 0;
    int r = 0;
    for(int i=(1<<n)-1;i>0;i--) {
        ll left = l[2*i]+a[2*i], right = l[2*i+1]+a[2*i+1];
        r += mod(right-left);
        l[i] = max(right,left);
    }
    cout << r << endl;
    return 0;
}


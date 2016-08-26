#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, k, h, a, c = 0;
    ll t = 0;
    cin >> n >> h >> k;
    for(int i=0;i<n;i++) {
        cin >> a;
        if(c+a <= h) {
            c = c+a;
        } else {
            int tz = (min(c,c+a-h)+k-1)/k;
            t += tz; 
            c = max(0,c-tz*k);
            c += a;
        }
    }
    if(c) t += (c+k-1)/k;
    cout << t << endl;
    return 0;
}


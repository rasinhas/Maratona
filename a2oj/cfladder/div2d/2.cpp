#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll p[111], c[11], t[11];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<5;i++) cin >> c[i];
    ll cur = 0;
    for(int i=0;i<n;i++) {
        cur += p[i];
        for(int j=4;j>=0;j--) {
            t[j] += cur/c[j];
            cur %= c[j];
        }
    }
    for(int i=0;i<5;i++) cout << t[i] << " ";
    cout << endl << cur << endl;
    return 0;
}


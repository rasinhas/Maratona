#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k, m;
        cin >> n >> k >> m;
        ll v = n;
        for(int i=1;;i++) {
            ll nv = v*k;
            if(nv > m || nv/k != v) {
                cout << i-1 << endl;
                break;
            }
            v = nv;
        }
    }
    return 0;
}

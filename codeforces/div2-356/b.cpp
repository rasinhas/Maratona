#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int v[11111];

int main() {
    int n, a, r = 0;
    cin >> n >> a;
    a -= 1;
    for(int i=0;i<n;i++) cin >> v[i];
    if(v[a] == 1) r++;
    for(int i=1;;i++) {
        if(a+i >= n && a-i < 0) break;
        if(a+i >= n && v[a-i] == 1) r++;
        if(a-i < 0 && v[a+i] == 1) r++;
        if(a-i >= 0 && a+i < n && v[a+i]+v[a-i] == 2) r += 2;
    }
    cout << r << endl;
    return 0;
}


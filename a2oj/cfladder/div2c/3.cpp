#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void solve(int n, int m, int l) {
    if(n == m && m == 0) return;
    if(n > m+1 || m > 2*n + 2) {
        cout << -1 << endl;
        return ;
    }
    if(n > m) {
        cout << 0;
        solve(n-1,m,0);
    }
    else if(m > 2*n && m > 1) {
        cout << 11;
        solve(n,m-2,1);
    }
    else {
        if(l == -1) l = 0;
        cout << 1-l;
        solve(n-l,m-(1-l),1-l);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    solve(n,m,-1);
    cout << endl;
    return 0;
}


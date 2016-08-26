#include <bits/stdc++.h>

using namespace std;

long long r[1111111];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) {
        cin >> r[i];
        r[i] *= r[i];
    }
    sort(r,r+n);
    long long ret = 0;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        long long d = 1ll*x*x + 1ll*y*y;
        ret += (n-(lower_bound(r,r+n,d)-r));
    }
    cout << ret << endl;
    return 0;
}

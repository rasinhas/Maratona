#include <bits/stdc++.h>

using namespace std;

long long a[1111111];
int n;

long long solve(int idx) {
    long long cur = 0, r = 0;
    for(int i=0;i<n;i++) {
        cur += (i%2 == idx ? a[i] : -a[i]);
        if(cur < 0) cur = 0;
        r = max(cur,r);
    }
    return r;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) scanf("%lld", &a[i]);
    cout << max(solve(0),solve(1)) << endl;
    return 0;
}

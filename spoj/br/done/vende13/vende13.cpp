#include <bits/stdc++.h>

using namespace std;

int a[111111];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int m = 1e9;
    for(int i=0;i<=k;i++) m = min(m,a[n+i-k-1]-a[i]);
    cout << m << endl;
    return 0;
}

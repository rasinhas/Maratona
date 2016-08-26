#include <bits/stdc++.h>

using namespace std;

int l[111111];

int main() {
    int n, i;
    long long s = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> l[i];
        s += l[i];
    }
    sort(l,l+n,greater<int>());
    for(i=0;i<n;i++) {
        s -= l[i];
        if(l[i] < s) break;
    }
    i = n-i;
    if(i < 3) cout << 0 << endl;
    else cout << i << endl;
    return 0;
}

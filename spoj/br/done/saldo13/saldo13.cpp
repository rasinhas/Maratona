#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s, c, r;
    cin >> n >> s;
    r = s;
    for(int i=0;i<n;i++) {
        cin >> c;
        s += c;
        r = min(r,s);
    }
    cout << r << endl;
    return 0;
}

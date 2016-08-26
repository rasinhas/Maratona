#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f;

char solve() {
    if(a >= e && c >= e && b+d >= f) return 'S';
    if(a >= e && d >= e && b+c >= f) return 'S';
    if(b >= e && c >= e && a+d >= f) return 'S';
    if(b >= e && d >= e && a+c >= f) return 'S';
    if(a >= f && c >= f && b+d >= e) return 'S';
    if(a >= f && d >= f && b+c >= e) return 'S';
    if(b >= f && c >= f && a+d >= e) return 'S';
    if(b >= f && d >= f && a+c >= e) return 'S';
    if(a >= f && b >= e) return 'S';
    if(b >= f && a >= e) return 'S';
    if(c >= f && d >= e) return 'S';
    if(d >= f && c >= e) return 'S';
    return 'N';
}

int main() {
    cin >> a >> b >> c >> d >> e >> f;
    cout << solve() << endl;
    return 0;
}

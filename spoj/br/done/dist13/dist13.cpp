#include <bits/stdc++.h>

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << mod(a-c)+mod(b-d) << endl;
    return 0;
}

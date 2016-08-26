#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int g = __gcd(b,d);
    a = (a*d)/g;
    c = (c*b)/g;
    a = a+c;
    b = b*d/g;
    g = __gcd(a,b);
    cout << a/g << " " << b/g << endl; 
    return 0;
}

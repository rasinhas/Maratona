#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int main()
{
    long long n, m, x, y, a, b;
    long long limw, liml, l, w, d;
    long long x1, x2, y1, y2;
    cin >> n >> m >> x >> y >> a >> b;
    d = gcd(a,b);
    a /= d;
    b /= d;
    limw = n/a*b;
    liml = m/b*a;
    if(limw > m)
    {
        l = liml;
        w = liml/a*b;
    }
    else
    {
        w = limw;
        l = limw/b*a;
    }
    x2 = x+l/2;
    x1 = x2-l;
    if(x2 > n) x2 = n, x1 = n-l;
    else if(x1 < 0) x1 = 0, x2 = l;
    y2 = y+w/2;
    y1 = y2-w;
    if(y2 > m) y2 = m, y1 = m-w;
    else if(y1 < 0) y1 = 0, y2 = w;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}

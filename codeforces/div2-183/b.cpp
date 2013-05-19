#include <iostream>
#include <cstdio>

using namespace std;

int f[13] = {-1, 306, 337, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275};

int day0(int y, int m, int d)
{
    int a, b, c, r;
    if(m <= 2) --y;
    a = y/4;
    b = y/100;
    c = y/400;
    r = d + f[m] + y*365 + a - b + c;
    return r;
}

int mod(int a) {return a > 0 ? a : -a; }

int main()
{
    int y1, d1, m1, y2, m2, d2;
    scanf("%d:%d:%d", &y1, &m1, &d1);
    scanf("%d:%d:%d", &y2, &m2, &d2);
    cout << mod(day0(y2,m2,d2)-day0(y1,m1,d1)) << endl;
    return 0;
}

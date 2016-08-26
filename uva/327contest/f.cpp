#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        double x, y, r;
        cin >> x >> y >> r;
        double d = hypot(x,y);
        printf("%.2lf %.2lf\n", r-d, r+d);
    }
    return 0;
}

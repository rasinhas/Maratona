#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi=acos(-1);

float rad(int d) { return d*pi/180.0; }

int main()
{
    int n, x;
    double t, v, a, p;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %d", &t, &x);
        t *= 100.0;
        v = t*tan(rad(x));
        a = floor(v/105.0);
        p = v - 105.0*a;
        if(p <= 16.0/cos(rad(x)) || p >= 105.0-(16.0/cos(rad(x)))) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double m, r;
    double ret=0;
    double s2 = sqrt(2);
    scanf("%lf %lf", &m, &r);
    for(int i=1;i<=m;i++)
    {
        double v = 2*r;
        if(m > 1)
        {
            if(i > 1 && i < m) v += 2*(2*r + r*s2);
            else v += 2*r + r*s2;
        }
        if(m > 2)
        {
            if(i > 1 && i < m) v += 2*(m-3)*r*s2;
            else v += 2*(m-2)*r*s2;
        }
        if(i > 2) v += r*(i-1)*(i-2);
        if(i < m-1) v += r*((m-i))*(m-i-1);
        ret += v;
    }
    ret /= (m*m);
    printf("%.10lf", ret);
    return 0;
}

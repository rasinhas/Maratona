#include <stdio.h>
#include <math.h>
#define EPS 1e-5

using namespace std;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

int main()
{
    int t;
    double val, arc, aux, a, b;
    double pi = acos(-1);
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%lf %lf", &a, &b);
        val = sqrt(a*a+b*b);
        // gama = acos(a/val) = asin(b/val)
        // theta + gama = pi/2
        arc = atan2(a,b);
        if(cmpD(arc) < 0) arc += 2*pi;
        printf("%.2lf %.2lf\n", arc, val);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int t;
    double l, tot, red;
    double pi = acos(-1);
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%lf", &l);
        tot = l * l * 0.6;
        red = l * l * 0.04 * pi;
        printf("%.2lf %.2lf\n", red, tot-red);
    }
    return 0;
}

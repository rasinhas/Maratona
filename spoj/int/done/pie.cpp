#include <iostream>
#include <stdio.h>
#include <cmath>
#define eps 1e-6

using namespace std;

int n;
double m;
double v[11000];
const double pi=acos(-1);

int pieces(double size)
{
    int p=0;
    for(int i=0;i<n;i++) p = p + floor(v[i]/size);
    return p;
}

double bs(int f)
{
    double hi=m , lo=0.0, mid, ret;
    mid = (lo+hi)/2;
    while(mid - lo > eps)
    {
        //printf("@%lf -- %d\n", mid, pieces(mid));
        if(pieces(mid) >= f)
        {
            lo = mid;
            ret = mid;
        }
        else hi = mid;
        mid = (hi+lo)/2;
    }
    return ret;
}

int main()
{
    int t, f;
    double p;
    scanf("%d", &t);
    while(t--)
    {
        m = 0;
        scanf("%d%d", &n, &f);
        f++;
        for(int i=0;i<n;i++)
        {
            scanf("%lf", &p);
            v[i] = pi*p*p;
            m = max(m,v[i]);
        }
        //for(int i=0;i<n;i++) printf("%f ", v[i]);
        //printf("\n");
        printf("%.4lf\n", bs(f));
    }
    return 0;
}

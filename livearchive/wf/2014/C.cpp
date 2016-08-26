#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int i, n;
    ll x[111], y[111], xmin=1e18, xmax=-1e18;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
        if(!y[i]) xmin=min(xmin, x[i]);
        if(!y[i]) xmax=max(xmax, x[i]);
    }
    double a=0, cx=0;
    for(i=0; i<n; i++) {
        a+=(x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n]);
        cx+=(x[i]+x[(i+1)%n])/3.0 * (x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n]);
    }
    cx /= a;
    a=fabs(a)/2;
    if(cx>xmax || cx<xmin) 
    {
        if(cx>xmax && x[0]>=xmax) printf("unstable\n");
        else if(cx<xmin && x[0]<=xmin) printf("unstable\n");
        else
        {
            if(x[0]>=xmin && x[0]<=xmax)
            {
                double t;
                if(cx>xmax)
                {
                    t=(a*fabs(xmax-cx)/(fabs(x[0]-xmax)));
                }
                else
                {
                    t=(a*fabs(xmin-cx)/(fabs(x[0]-xmin)));

                }
                printf("%.0lf .. inf\n", floor(t));
            }
            else
            {
                double t1, t2;
                t1=(a*fabs(xmax-cx)/(fabs(x[0]-xmax)));
                t2=(a*fabs(xmin-cx)/(fabs(x[0]-xmin)));
                if(t1>t2) swap(t1, t2);
                printf("%.0lf .. %.0lf\n", floor(t1), ceil(t2));
            }
        }
    }
    else
    {
        if(x[0]>=xmin && x[0]<=xmax) printf("0 .. inf\n");
        else
        {
            if(x[0]>=xmin) printf("0 .. %.0lf\n", ceil(a*fabs(xmax-cx)/(fabs(x[0]-xmax))));
            else printf("0 .. %.0lf\n", ceil(a*fabs(cx-xmin)/(fabs(x[0]-xmin))));
        }
    }
    return 0;
}

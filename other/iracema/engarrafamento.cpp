#include <iostream>
#include <cstdio>
#define maxv 10
#define minv 0

using namespace std;

int main()
{
    int n;
    double t, d, vi, vf, a, b, lb;
    while(cin >> n && n)
    {
        lb = 0.0;
        vi = 0.0;
        vf = 0.0;
        d = 0,0;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            //desaceleracao
            vi = ((vf-2*(a-lb)) > minv) ? (vf-2*(a-lb)) : (minv);
            if(vi == 0)
            {
                t = (vf)/2;
                d += (vf*t - t*t); 
            }
            else
            {
                t = (a-lb);
                d += (vf*(t) - t*t);
            }
            lb = b;
            //aceleracao
            vf = ((vi+(b-a)) < maxv) ? (vi+(b-a)) : (maxv);
            if(vf == maxv)
            {
                t = (vf-vi);
                d += (vi*t + (t*t)/2);
                t = (b-a)-t;
                d += vf*t;
            }
            else
            {
                t = (b-a);
                d += (vi*t + (t*t)/2);
            }
        }
        printf("%.2lf\n", d);
    }
    return 0;
}

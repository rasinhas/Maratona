#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
double ox, oy;
double best;
const double pi=acos(-1);
const double c=cos(-pi/4) ,s=sin(-pi/4);

void go(double x, double y, double dx, double dy, int d, int p)
{
    if(d > 7) return;
    if(p > n) return;
    best = min(best, hypot(x-ox,y-oy));
    go(x+dx,y+dy,dx,dy,d,p+1);
    double ndx = dx*c-dy*s;
    double ndy = dx*s+dy*c;
    go(x,y,ndx,ndy,d+1,p+1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> ox >> oy;
        best = 1e9;
        go(0.0,0.0,10.0,0.0,0,0);
        printf("%.6lf\n", best);
    }
    return 0;
}

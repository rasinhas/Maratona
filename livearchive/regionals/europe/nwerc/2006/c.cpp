#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-4

using namespace std;

double v[11111];
int n, f, t;

bool valid(double m)
{
    int k=0;
    for(int i=0;i<n;i++) k += (v[i]/m);
    if(k > f) return 1;
    return 0;
}

int main()
{
    int p;
    cin >> t;
    while(t--)
    {
        cin >> n >> f;
        double pi=acos(-1);
        double mv=0.0;
        for(int i=0;i<n;i++)
        {
            cin >> p;
            v[i] = p*p*pi;
            mv = max(mv,v[i]);
        }
        double h=mv;
        double l=0.0;
        double m;
        while(1)
        {
            m = (l+h)/2;
            if(valid(m))
            {
                if(!valid(m+eps)) break;
                else l = m+eps; 
            }
            else
            {
                if(valid(m-eps)) break;
                else h = m-eps;
            }
        }
        printf("%.4lf\n", m);
    }
    return 0;
}

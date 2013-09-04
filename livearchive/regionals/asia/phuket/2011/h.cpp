#include <iostream>
#include <cstdio>
#include <cmath>
#define EPS 1e-8

using namespace std;

typedef long long ll;
const double pi = acos(-1);

int main()
{
    ll r, R, d, D;
    double s;
    while((cin >> r >> R >> d >> D >> s) && r)
    {
        ll ret=0;
        for(int i=r;i<=R;i++)
        {
            for(int j=d;j<=D;j++)
            {
                ll t = 2*(i+j);
                double u = t-pi*i*i/t;
                ll v = (s-t)/u;
                ret += 2*(v+1);
            }
        }
        cout << ret << endl;
    }
    return 0;
}

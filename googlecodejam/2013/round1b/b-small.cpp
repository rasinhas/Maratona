#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define EPS 1e-6

using namespace std;

int mod(int a) { return a>0 ? a : -a; }
int countAll(int l) { return l + 2*l*(l-1); }
int count(int l) { return l == 0 ? 0 : 4*(l-1) + 1; }
long long cmb[300][300];

void calc_pascal(int n) 
{
    memset(cmb, 0, sizeof(cmb));
    for(int i=0;i<n;++i)
    {
        cmb[i][0] = cmb[i][i] = 1;
        for(int j=1;j<i;j++) cmb[i][j] = cmb[i-1][j-1] + cmb[i-1][j];
    }
}

double exp[300]; // 0.5^n

int main()
{
    int t, x, y, c, n;
    int mh, l;
    double ret, p;
    cin >> t;
    p = 0.5;
    calc_pascal(300);
    exp[0] = 1;
    for(int i=1;i<300;i++) exp[i] = exp[i-1]*p;
    for(int i=0;i<t;i++)
    {
        cin >> n >> x >> y;
        l = ((mod(x) + mod(y))/2)+1;
        c = n - countAll(l-1);
        ret = 0.0;
        if(c < 0) ret = 0;
        else if(c >= count(l)) ret = 1;
        else
        {
            mh = 2*(l-1);
            if(y >= mh) ret = 0;
            else 
            {
                if(n < y) ret = 0;
                else
                {
                    for(int j=0;j<=c;j++) if((c-mh) >= y+1 || j >= y+1) ret += exp[c]*cmb[c][j];
                }
            }
        }
        printf("Case #%d: %.7lf\n", i+1, ret);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int M=1000000;
int a, s, d;
double r, dv[2222222], av[2222222], sv[2222222], pv[2222222];

void solve()
{
    dv[1] = 0.5; av[1] = 0.5; sv[1] = 2, pv[1] = 1;
    for(int i=1;i<M;i++)
    {
        dv[2*i] += pv[i]+dv[i];
        sv[2*i] += sv[i];
        av[2*i] += av[i];
        pv[2*i] += pv[i];
        if(!(i&1))
        {
            dv[i+1] += dv[i];
            av[i+1] += av[i];
            sv[i+1] += pv[i]/2+sv[i];
            pv[i+1] += pv[i]/2;
            if(i>2)
            {
                av[i-1] += pv[i]/2+av[i];
                dv[i-1] += dv[i];
                sv[i-1] += sv[i];
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    solve();
    cout << dv[2] << av[2] << sv[2] << endl;
    while(T--)
    {
        int n;
        scanf("%d %d %d %d", &n, &d, &s, &a);
        r = d*dv[n]+s*sv[n]+a*av[n];
        printf("%.3lf\n", r);
    }
    return 0;
}

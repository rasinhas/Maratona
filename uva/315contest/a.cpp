#include <iostream>
#include <cstdio>
using namespace std;

long long pot2[32];
long long pot3[32];

long long f(int i, int k)
{
    long long u, v, r;
    v = pot2[k];
    u = pot3[k];
    r = 0;
    if(i == pot2[k]+1) r++;
    while(v > 1)
    {
        v/=2;
        if(i > v)
        {
            r += 2*u/3; 
            u = u/3;
            i -= v;
        }
        else u = (u*2)/3;
    }
    return r;
}

int main()
{
    int n, k, a, b;
    pot2[0] = 1;
    pot3[0] = 1;
    for(int i=1;i<31;i++) pot2[i] = 2*pot2[i-1];
    for(int i=1;i<31;i++) pot3[i] = 3*pot3[i-1];
    cin >> n;
    for(int t=1;t<=n;t++)
    {
        cin >> k >> a >> b;
        printf("Case %d: ", t);
        cout << (f(b+1,k)-f(a,k)) << endl;
    }
    return 0;
}

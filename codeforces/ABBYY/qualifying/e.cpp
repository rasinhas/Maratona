#include <stdio.h>
#include <iostream>
#define mod 1000000000

using namespace std;

int main()
{
    int n, m;
    int x, v, l, r, t;
    long long f[200];
    long long a[200];
    long long sum;
    f[0] = f[1] = 1;
    for(int i=2;i<=150;i++) f[i] = (f[i-1]+f[i-2])%mod;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> v;
            a[x] = v;
        }
        else if(t == 2)
        {
            cin >> l >> r;
            sum = 0;
            for(int j=l;j<=r;j++)
            {
                sum = (sum+a[j]*f[j-l])%mod;
            }
            cout << sum%mod << endl;
        }
        else if(t == 3)
        {
        }
    }
    return 0;
}


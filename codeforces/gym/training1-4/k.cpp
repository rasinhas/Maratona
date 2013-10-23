#include <iostream>
#include <cstdio>

using namespace std;

int a[111], s[111], dp[111], c[111];

int gcd(int a, int b) { return (b ? gcd(b,a%b) : a); } 

int main()
{
    int t, n, p;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(i) s[i] = s[i-1]+a[i];
            else s[i] = a[i];
            dp[i] = p/gcd(p,s[i]);
            c[i] = 0;
        }
        dp[0] = p/gcd(p,s[0]);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]/gcd(dp[j],s[i]-s[j]) < dp[i] || (dp[j]/gcd(dp[j],s[i]-s[j]) == dp[i] && c[j]+1 < c[i]))
                {
                    dp[i] = dp[j]/gcd(dp[j],(s[i]-s[j]));
                    c[i] = c[j]+1;
                }
            }
        }
        for(int j=0;j<n;j++) printf("%3d", dp[j]);
        cout << endl;
        cout << p/dp[n-1] << " " << c[n-1] << endl;
    }
    return 0;
}

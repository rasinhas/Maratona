#include <iostream>
#include <cstdio>

using namespace std;

int a[3333], b[3333], c[3333], dp[2][3333];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    if(n == 1) cout << a[0] << endl;
    else
    {
        for(int i=1;i<n-1;i++)
        {
            dp[0][i] = max(dp[0][i-1]+b[i],dp[1][i-1]+a[i]);
            dp[1][i] = max(dp[0][i-1]+c[i],dp[1][i-1]+b[i]);
        }
        cout << max(dp[0][n-2]+b[n-1],dp[1][n-2]+a[n-1]) << endl;
    }
    return 0;
}

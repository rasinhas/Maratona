#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int dp[2][1111111];

int main()
{
    int n, m=0;
    string s;
    cin >> n;
    cin >> s;
    dp[0][0] = (s[0] == 'A' ? 0 : 1);
    dp[1][0] = (s[0] == 'A' ? 1 : 0);
    for(int i=1;i<n;i++)
    {
        if(s[i] == 'A')
        {
            dp[0][i] = dp[0][i-1];
            dp[1][i] = min(dp[1][i-1]+1,dp[0][i-1]+1);
        }
        else
        {
            dp[1][i] = dp[1][i-1];
            dp[0][i] = min(dp[0][i-1]+1,dp[1][i-1]+1);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}

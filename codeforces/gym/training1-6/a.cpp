#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int c[11];
int dp[222];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i=0;i<=200;i++) dp[i] = inf;
        for(int i=0;i<6;i++)
        {
            cin >> c[i];
            dp[c[i]] = 1;
        }
        int l = 94;
        int p = 1;
        while(l)
        {
            for(int i=1;i<=200;i++) if(dp[i] == p)
            {
                for(int j=0;j<6;j++)
                {
                    if(i+c[j] <= 200 && dp[i+c[j]] == inf)
                    {
                        dp[i+c[j]] = dp[i]+1;
                        if(i+c[j] <= 100) l--;
                    }
                    if(i-c[j] > 0 && dp[i-c[j]] == inf)
                    {
                        dp[i-c[j]] = dp[i]+1;
                        if(i-c[j] <= 100) l--;
                    }
                }
            }
            p++;
        }
        double s = 0;
        int m = 0;
        for(int i=1;i<=100;i++)
        {
            s += dp[i];
            m = max(m,dp[i]);
        }
        printf("%.2lf %d\n",s/100,m);
    }
    return 0;
}

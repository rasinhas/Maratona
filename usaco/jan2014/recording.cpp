#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

int n, m;
pair<int,int> interv[222];
int dp[222][222];

int main()
{
    ifstream in("recording.in");
    ofstream out("recording.out");
    in >> n;
    m = 0;
    for(int i=1;i<=n;i++) in >> interv[i].ff >> interv[i].ss;
    sort(interv, interv+n+1);
    for(int i=1;i<=n;i++) dp[0][i] = 1;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n+1;j++) if(interv[j].ff >= interv[i].ss) dp[0][j] = dp[j][0] = max(dp[0][j], dp[0][i]+1);
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(i > 0 && (interv[i].ss <= interv[j].ff || interv[j].ss <= interv[i].ff)) continue;
            for(int k=j+1;k<=n;k++)
            {
                if(interv[k].ff >= interv[i].ss && interv[k].ff < interv[j].ss) dp[j][k] = dp[k][j] = max(dp[j][k],dp[i][j]+1);
                if(interv[k].ff >= interv[j].ss && interv[k].ff < interv[i].ss) dp[i][k] = dp[k][i] = max(dp[i][k],dp[i][j]+1);
            }
            m = max(m,dp[i][j]);
        }
    }
    out << m << endl;
    return 0;
}


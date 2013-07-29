#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mp make_pair

using namespace std;

int fn[555][111];
pair<int,int> dp[555][111];

int main()
{
    int n, s, w;
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        printf("Case %d: ", t);
        cin >> n >> s >> w;
        memset(fn,0,sizeof(fn));
        for(int i=1;i<=n;i++) for(int j=1;j<=s;j++) dp[i][j] = mp(1e9,0);
        for(int i=1;i<=w;i++)
        {
            int k;
            cin >> k;
            for(int j=0;j<k;j++)
            {
                int l;
                cin >> l;
                fn[l][i]=1;
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=w;j++) fn[i][j] = fn[i][j] + fn[i-1][j];
        int f=0;
        for(int i=1;i<=w;i++) if(fn[1][i] > 0) f++;
        if(1+f <= s) dp[1][1+f] = mp(f,1);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(dp[i][j].first != 1e9)
                {
                    f = 0;
                    int l = dp[i][j].second;
                    for(int k=1;k<=w;k++) if(fn[i+1][k]-fn[i][k] > 0 && fn[i][k]-fn[l-1][k] == 0) f++;
                    if(j+f+1 <= s) if(dp[i][j].first + f < dp[i+1][j+f+1].first) dp[i+1][j+f+1] = mp(dp[i][j].first+f,l);
                    f = 0;
                    for(int k=1;k<=w;k++) if(fn[i+1][k]-fn[i][k] > 0) f++;
                    if(f+1 <= s) if(dp[i][j].first+f < dp[i+1][f+1].first) dp[i+1][f+1] = mp(dp[i][j].first + f,i+1);
                }
            }
        }
        int best = 1e9;
        for(int i=1;i<=s;i++) best = min(best,dp[n][i].first);
        cout << (best != 1e9 ? best : -1) << endl;
    }
    return 0;
}

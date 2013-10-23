#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map <int,int> dp;
vector <int> di;

int main()
{
    int n, ans;
    cin >> n;
    for(int i=2;i*i<=n;i++) if(n%i == 0) 
    {
        di.push_back(i);
        if(i*i != n) di.push_back(n/i);
    }
    sort(di.begin(),di.end());
    for(int i=0;i<di.size();i++)
    {
        dp[di[i]] = di[i]/2+1;
        for(int j=0;j<i;j++) if(di[i]%di[j] == 0) dp[di[i]] = min(dp[di[i]],(dp[di[i]/di[j]])*(dp[di[j]]));
    }
    ans = n/2+1;
    for(int i=0;i<di.size();i++) ans = min(ans,dp[di[i]]*dp[n/di[i]]);
    cout << ans << endl;
    return 0;
}

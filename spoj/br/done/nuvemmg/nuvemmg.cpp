#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int k, l;
    int i, j, m;
    int dem[600], pr[600], dp[600][600];
    while(scanf("%d%d", &k, &l) && k)
    {
        for(i=0;i<k;i++) scanf("%d %d", &dem[i], &pr[i]);
        for(i=0;i<=k;i++) for(j=0;j<=l;j++) dp[i][j] = INF;
        sort(pr,pr+k);
        sort(dem,dem+k);
        for(i=k-1;i>=0;i--) dp[i][l-1] = (k-i)*pr[k-1];
        for(i=l-1;i>0;i--)
        {
            for(j=k-l+i;j>=0;j--)
            {
                for(m=j-1;m>=0;m--)
                {
                    dp[m][i-1] = min(dp[m][i-1],dp[j][i]+(j-m)*pr[j-1]);
                }
            }
        }
        printf("%d\n", dp[0][0]);
    }
	return 0;
}

#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;

const ll M=1e9+7;
set<ll> s;
char c[111];
ll dp[111];

const ll C = 1234567;
ll pot[111];

int main()
{
    pot[0]=1;
    for(int i=1;i<111;i++) pot[i] = (C*pot[i-1])%M;
    int i, j, n, q;
    while(scanf("%d", &n) != EOF)
    {
        s.clear();
        for(i=0; i<n; i++)
        {
            scanf("%s", c);
            ll h=0;
            int sz = strlen(c);
            for(int j=sz-1;j>=0;j--) h = (h+pot[j]*c[j])%M;
            s.insert(h);
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%s", c);
            int sz=strlen(c);
            memset(dp, 0, sizeof(dp));
            dp[0]=1;
            for(i=1; i<=sz; i++)
            {
                ll h=0;
                for(j=i; j>=1; j--)
                {
                    h = (h*C + c[j-1])%M;
                    if(s.count(h)) {
                        dp[i]=(dp[i]+dp[j-1])%M;
                    }
                }
            }
            printf("%lld\n", dp[sz]);
        }
    }
    return 0;
}

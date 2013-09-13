#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

//[pos][round]
double dp[55][55];
char c[55][5];
int m;

void go(int x, int r, double p)
{
    x = min(x,m+1);
    if(!strcmp(c[x],"L")) dp[x][r+1] += p;
    else
    {
        int d;
        sscanf(c[x],"%d", &d);
        dp[min(m+1,x+d)][r] += p;
    }
}

int main()
{
    int t, r;
    cin >> t;
    while(t--)
    {
        double ret=0.0;
        cin >> m >> r;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<m;i++) cin >> c[i+1];
        c[m+1][0] = '0';
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                go(j+1,i+1,dp[j][i]/2);
                go(j+2,i+1,dp[j][i]/2);
            }
            ret += dp[m+1][i];
        }
        if(ret > 0.5) printf("Bet for. ");
        else if(ret < 0.5) printf("Bet against. ");
        else printf("Push. ");
        printf("%.4lf\n", ret);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#define inf 0x3f3f3f3f
#define sz size()
#define pb push_back

using namespace std;

// caractere da palavra x pos esq x pos dir
double dp[333][22][22];
double t[12][12];

void precalct()
{
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            double dx2 = (i/3-j/3)*(i/3-j/3);
            double dy2 = (i%3-j%3)*(i%3-j%3);
            t[i][j] = sqrt(dx2+dy2)/30;
        }
    }
}

int pos(char c)
{
    if(c == ' ') return 10;
    else if(c == '#') return 11;
    else if(c < 'd') return 1;
    else if(c < 'g') return 2;
    else if(c < 'j') return 3;
    else if(c < 'm') return 4;
    else if(c < 'p') return 5;
    else if(c < 't') return 6;
    else if(c < 'w') return 7;
    else return 8;
}

double press(char c)
{
    if(c == ' ') return 1;
    else if(c == '#') return 1;
    else if(c < 'd') return c-'a'+1;
    else if(c < 'g') return c-'d'+1;
    else if(c < 'j') return c-'g'+1;
    else if(c < 'm') return c-'j'+1;
    else if(c < 'p') return c-'m'+1;
    else if(c < 't') return c-'p'+1;
    else if(c < 'w') return c-'t'+1;
    else return c-'w'+1;
}

int main()
{
    char s[222];
    vector <char> p;
    precalct();
    while(scanf("%[^\n]", s) != EOF)
    {
        getchar();
        p.clear();
        p.pb(s[0]);
        int len = strlen(s);
        for(int i=1;i<len;i++)
        {
            if(pos(s[i]) == pos(s[i-1])) p.pb('#');
            p.pb(s[i]);
        }
        for(int i=0;i<=p.sz;i++) for(int j=0;j<12;j++) for(int k=0;k<12;k++) dp[i][j][k] = 1000000.0;
        dp[0][3][5] = 0;
        for(int i=1;i<=p.sz;i++)
        {
            int next = pos(p[i-1]);
            for(int j=0;j<12;j++)
            {
                for(int k=0;k<12;k++)
                {
                    dp[i][j][next] = min(dp[i][j][next],dp[i-1][j][k]+t[k][next]+0.2*press(p[i-1]));
                    dp[i][next][k] = min(dp[i][next][k],dp[i-1][j][k]+t[j][next]+0.2*press(p[i-1]));
                }
            }
        }
        double ret = 10000000.0;
        for(int j=0;j<12;j++)
        {
            for(int k=0;k<12;k++)
            {
                ret = min(ret,dp[p.sz][j][k]);
            }
        }
        printf("%.2lf\n", ret);
    }
    return 0;
}

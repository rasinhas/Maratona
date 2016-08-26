#include <iostream>
#include <cstdio>

using namespace std;

int a[3];
double at[44];
double p[2][44];
double dp[2][333][333];

// WA
// ideia errada? dp[][][] jogador que esta jogando, vida do primeiro, vida do segundo
// p[i][j] maior probabilidade do jogador i tirar vida j em uma jogada

int main()
{
    int va, vb, na, nb;
    int d;
    while(scanf("%d%d%d%d", &va, &vb, &na, &nb) != EOF)
    {
        memset(p,0.0,sizeof(p));
        memset(dp,0.0,sizeof(dp));
        for(int i=0;i<na;i++)
        {
            cin >> d;
            memset(a,0,sizeof(a));
            memset(at,0.0,sizeof(at));
            for(int j=0;j<d;j++) cin >> a[j];
            for(int j=0;j<=a[0];j++) for(int k=0;k<=a[1];k++) for(int l=0;l<=a[2];l++)
            {
                if(d == 1 && j > 0) at[j] +=  1.0/a[0];
                else if(d == 2 && j > 0 && k > 0) at[j+k] += 1.0/(a[0]*a[1]);
                else if(d == 3 && j > 0 && k > 0 && l > 0) at[j+k+l] += 1.0/(a[0]*a[1]*a[2]);
                else continue;
            }
            for(int j=1;j<=36;j++) p[0][j] = max(p[0][j], at[j]);// tem que ser max ou +=?
        }
        for(int i=0;i<nb;i++)
        {
            cin >> d;
            memset(a,0,sizeof(a));
            memset(at,0.0,sizeof(at));
            for(int j=0;j<d;j++) cin >> a[j];
            for(int j=0;j<=a[0];j++) for(int k=0;k<=a[1];k++) for(int l=0;l<=a[2];l++)
            {
                if(d == 1 && j > 0) at[j] +=  1.0/a[0];
                else if(d == 2 && j > 0 && k > 0) at[j+k] += 1.0/(a[0]*a[1]);
                else if(d == 3 && j > 0 && k > 0 && l > 0) at[j+k+l] += 1.0/(a[0]*a[1]*a[2]);
                else continue;
            }
            for(int j=1;j<=36;j++) p[1][j] = max(p[1][j], at[j]);// tem que ser max ou +=?
        }
        dp[0][va][vb] = 1; 
        for(int i=va;i>0;i--)
        {
            for(int j=vb;j>0;j--)
            {
                for(int k=0;k<2;k++)
                {
                    if(dp[k][i][j] > 0)
                    {
                        for(int l=1;l<=36;l++)
                        {
                            if(p[k][l] > 0)
                            {
                                if(k == 0) dp[1-k][i][max(j-l,0)] += dp[k][i][j]*p[k][l];
                                else dp[1-k][max(i-l,0)][j] += dp[k][i][j]*p[k][l];
                            }
                        }
                    }
                }
            }
        }
        for(int i=va;i>=0;i--)
        {
            for(int j=vb;j>=0;j--)
            {
                printf("%6.3lf", dp[0][i][j]);
            }
            cout << endl;
        }
        cout << endl;
        for(int i=va;i>=0;i--)
        {
            for(int j=vb;j>=0;j--)
            {
                printf("%6.3lf", dp[1][i][j]);
            }
            cout << endl;
        }
        double ret = 0;
        for(int i=va;i>=0;i--) ret += dp[1][i][0];
        printf("%.3lf\n", ret);
    }
    return 0;
}

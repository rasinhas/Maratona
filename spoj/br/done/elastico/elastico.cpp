#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define err 1e-4

using namespace std;

int main()
{
    int i, j, k, n, teste=0, x[210], y[210], dp[210][210], maximo;
    double tg;
    vector <pair<double,pair<double,int> > > pto;
    int u, v, w;
    while(scanf("%d", &n) && n)
    {
        pto.clear();
        maximo=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            tg = (double)y[i]/x[i];
            pto.push_back(make_pair(tg, make_pair((double)1/((x[i]*x[i])+(y[i]*y[i])),i)));
            memset(dp[i],0,n*sizeof(int));
        }
        sort(pto.begin(),pto.end());
        for(i=0;i<n;i++)
        {
            u = pto[i].second.second;
            dp[u][u] = 2;
            for(j=0;j<i;j++)
            {
                v = pto[j].second.second;
                if(pto[u].first-pto[v].first > err || -pto[u].first-pto[v].first < err)
                {
                    dp[u][v] = 3;
                }
                for(k=0; k<j; k++)
                {
                    w = pto[k].second.second;
                    if((y[u]-y[w])*(x[v]-x[w]) > (y[v]-y[w])*(x[u]-x[w])) 
                    {
                        dp[u][v] = max(dp[u][v], dp[v][w]+1);
                    }
                }
                maximo = max(maximo,dp[u][v]);
            }
        }
        printf("Teste %d\n%d\n\n", ++teste, maximo);
    }
    return 0;   
}



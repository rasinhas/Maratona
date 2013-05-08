#include <stdio.h>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<string, int> city;
double x[1001][51], y[1001][51], dp[1001][50];
int vis[1001], cand[1001];
vector<int> grafo[1001];

void dfs(int u)
{
    int i, j, k, v;
    double dist;
    vis[u]=1;
    for(i=0; i<grafo[u].size(); i++)
    {
        v=grafo[u][i];
        if(!vis[v])
        {
            dfs(v);
            for(j=0; j<cand[u]; j++)
            {
                dist=1000000000000000.0;
                for(k=0; k<cand[v]; k++) dist=min(dist, hypot(x[u][j]-x[v][k], y[u][j]-y[v][k])+dp[v][k]);
                dp[u][j]+=dist;
            }
        }
    }
}

int main()
{
    int i, j, k, n, c, a, b;
    char s[50], c1[50], c2[50];
    double resp;
    while(scanf("%d", &n) && n)
    {
        city.clear();
        for(i=0; i<n; i++)
        {
            grafo[i].clear();
            vis[i]=0;
            scanf("%s %d", s, &cand[i]);
            city[s]=i;
            for(j=0; j<cand[i]; j++)
            {
                scanf("%lf %lf", &x[i][j], &y[i][j]);
                dp[i][j]=0.0;
            }
        }
        for(i=0; i<n-1; i++)
        {
            scanf("%s %s", c1, c2);
            a=city[c1], b=city[c2];
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        dfs(0);
        resp=1000000000000000.0;
        for(i=0; i<cand[0]; i++) resp=min(resp, dp[0][i]);
        printf("%.1lf\n", resp);
    }
    return 0;
}

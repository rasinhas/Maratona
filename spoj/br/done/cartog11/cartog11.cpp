#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)

using namespace std;

vector <int> grafo[1000000];
int vis[1000000];
int dmax;
int vertex;

void dfs(int v, int d)
{
    int i, c, len;
    len = grafo[v].size();
    for(i=0;i<len;i++)
    {
        c = grafo[v][i];
        if(!vis[c])
        {
            vis[c]=1;
            if(dmax < d+1)
            {
                dmax = d+1; 
                vertex = c;
            }
            dfs(c, d+1);
        }
    }
}

int main()
{
    int n, a, b;
    int start, d, i, j, first, second, c;
    scanf("%d", &n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(i=0;i<n;i++) vis[i]=0;
    dfs(0, 0);
    for(i=0;i<n;i++) vis[i]=0;
    dfs(vertex, 0);
    printf("%d\n", dmax);
    return 0;
}

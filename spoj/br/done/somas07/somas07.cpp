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

vector <int> adj[100100], conj[2];
int par[100100], vis[100100], v[100100];

int dfs(int u, int pi, int p)
{
    int q, ret = 1;
    vis[u] = 1;
    par[u] = p;
    conj[p].push_back(v[u]);
    for(int i=0;i<adj[u].size();i++)
    {
        q = adj[u][i];
        if(q == pi) continue;
        if(vis[q] && par[u] == par[q]) return 0;
        if(!vis[q] && !dfs(q,u,1-p)) return 0;
    }
    return ret;
}

int main()
{
    int n, m, i, fi, in, s, p, ret=1;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
        vis[i] = 0;
        par[i] = -1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d", &s);
        fi = n-1;
        in = 0;
        while(fi > in)
        {
            if(v[in]+v[fi] > s) fi--;
            else if(v[in]+v[fi] < s) in++;
            else
            {
                adj[in].push_back(fi);
                adj[fi].push_back(in);
                in++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        p = 0;
        if(vis[i]) continue;
        if(!(ret = dfs(i,i,p))) break;
    }
    if(!ret) printf("-1\n-1\n");
    else
    {
        sort(conj[0].begin(),conj[0].end());
        sort(conj[1].begin(),conj[1].end());
        printf("%d", (int)conj[0].size());
        for(i=0;i<conj[0].size();i++) printf(" %d", conj[0][i]);
        printf("\n%d", (int)conj[1].size());
        for(i=0;i<conj[1].size();i++) printf(" %d", conj[1][i]);
        printf("\n");
    }
	return 0;
}

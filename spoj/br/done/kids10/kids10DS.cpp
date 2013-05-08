//SOLUÇÃO USANDO DISJOINT SETS//
#include <iostream>
#include <ctype.h>
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

using namespace std;

int pai[200100], rank[200100], sz[200100];

void init_set(int p)
{
    int i;
    for(i=0;i<p;i++) 
    {
        pai[i] = i;
        rank[i] = 0;
        sz[i] = 1;
    }
}

int find_set(int x)
{
    if(x != pai[x])
    {
        pai[x] = find_set(pai[x]);
    }
    return pai[x];
}

void merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if(rank[x] > rank[y])
    {
        pai[y] = x;
        sz[x] += sz[y];
    }
    else
    {
        pai[x] = y;
        sz[y] += sz[x];
        if(rank[x] == rank[y]) rank[y]++;
    }
}

int main()
{
    int i, n, k, u, v, cnt, ret, a;
    int vis[200100];
    map <int,int> ind;
    set <pair<int,int> > merges;
    set <pair<int,int> >::iterator it;
    while(scanf("%d %d", &n, &k) && n)
    {
        cnt = 1;
        ret = 1;
        merges.clear();
        ind.clear();
        for(i=0;i<k;i++)
        {
            scanf("%d%d", &u, &v);
            if(!ind[u])
            {
                ind[u] = cnt;
                cnt++;
            }
            if(!ind[v])
            {
                ind[v] = cnt;
                cnt++;
            }
            if(ind[u] <= ind[v]) merges.insert(make_pair(ind[u],ind[v]));
            else merges.insert(make_pair(ind[v],ind[u]));
        }
        init_set(cnt);
        memset(vis,0,cnt*sizeof(int));
        for(it=merges.begin();it!=merges.end();it++)
        {
            a = find_set((*it).first);
            if(find_set((*it).first) != find_set((*it).second)) merge_set((*it).first, (*it).second);
            else if(find_set((*it).first) == find_set((*it).second) && sz[a] < n) ret = 0;
            if(++vis[(*it).first] > 2) ret = 0;
            if(++vis[(*it).second] > 2) ret = 0;
        }
        if(ret) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

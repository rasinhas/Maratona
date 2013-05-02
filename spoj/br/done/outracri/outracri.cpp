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

typedef pair <int, int> pii;

vector <int> adj[101000];

int workers(int u, int t)
{
    int i, ret=0;
    vector <int> filhos;
    if(adj[u].size() == 0) return 1;
    int pmin = adj[u].size()*t/100;
    if((adj[u].size()*t)%100 != 0) pmin++;
    for(i=0;i<adj[u].size();i++) filhos.push_back(workers(adj[u][i],t));
    sort(filhos.begin(),filhos.end());
    for(i=0;i<pmin;i++) ret += filhos[i];
    return ret;
}

int main()
{
    int i, n, t, b;
    while(scanf("%d%d", &n, &t) && n)
    {
        for(i=0;i<=n;i++) adj[i].clear();
        for(i=0;i<n;i++)
        {
            scanf("%d", &b);
            adj[b].push_back(i+1);
        }
        printf("%d\n", workers(0,t));
    }
	return 0;
}

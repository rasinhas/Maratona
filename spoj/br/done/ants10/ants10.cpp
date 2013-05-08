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

int main()
{
    int i, n, p, q, u, v, s, t;
    long long d;
    vector<pair <int,long long> > vertex;
    while(scanf("%d", &n) && n>0)
    {
        vertex.clear();
        vertex.push_back(make_pair(0,0));
        for(i=1;i<n;i++)
        {
            scanf("%d %lld", &p, &d);
            vertex.push_back(make_pair(p, d));
        }
        for(i=1;i<n;i++) vertex[i].second += vertex[vertex[i].first].second;
        scanf("%d", &q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d", &s, &t);
            u = s; v = t;
            while(u != v)
            {
                if(vertex[u].second < vertex[v].second) v = vertex[v].first;
                else u = vertex[u].first;
            }
            printf("%lld ", vertex[s].second+vertex[t].second-2*vertex[u].second);
        }
        printf("\n");
    }
	return 0;
}

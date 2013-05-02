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

vector <int> adj[50000], clique;
vector <pair<int,int> > ar;
int inclique[50000], grau[50000];

int main()
{
    int i, j, n, m, g, flag, a, b, ccnt;
    while(scanf("%d%d", &n, &m) && n)
    {
        flag = 1;
        for(i=0;i<n;i++) 
        {
            adj[i].clear();
            grau[i] = 0;
            inclique[i] = 0;
        }
        clique.clear();
        ar.clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d", &a, &b);
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            grau[a]++;
            grau[b]++;
            ar.push_back(make_pair(a,b));
        }
        g = INF;
        for(i=0;i<m;i++) g = min(g,max(grau[ar[i].first],grau[ar[i].second]));
        for(i=0;i<n;i++) if(grau[i] >= g)
        {
            clique.push_back(i);
            inclique[i] = 1;
        }
        if(clique.size() > g+1) printf("N\n");
        else
        {
            for(i=0;i<clique.size();i++)
            {
                ccnt = 0;
                for(j=0;j<adj[clique[i]].size();j++) if(inclique[adj[clique[i]][j]]) ccnt++;
                if(ccnt < clique.size()-1)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) printf("Y\n");
            else printf("N\n");
        }
    }
	return 0;
}

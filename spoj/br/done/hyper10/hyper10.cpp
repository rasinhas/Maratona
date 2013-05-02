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
#define MOD 100000000

using namespace std;

typedef pair <int, int> pii;

int main()
{
    int m, n, a, b;
    int i, j, k, ret;
    int pd[101][101];
    vector <pair<int,int> > interv;
    while(scanf("%d%d", &m, &n) && n)
    {
        interv.clear();
        for(i=0;i<n;i++) memset(pd[i],0,n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &a, &b);
            interv.push_back(make_pair(a,b));
        }
        sort(interv.begin(),interv.end());
        ret = 0;
        if(interv[0].first == 0)
        {
            for(i=0;i<n;i++)
            {
                if(interv[i].first == 0 && interv[i].second == m) 
                {
                    ret++;
                    continue;
                }
                for(j=i+1;j<n;j++)
                {
                    if(interv[i].first < interv[j].first && interv[i].second >= interv[j].first && interv[j].second > interv[i].second)
                    {
                        if(interv[i].first == 0) pd[i][j] += 1;
                        for(k=0;k<i;k++) if(interv[k].second < interv[j].first) pd[i][j] = (pd[i][j]+pd[k][i])%MOD;
                    }
                    if(interv[j].second == m) ret = (ret+pd[i][j])%MOD;
                }
            }
        }
        printf("%d\n", ret);
    }
	return 0;
}

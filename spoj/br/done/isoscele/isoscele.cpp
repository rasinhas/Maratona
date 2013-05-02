#include <iostream>
#include <ctype.h>
#include <cmath>
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
    int n, x, y, i, j, iso, cnt;
    vector <pair<int,int> > points;
    vector <long long> dist;
    pair <long long,long long> u, v;
    while(scanf("%d", &n) && n)
    {
        iso = 0;
        points.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &x, &y);
            points.push_back(make_pair(x, y));
        }
        for(i=0;i<n;i++)
        {
            dist.clear();
            for(j=0;j<n;j++)
            {
                if(i == j) continue;
                v = points[i];
                u = points[j];
                dist.push_back((v.first-u.first)*(v.first-u.first)+(v.second-u.second)*(v.second-u.second));
            }
            sort(dist.begin(),dist.end());
            dist.push_back(0);
            cnt = 1;
            for(j=1;j<dist.size();j++)
            {
                if(dist[j-1] == dist[j]) cnt++;
                else
                {
                    iso += (cnt-1)*cnt/2;
                    cnt = 1;
                }
            }
        }
        printf("%d\n", iso);
    }
	return 0;
}

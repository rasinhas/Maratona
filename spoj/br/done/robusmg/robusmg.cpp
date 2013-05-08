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

double t[101][1001];

int main()
{
    int n, b, c[101];
    int i, j, v;
    double f[101], ret, p;
    while(scanf("%d%d", &n, &b) && n)
    {
        for(i=0;i<n;i++) scanf("%d %lf", &c[i], &f[i]);
        for(i=0;i<=n;i++) for(j=0;j<=b;j++) t[i][j] = 0;
        t[0][0] = 1;
        for(i=1;i<=n;i++)
        {
            for(j=b;j>=0;j--)
            {
                if(t[i-1][j])
                {
                    p = 1;
                    v = j;
                    while(v < b)
                    {
                        p *= f[i-1];
                        v += c[i-1];
                        t[i][v] = max(t[i][v],t[i-1][j]*(1-p));
                    }
                }
            }
        }
        ret = 0;
        for(i=0;i<=b;i++) ret = max(ret,t[n][i]);
        printf("%.3lf\n",ret);
    }
	return 0;
}

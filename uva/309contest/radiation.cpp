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
#define EPS 1e-8

using namespace std;

int ppda[15000], ppdb[15000];
int x[200001], y[200001];

int mod(int a) { return a > 0 ? a : -a;}

int main()
{
    int n, ax, ay, bx, by;
    int q, ra, rb, val, i;
    int t=1;
    double v;
    while(scanf("%d", &n) && n)
    {
        memset(ppda,0,sizeof(ppda));
        memset(ppdb,0,sizeof(ppdb));
        for(i=0;i<n;i++) scanf("%d %d", &x[i], &y[i]);
        scanf("%d %d %d %d %d", &ax, &ay, &bx, &by, &q);
        for(i=0;i<n;i++)
        {
            v = sqrt((ax-x[i])*(ax-x[i]) + (ay-y[i])*(ay-y[i]));
            v = ceil(v);
            if(v < 15000.00)
            {
                ppda[(int)v]++;
            }
            v = sqrt((bx-x[i])*(bx-x[i]) + (by-y[i])*(by-y[i]));
            v = ceil(v);
            if(v < 15000.00)
            {
                ppdb[(int)v]++; 
            }
        }
        for(i=1;i<15000;i++)
        {
            ppda[i] += ppda[i-1];
            ppdb[i] += ppdb[i-1];
        }
        printf("Case %d:\n", t++);
        for(i=0;i<q;i++)
        {
            scanf("%d %d", &ra, &rb);
            val = ppda[ra]+ppdb[rb];
            if(val >= n) printf("0\n");
            else printf("%d\n",n-val);
        }
    }
	return 0;
}

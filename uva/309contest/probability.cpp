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

double pt[22000], p;

int main()
{
    int i, sum, n, r, k;
    double *a, *b;
    int t=1;
    while(scanf("%d %d", &n, &r) && n)
    {
        for(i=0;i<n;i++) scanf("%lf", &pt[i]);
        sort(pt,pt+n);
        for(i=0;i<n;i++)
        {
            p = (double)(pt[i]-(int)pt[i]);
            a = upper_bound(pt,pt+n,((double)(((int)pt[i]+90)%360)+p));
            b = upper_bound(pt,pt+n,((double)(((int)pt[i]+270)%360))+p);
            if(a>b)
            {
                k = *a - *b;
            }
            else
            {
                k = n-*b + *a;
            }
            sum += k*(n-2);
        }
        printf("Case %d: %d\n", t++, sum);
    }
	return 0;
}

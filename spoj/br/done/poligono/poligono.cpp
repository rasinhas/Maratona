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

int alc[10000001];

int main()
{
    int i, j, n, circ, amax, flag, vmax, a, parc, at, nv, d, tmin;
    int arc[10010], arct[10010];
    while(scanf("%d", &n) && n)
    {
        circ = 0;
        amax = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &a);
            arc[i] = a;
            arct[i] = circ;
            circ += a;
            amax = max(a,amax);
        }
        vmax = circ/amax;
        flag = 0;
        nv = 0;
        memset(alc,0,(circ+2)*sizeof(int));
        alc[0] = 1;
        circ = 0;
        for(i=0;i<n;i++) alc[circ += arc[i]] = 1;
        for(i=vmax;i>2;i--)
        {
            if(circ%i == 0)
            {
                parc = circ/i;
                tmin = 0;
                d = 0;
                while(d <= parc)
                {
                    d += arc[tmin];
                    tmin = (tmin+1)%n;
                }
                for(j=0;j<tmin;j++)
                {
                    nv = 0;
                    d = arct[j];
                    while(alc[d])
                    {
                        d = (d+parc)%circ;
                        nv++;
                        if(nv == i)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("-1\n");
        else printf("%d\n", n-nv);
    }
	return 0;
}

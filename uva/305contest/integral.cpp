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

long long f[1001000], fmax[1001000], fmin[1001000];

int main()
{
    int n, m, x, i, val, at, size;
    long long a, y;
    vector <pair<int,int> > next;
    queue <long long> ret;
    while(scanf("%d%d%lld", &n, &m, &y) != EOF)
    {
        next.clear();
        while(!ret.empty()) ret.pop();
        for(i=0;i<=n;i++) f[i] = -1;
        memset(fmin,0,(n+3)*sizeof(long long));
        memset(fmax,0,(n+3)*sizeof(long long));
        for(i=0;i<m;i++)
        {
            scanf("%d%d", &x, &val);
            next.push_back(make_pair(x,val));
            f[x] = val;
        }
        y *= 2;
        a = f[n];
        at = 0;
        sort(next.begin(),next.end());
        for(i=0;i<n;i++)
        {
            if(f[i] == next[at].second) at++;
            if(f[i] == -1) 
            {
                fmax[i] = max(next[at-1].second,next[at].second);
                fmin[i] = min(next[at-1].second,next[at].second);
                a += 2*fmax[i];
            }
            else 
            {
                a += 2*f[i];
                fmax[i] = fmin[i] = f[i];
                if(i == 0) a -= f[i];
            }
        }
        at = 0;
        if(a >= y)
        {
            for(i=0;i<=n;i++)
            {
                if(f[i] == next[at].second) at++;
                if(f[i] == -1)
                {
                    if(next[at].second >= next[at-1].second)
                    {
                        if(a - 2*(fmax[i]-fmin[i]) >= y)
                        {
                            f[i] = fmin[i];
                            a -= 2*(fmax[i]-fmin[i]);
                        }
                        else
                        {
                            f[i] = fmax[i]-((a-y)/2);
                            a -= 2*(fmax[i]-f[i]);
                        }
                        fmin[i+1] = f[i];
                    }
                    else
                    {
                        size = next[at].first - i;
                        if((a-(2*size*(fmax[i]-fmin[i])) >= y))
                        {
                            f[i] = fmin[i];
                            a -= (2*size*(fmax[i]-fmin[i]));
                        }
                        else
                        {
                            f[i] = fmax[i]-((a-y)/(2*size));
                            a -= (2*size*(fmax[i]-f[i]));
                        }
                        fmax[i+1] = f[i];
                    }
                    ret.push(f[i]);
                }
            }
        }
        if(a == y) 
        {
            printf("S");
            while(!ret.empty()) 
            {
                printf(" %lld", ret.front());
                ret.pop();
            }
        }
        else printf("N");
        printf("\n");
    }
	return 0;
}

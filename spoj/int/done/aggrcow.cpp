#include <iostream>
#include <stdio.h>
#include <algorithm>
#define inf 1e9

using namespace std;

int n;
int m, M;
int s[110000];

int cows(int e)
{
    int c=1;
    int start=s[0];
    for(int i=1;i<n;i++)
    {
       if(s[i]-start >= e) 
       {
           c++;
           start = s[i];
       }
    }
    return c;
}

int bs(int c)
{
    int mid, hi=M, lo=0;
    int ret=0;
    mid = (hi+lo)/2;
    while(mid > lo)
    {
        if(cows(mid) >= c)
        {
            lo = mid;
            ret = mid;
        }
        else hi = mid;
        mid = (hi+lo)/2;
    }
    return ret;
}

int main()
{
    int t, c;
    scanf("%d", &t);
    while(t--)
    {
        m = inf;
        M = 0;
        scanf("%d%d", &n, &c);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &s[i]);
            m = min(m,s[i]);
            M = max(M,s[i]);
        }
        sort(s,s+n);
        printf("%d\n",bs(c));
    }
    return 0;
}

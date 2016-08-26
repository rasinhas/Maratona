#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int> p[111111];

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int n, m;
        printf("Case %d:\n", t);
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l = 2*l+1;
            r = 2*r+1;
            p[i] = make_pair((l+r)/2,(r-l)/2);
        }
        sort(p,p+n);
        for(int i=0;i<m;i++) 
        {
            int x;
            scanf("%d", &x);
            x = 2*x+1;
        }
    }
    return 0;
}

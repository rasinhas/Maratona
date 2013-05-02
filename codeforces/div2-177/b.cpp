#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define pb push_back

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int n, m, d, v, f, p, ret;
    vector <int> vet;
    scanf("%d%d%d", &n, &m, &d);
    f = 1;
    for(int i=0;i<n*m;i++)
    {
            scanf("%d",&p);
            vet.pb(p);
            if(i == 0) v = (p%d);
            if(p%d != v) f = 0;
    }
    if(f)
    {
        sort(vet.begin(),vet.end());
        for(int i=0;i<n*m;i++)
        {
            ret += mod(vet[i]-vet[(n*m)/2]);
        }
        printf("%d\n", ret/d);
    }
    else printf("-1\n");
    return 0;
}

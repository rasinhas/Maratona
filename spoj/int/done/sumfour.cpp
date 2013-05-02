#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define sz size()

using namespace std;

vector <int> ab, cd;

int main()
{
    int n;
    int ret;
    int a[4000], b[4000], c[4000], d[4000];
    scanf("%d", &n);
    ret = 0;
    for(int i=0;i<n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        ab.pb(a[i]+b[j]);
        cd.pb(c[i]+d[j]);
    }
    sort(cd.begin(),cd.end());
    for(int i=0;i<ab.sz;i++)
    {
        ret += (lower_bound(cd.begin(), cd.end(),-(ab[i]-1)) - lower_bound(cd.begin(), cd.end(),-ab[i]));
    }
    printf("%d\n",ret);
    return 0;
}

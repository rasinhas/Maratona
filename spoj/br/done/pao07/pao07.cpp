#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, hi=0, lo=0, mid, ret=0, v;
    int p[101000];
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> p[i];
        hi = max(hi,p[i]);
    }
    lo = 0;
    mid = (lo+hi)/2;
    while(lo < mid)
    {
        v = 0;
        for(int i=0;i<k;i++) v += p[i]/mid;
        if(v >= n)
        {
            lo = mid;
            ret = max(ret,mid);
        }
        if(v < n) hi = mid;
        mid = (lo+hi)/2;
    }
    cout << ret << endl;
    return 0;
}

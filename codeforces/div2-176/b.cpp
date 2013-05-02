#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#define pipes(p) (((k-1+p)*(k-p))/2)+1
#define inf 10000000000000

using namespace std;

int main()
{
    long long n, k, lo, mid, hi, ret;
    cin >> n;
    cin >> k;
    hi = k+1;
    lo = 0;
    mid = (lo+hi)/2;
    ret = inf;
    if(pipes(0) < n) ret = -1;
    else
    {
        while(lo+1ll < hi)
        {
            if(pipes(mid) >= n)
            {
                lo = mid;
                ret = min(ret, k-mid);
            }
            else hi = mid;
            mid = (lo+hi)/2;
        }
    }
    cout << ret << endl;
    return 0;
}

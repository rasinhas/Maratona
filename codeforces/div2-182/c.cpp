#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, e, ret;
    int a[300], msum[300];
    cin >> n;
    e = (2*n)-1;
    msum[0] = 0;
    for(int i=0;i<e;i++)
    {
        cin >> a[i];
        msum[0] += a[i];
    }
    sort(a,a+e);
    for(int i=1;i<=e;i++) msum[i] = msum[i-1] - 2*a[i-1];
    ret = msum[n];
    if(n%2 == 0) for(int i=1;i<=n;i++) ret = max(ret,msum[2*(n-i)]);
    else for(int i=0;i<=e;i++) ret = max(ret,msum[i]);
    cout << ret << endl;
    return 0;
}

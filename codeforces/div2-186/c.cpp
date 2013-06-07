#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int a[3000000];

int main()
{
    int n;
    long long ret;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int k=n;
    while(k>0)
    {
        for(int i=1;i<=k;i++) ret += a[n-i];
        k/=4;
    }
    cout << ret << endl;
    return 0;
}

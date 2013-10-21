#include <iostream>
#include <cstdio>

using namespace std;

int a[111111], s[111111], b[111111];

int main()
{
    int n, ret=0, t=0;
    cin >> n;
    s[0] = b[0] = 0;
    for(int i=0;i<n;i++) 
    {
        cin >> a[i];
        s[i+1] = s[i]+a[i];
    }
    for(int i=1;i<=n;i++) b[i] = max(b[i-1],s[i]);
    for(int i=0;i<=n;i++) ret = max(ret, b[i] + s[n]-s[i]);
    for(int i=0;i<n;i++)
    {
        t = max(0,t+a[i]);
        ret = max(ret,t);
    }
    cout << ret << endl;
    return 0;
}

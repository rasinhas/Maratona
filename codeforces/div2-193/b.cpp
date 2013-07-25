#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

long long s[222222], si[222222], ms[222222], a[222222];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i > 0) s[i] = s[i-1]+a[i];
        else s[i] = a[i];
    }
    si[0] = s[k-1];
    for(int i=1;i<=n-k;i++) si[i] = s[i+k-1]-s[i-1];
    ms[n-k] = n-k;
    for(int i=n-k-1;i>=0;i--)
    {
        if(si[ms[i+1]] > si[i]) ms[i] = ms[i+1];
        else ms[i] = i;
    }
    long long ret=0;
    for(int i=0;i<=n-2*k;i++) ret = max(ret,si[i]+si[ms[i+k]]);
    for(int i=0;i<=n-2*k;i++) if(si[i]+si[ms[i+k]] == ret) 
    {
        cout << i+1 << " " << ms[i+k]+1 << endl;
        break;
    }
    return 0;
}

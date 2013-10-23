#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[222222];
int n;
long long p, q;

bool check(long long v)
{
    long long u=v;
    for(int i=0;i<n;i++)
    {
        //p*x + q*(v-x) = a[i];
        long long k = max(0ll,a[i] - v*q);
        if(p > q) u -= (k + p-q-1)/(p-q);
        if(p == q && k > 0) return 0;
    }
    return u >= 0;
}

int bs()
{
    long long hi=1000000000, lo=0, mi;
    while(hi > lo+1)
    {
        mi = (hi+lo)/2;
        if(check(mi)) hi = mi;
        else lo = mi;
    }
    return hi;
}

int main()
{
    cin >> n >> p >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << bs() << endl;
    return 0;
}

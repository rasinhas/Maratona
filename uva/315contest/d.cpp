#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    long long pa[222];
    pa[0] = 0;
    for(int i=1;i<222;i++) pa[i] = pa[i-1]+i;
    while(cin >> n && n)
    {
        long long r = 0;
        for(int i=2;i<=n;i++) r += (pa[i-1]*(n-i+1));
        cout << r << endl;
    }
    return 0;
}

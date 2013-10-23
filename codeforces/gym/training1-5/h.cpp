#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[22222];

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int d = 0;
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        for(int i=n%3;i<n;i+=3) d += a[i];
        cout << d << endl;
    }
    return 0;
}

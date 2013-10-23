#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[55];

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        cout << 2*(a[n-1]-a[0]) << endl;
    }
    return 0;
}

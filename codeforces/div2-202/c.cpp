#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

ll a[111111];

int main()
{
    int n;
    ll r;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ll p0 = a[0];
    ll s=0;
    for(int i=0;i<n;i++) 
    {
        a[i] -= p0;
        s += a[i];
    }
    ll k = s+p0-(n-1)*a[n-1];
    if(k > 0) p0 += ((k+n-2)/(n-1));
    cout << p0+a[n-1] << endl;
    return 0;
}

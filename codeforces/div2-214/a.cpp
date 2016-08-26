#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int a[4], b[4], c[4], d[4];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<4;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int i;
    for(i=0;i<4;i++)
    {
        int m = min(a[i],b[i])+min(c[i],d[i]);
        if(m <= n) break;
    }
    if(i == 4) cout << -1 << endl;
    else cout << i+1 << " " << min(a[i],b[i]) << " " << n-min(a[i],b[i]) << endl;
    return 0;
}

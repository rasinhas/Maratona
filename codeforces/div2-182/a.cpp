#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n, m, a, l, r;
    int c0, c1, p;
    cin >> n >> m;
    c0 = 0;
    c1 = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a;
        if(a == 1) c1++;
        else c0++;
    }
    for(int i=0;i<m;i++)
    {
        cin >> l >> r;
        p = r-l+1;
        if(p%2 == 1) cout << 0 << endl;
        else if(c1 >= p/2 && c0 >= p/2) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

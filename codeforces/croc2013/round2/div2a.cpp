#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, f;
    int p[100000];
    cin >> n;
    d = 1000000001;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        d = min(d,p[i]);
    }
    f = 0;
    for(int i=0;i<n;i++) if(p[i]%d != 0) f = 1;
    if(f) cout << "-1" << endl;
    else cout << d << endl;
    return 0;
}

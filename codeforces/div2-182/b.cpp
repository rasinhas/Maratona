#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    int c, t, v;
    int s[100100];
    int *a;
    cin >> n >> m;
    s[0] = 0;
    for(int i=0;i<n;i++)
    {
        cin >> c >> t;
        s[i+1] = s[i] + c*t;
    }
    for(int i=0;i<m;i++)
    {
        cin >> v;
        a = upper_bound(s,s+n,v);
        cout << (a-s) << endl;
    }
    return 0;
}

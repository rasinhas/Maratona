#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int v[111111];

int main()
{
    int n, l;
    while((cin >> n >> l) && n)
    {
        for(int i=0;i<l;i++) cin >> v[i];
        sort(v,v+l);
        int r = 1e9;
        for(int i=0;i<l;i++)
        {
            int u = v[i]+n-1;
            int k = upper_bound(v, v+l, u)-v; 
            r = min(r,n-(k-i));
        }
        cout << r << endl;
    }
    return 0;
}

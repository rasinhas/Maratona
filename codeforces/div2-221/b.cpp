#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int o[111];
int io[111];

int main()
{
    int n, m;
    int a, b, v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> v;
        a--; b--;
        o[a] += v;
        io[b] += v;
    }
    int r = 0;
    for(int i=0;i<n;i++)
    {
        int k = min(o[i],io[i]);
        o[i] -= k;
        io[i] -= k;
        r += io[i];
    }
    cout << r << endl;
    return 0;
}

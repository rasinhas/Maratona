#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int bot[1000], b[1000], a[1000];

int main()
{
    int n, ret;
    cin >> n;
    ret = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        bot[b[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i] == b[i] && bot[a[i]] > 1) ret++;
        if(a[i] != b[i] && bot[a[i]] > 0) ret++;
    }
    cout << n-ret << endl;
    return 0;
}

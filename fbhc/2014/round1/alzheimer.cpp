#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int a[66];

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<T;t++)
    {
        int n, k, s=0;
        cin >> n >> k;
        for(int i=0;i<n;i++) 
        {
            cin >> a[i];
            s += a[i];
        }
        cout << s << endl;
    }
    return 0;
}

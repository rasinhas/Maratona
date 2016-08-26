#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int a[111111], pk[111111];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pk[i%k] += a[i];
    }
    int m=1000000000, mi=-1;
    for(int i=0;i<k;i++)
    {
        if(pk[i] < m) 
        {
            m = pk[i];
            mi = i;
        }
    }
    cout << mi+1 << endl;
    return 0;
}

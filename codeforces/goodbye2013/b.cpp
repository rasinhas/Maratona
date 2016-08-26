#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int a[333];

int main()
{
    int n;
    cin >> n;
    int m = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        m = max(m,a[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j] > 0)
            {
                a[j]--;
                cout << 'P';
            }
            if(j != n-1) cout << 'R';
        }
        if(i != m-1) for(int j=1;j<n;j++) cout << 'L';
    }
    cout << endl;
    return 0;
}

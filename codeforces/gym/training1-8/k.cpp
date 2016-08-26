#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int a[111], r[111];

int main()
{
    ifstream in("cubes.in");
    int t, n;
    in >> t;
    for(int i=0;i<t;i++)
    {
        in >> n;
        printf("Case %d:\n", i+1);
        for(int j=0;j<n;j++) in >> a[j];
        sort(a,a+n);
        int p = n-1;
        for(int j=0, k=n-1;j<=k;j++,k--)
        {
            r[k] = a[p--];
            if(j < k) r[j] = a[p--];
        }
        cout << r[0];
        for(int j=1;j<n;j++) cout << " " << r[j];
        cout << endl;
    }
    return 0;
}

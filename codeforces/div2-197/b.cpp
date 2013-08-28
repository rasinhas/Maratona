#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long a[111111];

int main()
{
    long long n, m, t=0;
    cin >> n >> m;
    cin >> a[0];
    for(int i=1;i<m;i++) 
    {
        cin >> a[i];
        if(a[i] < a[i-1]) t++;
    }
    cout << (t*n)+a[m-1]-1 << endl;
    return 0;
}

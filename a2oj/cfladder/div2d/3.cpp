#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a[18][222222];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0;i<(1<<n);i++) cin >> a[0][i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<(n-i));j+=2)
        {
            if(i%2 == 0) a[i+1][j/2] = (a[i][j]|a[i][j+1]);
            else a[i+1][j/2] = (a[i][j]^a[i][j+1]);
        }
    }
    for(int i=0;i<m;i++)
    {
        int p, b;
        cin >> p >> b;
        p--;
        a[0][p] = b;
        for(int j=0;j<n;j++)
        {
            p -= p%2;
            if(j%2 == 0) a[j+1][p/2] = (a[j][p]|a[j][p+1]);
            else a[j+1][p/2] = (a[j][p]^a[j][p+1]);
            p/=2;
        }
        cout << a[n][0] << endl;
    }
    return 0;
}

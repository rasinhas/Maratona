#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int x[111111], y[111111], z[111111];
int a[3];

int main()
{
    int n;
    string s;
    cin >> s;
    x[0] = y[0] = z[0] = 0;
    for(int i=0;i<s.size();i++)
    {
        x[i+1] = x[i];
        y[i+1] = y[i];
        z[i+1] = z[i];
        if(s[i] == 'x') x[i+1]++;
        if(s[i] == 'y') y[i+1]++;
        if(s[i] == 'z') z[i+1]++;
    }
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int l, r;
        int ok = 0;
        cin >> l >> r;
        l--;
        a[0] = x[r]-x[l];
        a[1] = y[r]-y[l];
        a[2] = z[r]-z[l];
        sort(a,a+3,greater<int>());
        if((r-l) < 3) ok = 1;
        else
        {
            if(a[0] - a[1] <= 1 && a[0] - a[2] <= 1) ok = 1;
            else ok = 0; 
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

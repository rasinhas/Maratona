#include <iostream>
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

int x[111111];

int main() 
{
    int n;
    while(cin>>n && !cin.eof()) 
    {
        int s = 0;
        for(int i=0;i<n;i++) 
        {
            cin>>x[i];
            s += x[i];
        }
        int ans = 0;
        if(n > 2)
        {
            int m = *max_element(x,x+n);
            int a = s-m;
            if(2*a > m) ans = s/3;
            else ans = a;
        }
        cout << ans << endl;
    }
    return 0;
}

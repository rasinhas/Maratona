#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a[111], w[111];

int main()
{
    int n, m, tl=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> w[i];
    sort(a,a+n);
    sort(w,w+m);
    for(int i=a[n-1];i<w[0];i++)
    {
        if(2*a[0] <= i) 
        {
            tl = i;
            break;
        }
    }
    cout << tl << endl;
    return 0;
}

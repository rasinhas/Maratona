#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

pair<double,int> a[111];

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i=0;i<n;i++)
        {
            int l, w, h;
            cin >> l >> w >> h;
            a[i] = make_pair((2*h-1)/2*h,h*l*w);
        }
        sort(a,a+n);
        cout << a[n-1].second << endl;
    }
    return 0;
}

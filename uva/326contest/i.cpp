#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <cmath>
#include <numeric>

using namespace std;

int a[4], d[4];

int main()
{
    int T, r = 0;
    cin >> T;
    while(T--)
    {
        int ok = 1;
        for(int i=0;i<4;i++)
        {
            scanf("%d.%d", &a[i], &d[i]);
            a[i] = a[i]*100+d[i];
        }
        int s = a[0]+a[1]+a[2];
        if(a[3] > 700) ok = 0;
        else 
        {
            if(s <= 12500) ok = 1;
            else
            {
                if(a[0] <= 5600 && a[1] <= 4500 && a[2] <= 2500) ok = 1;
                else ok = 0;
            }
        }
        if(ok) r++;
        cout << ok << endl;
    }
    cout << r << endl;
    return 0;
}

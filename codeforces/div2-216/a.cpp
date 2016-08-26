#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, a, c;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a == 1)
        {
            if(m == 0) { m++; c++;}
            m--;
        }
        else 
        {
            if(k == 0)
            {
                if(m == 0) { m++; c++;}
                m--;
            }
            else k--;
        }
    }
    cout << c << endl;
    return 0;
}

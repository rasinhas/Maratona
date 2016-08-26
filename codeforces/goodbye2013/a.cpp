#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int a, b, c=0, r=0;
    cin >> a >> b;
    while(a)
    {
        r += a;
        c += a;
        a = c/b;
        c %= b;
    }
    cout << r << endl;
    return 0;
}

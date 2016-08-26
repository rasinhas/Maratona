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

int main()
{
    unsigned long long a, b;
    while(cin >> a >> b && (a|b) != 0)
    {
        if(b > a) swap(a,b);
        unsigned long long k = (b-1)/2;
        cout << 1ll*(3*(2*k*k*k*k + 4*k*k*k + 2*k*k) - (a+b-1)*(4*k*k*k + 6*k*k + 2*k) + 3*(a*b-a-b)*(k*k+k) + 3*(k+1)*a*b)/3 << endl;
    }
    return 0;
}

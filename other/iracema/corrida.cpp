#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, ret, f;
    while(cin >> n && n)
    {
        ret = 0;
        while(n > 1)
        {
            f = n/3;
            if(n%3 != 0) f += 1;
            n = f;
            ret += n;
        }
        cout << ret << endl;
    }
    return 0;
}

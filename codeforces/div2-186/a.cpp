#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n;
    int p1, p2;
    cin >> n;
    if(n > 0) cout << n << endl;
    else
    {
        p1 = (n-n%10)/10;
        p2 = (n-n%100)/10 + n%10;
        cout << max(p1,p2) << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int ret, n, m;
    cin >> n >> m;
    if(n == 1) ret = m;
    else if(m == 1) ret = n;
    else if(n == 2) ret = 2*(2*(m/4)+min(2,m%4));
    else if(m == 2) ret = 2*(2*(n/4)+min(2,n%4));
    else ret = (n*m+1)/2;
    cout << ret << endl;
    return 0;
}

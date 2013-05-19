#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n, cnt;
    double c;
    cin >> n;
    cnt = 0;
    for(int a=1;a<=n;a++)
    {
        for(int b=a;b<=n;b++)
        {
            c = sqrt(a*a + b*b);
            if(c == (int)c && c <= n) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

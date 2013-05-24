#include <iostream>
#include <cstdio>

using namespace std;

int pts(double x, double y)
{
    double d2 = (x*x)+(y*y);
    if(d2 <= 4.0) return 7;
    else if(d2 <= 16.0) return 5;
    else if(d2 <= 36.0) return 3;
    else if(d2 <= 64.0) return 1;
    else return 0;
}

int main()
{
    int n, p;
    double x, y;
    while(cin >> n && n)
    {
        p = 0;
        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            p += pts(x,y);
        }
        cout << p << endl;
    }
    return 0;
}

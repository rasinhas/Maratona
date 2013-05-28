#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double a, b, c, d, q;
    cin >> a >> b >> c >> d;
    q = (1.0-(a/b))*(1.0-(c/d)); 
    printf("%.12f\n",  a/(b*(1-q)));
    return 0;
}

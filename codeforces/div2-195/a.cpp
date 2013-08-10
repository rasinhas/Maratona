#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if(x > 0 && y > 0) printf("0 %d %d 0\n", x+y, x+y);
    else if(x > 0 && y < 0) printf("0 %d %d 0\n", y-x, x-y);
    else if(x < 0 && y > 0) printf("%d 0 0 %d\n", x-y, y-x);
    else printf("%d 0 0 %d\n", x+y, x+y);
    return 0;
}

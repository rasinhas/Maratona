#include <iostream>
#include <cstdio>

using namespace std;

int mod(int a) { return (a > 0 ? a : -a); }

int main()
{
    int a, b;
    int z=0, x=0, c=0;
    cin >> a >> b;
    for(int i=1;i<=6;i++)
    {
        if(mod(a-i) < mod(b-i)) z++;
        if(mod(a-i) == mod(b-i)) x++;
        if(mod(a-i) > mod(b-i)) c++;
    }
    printf("%d %d %d\n", z, x, c);
    return 0;
}

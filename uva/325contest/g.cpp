#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, a, b;
    while(scanf("%d%d%d", &n, &a, &b) != EOF)
    {
        int i=0;
        a--; b--;
        while(1)
        {
            if(a == b) break;
            a/=2;
            b/=2;
            i++;
        }
        cout << i << endl;
    }
    return 0;
}

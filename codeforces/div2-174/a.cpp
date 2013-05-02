#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, x, ret;
    scanf("%d", &n);
    ret = n-1;
    for(int i=1;i<n;i++)
    {
        x = i;
        for(int j=1;j<n-1;j++)
        {
            if((x-1)%n == 0)
            {
                ret--;
                break;
            }
            x = (x*i)%n;
        }
    }
    printf("%d\n", ret);
    return 0;
}

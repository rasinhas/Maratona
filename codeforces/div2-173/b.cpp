#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%d", &n);
    int diff = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &a, &b);
        if(diff + a <= 500) 
        {
            printf("A");
            diff += a;
        }
        else
        {
            printf("G");
            diff -= b;
        }
    }
    return 0;
}

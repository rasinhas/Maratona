#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int a, b, t=0, ta=0, tb=0;
    int choc[200000];
    scanf("%d", &n);
    a = 0;
    b = n-1;
    for(int i=0;i<n;i++) scanf("%d", &choc[i]);
    while(a <= b || (!ta || !tb))
    {
        if(ta <= tb)
        {
            ta += choc[a];
            a++;
        }
        else
        {
            tb += choc[b];
            b--;
        }
    }
    printf("%d %d\n", a, n-a);
    return 0;
}

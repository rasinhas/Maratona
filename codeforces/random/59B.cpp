#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, imp=0, s=0, m=150;
    int f[110];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &f[i]);
        if(f[i]%2)
        {
            imp++;
            if(f[i] < m) m = f[i];
        }
        s += f[i];
    }
    if(imp == 0) printf("0\n");
    else
    {
        if(imp%2 == 0) printf("%d\n", s-m);
        if(imp%2 == 1) printf("%d\n", s);
    }
    return 0;
}

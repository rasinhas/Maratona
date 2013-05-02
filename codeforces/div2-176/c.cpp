#include <iostream>
#include <stdio.h>

using namespace std;

int p[110000];

int main()
{
    int n, f = 1;
    scanf("%d", &n);
    if(n%4 == 2 || n%4 == 3) f = 0;
    else
    {
        for(int i=0;i<n/2;i+=2)
        {
            p[i] = i+2;
            p[i+1] = n-i;
            p[n-i-1] = n-i-1;
            p[n-i-2] = i+1;
        }
    }
    if(f)
    {
        if(n == 1) printf("1");
        else
        {
            printf("%d", p[0]);
            for(int i=1;i<n;i++)
            {
                if(p[i])printf(" %d", p[i]);
                else printf(" %d", i+1);
            }
        }
    }
    else printf("-1");
    printf("\n");
    return 0;
}

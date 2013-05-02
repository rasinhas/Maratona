#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0;i<k;i++)
    {
        if(i == 0)printf("%d", n);
        else printf(" %d", n-i);
    }
    for(int i=0;i<n-k;i++)
    {
        if(k == 0 && i == 0) printf("%d", i+1);
        else printf(" %d", i+1);
    }
    printf("\n");
    return 0;
}

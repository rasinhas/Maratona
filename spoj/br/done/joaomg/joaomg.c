#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, n2, i, d;
    char ret;
    while(scanf("%d", &n) && n)
    {
        n2 = n*n;
        d = 10;
        ret = 'N';
        if(n==1) ret = 'S';
        else
        {
            while(d<n2)
            {
                if((n2/d)+(n2%d)==n && (n2%d)!=0)
                {
                    ret = 'S';
                    break;
                }
                d*=10;
            }
        }
        printf("%d: %c\n", n, ret);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int n, d, pi, pf, i;
    char ret='S';
    scanf("%d %d", &n, &d);
    pi=0;
    for(i=0;i<n;i++)
    {
        scanf("%d", &pf);
        if(pf-pi>d)
        {
            ret='N';
        }
        pi=pf;
    }
    pf=42195;
    if(pf-pi>d) ret='N';
    printf("%c\n",ret);
    return 0;
}

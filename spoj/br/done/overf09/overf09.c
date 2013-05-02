#include <stdio.h>

int main()
{
    int a, b, n, ret;
    char c;
    scanf("%d %d %c %d", &n, &a, &c, &b);
    if(c=='+') ret=a+b;
    else ret=a*b;
    if(ret>n) printf("OVERFLOW\n");
    else printf("OK\n");
    return 0;
}

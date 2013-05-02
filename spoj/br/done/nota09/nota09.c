#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%d",&n);
    if(n==0) c='E';
    else if(n<36) c='D';
    else if(n<61) c='C';
    else if(n<86) c='B';
    else c='A';
    printf("%c\n",c);
    return 0;
}

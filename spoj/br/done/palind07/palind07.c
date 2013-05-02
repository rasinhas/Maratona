#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, j, l;
    long long i;
    char alf[30];
    int pal[200];
    scanf("%d", &n);
    scanf("%s", alf);
    scanf("%d%lld", &k, &i);
    i--;
    for(j=0;j<(k+1)/2;j++)
    {
        pal[j] = i%n;
        i /= n;
    }
    for(l=j-1;l>=0;l--) printf("%c", alf[pal[l]]);
    if(k%2 == 1) for(l=1;l<j;l++) printf("%c", alf[pal[l]]);
    else for(l=0;l<j;l++) printf("%c", alf[pal[l]]);
    printf("\n");
    return 0;
}

#include <stdio.h>
#define inf 0x3f3f3f3f

int main()
{
    int vet[1000100];
    int n, k, x, i, min;
    scanf("%d %d", &n, &k);
    for(i=0;i<k;i++) vet[i]=0;
    for(i=0;i<n;i++) 
    {
        scanf("%d", &x);
        vet[x-1]++;
    }
    min=inf;
    for(i=0;i<k;i++) if(vet[i]<min) min=vet[i];
    printf("%d\n",min);
    return 0;
}

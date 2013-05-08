#include <stdio.h>
#include <string.h>

long long pow2(int a)
{
    int i;
    long long ret=1;
    for(i=0;i<a;i++) ret*=2;
    return ret;
}

int main()
{
    int p=0, i, len;
    long long soma;
    char palavra[100];
    while(scanf(" %s ", palavra) != EOF)
    {
        len = strlen(palavra);
        soma = 0;
        for(i=0;i<len;i++)
        {
            if(palavra[i]=='b') soma += pow2(len-i-1);
        }
        printf("Palavra %d\n%lld\n\n", ++p, soma);
    }
    return 0;
}

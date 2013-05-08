#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, j, p1, p2, teste=1;
    int n1[10], n2[10], senha[10], seq[10];
    char letra;
    while(scanf("%d ", &n) && n)
    {
        memset(senha,0,6*sizeof(int));
        for(j=0;j<10;j++) scanf("%d", &seq[j]);
        for(j=0;j<6;j++)
        {
            scanf(" %c ", &letra);
            n1[j] = seq[2*((int)(letra-'A'))];
            n2[j] = seq[2*((int)(letra-'A'))+1];
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<10;j++) scanf("%d", &seq[j]);
            for(j=0;j<6;j++)
            {
                scanf(" %c ", &letra);
                if(!senha[j])
                {
                    p1 = seq[2*((int)(letra-'A'))];
                    p2 = seq[2*((int)(letra-'A'))+1];
                    if(n1[j] == p1 && n2[j] != p2) senha[j] = p1;
                    else if(n2[j] == p1 && n1[j] != p2) senha[j] = p1;
                    else if(n1[j] != p1 && n2[j] == p2) senha[j] = p2;
                    else if(n2[j] != p1 && n1[j] == p2) senha[j] = p2;
                }
            }
        }
        printf("Teste %d\n", teste++);
        for(i=0;i<6;i++) printf("%d ", senha[i]);
        printf("\n\n");
    }
    return 0;
}

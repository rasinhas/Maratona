#include <stdio.h>
#include <string.h>

typedef struct
{
    int p;
    int d;
}indio;

int main()
{
    int n, e, cert, batidas, i, pos, sum, sump;
    int p0[1001000], pn[1001000];
    indio ind[1100], aux;
    scanf("%d%d", &n, &e);
    memset(p0,0,n*sizeof(int));
    batidas = 0;
    sum=0;
    for(i=0;i<e;i++)
    {
        scanf("%d%d", &aux.p, &aux.d);
        aux.p--;
        p0[aux.p] = 1;
        ind[i] = aux;
        sum += aux.p;
    }
    while(batidas < n)
    {
        sump = 0;
        batidas++;
        cert = 0;
        i = 0;
        while(i < e)
        {
            if(ind[i].d == 1) pos = (ind[i].p + batidas)%n;
            else pos = (ind[i].p + n - batidas)%n;
            i++;
            if(p0[pos]) cert++;
            sump += pos;
            if(cert == e || !p0[pos]) break;
        }
        if(cert == e && sump == sum) break;
    }
    printf("%d\n", batidas);
    return 0;
}

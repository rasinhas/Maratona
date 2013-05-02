#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 1000000000

using namespace std;

int main()
{
    int i, j, n, v[50], flag, minimo, mod[10000], ind, aux;
    while(scanf("%d", &n) && n)
    {
        flag=0;
        for(i=0; i<n; i++) scanf("%d", &v[i]);
        for(i=0; i<n; i++) for(j=i+1; j<n; j++) if(v[i]==v[j]) flag=1;
        if(flag) printf("No solution\n");
        else
        {
            aux=0;
            for(i=0; i<n; i++)
            {
                for(j=i; j<n; j++) if(v[j]==i+1) { minimo=v[j]; ind=j; }
                for(j=ind; j>i; j--)
                {
                    swap(v[j], v[j-1]);
                    mod[aux++]=j;
                }
            }
            if(aux>=4*n*n) printf("No solution\n");
            else
            {
                printf("%d", aux);
                for(i=0; i<aux; i++) printf(" %d", mod[i]);
                printf("\n");
            }
        }
    }
    return 0;    
}

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, m, teste=1, grau[40];
    int i, j, a, b, k;
    char nome[20];
    map<string, int> id;
    map<int, string> nomes;
    int grafo[40][40], ordem[40];
    while(scanf("%d", &n) && n)
    {
        k=0;
        nomes.clear();
        id.clear();
        for(i=0;i<n;i++)
        {
            ordem[i] = 0;
            for(j=0;j<n;j++) grafo[i][j]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf(" %s ", nome);
            id[nome] = i;
            nomes[i] = nome;
        }
        for(i=0;i<n;i++)
        {
            scanf(" %s ", nome);
            a = id[nome];
            scanf("%d", &m);
            grau[a] = m;
            if(!m) ordem[k++]=a;
            for(j=0;j<m;j++)
            {
                scanf(" %s ", nome);
                b = id[nome];
                grafo[b][a] = 1;
            }
        }
        for(i=0;i<k;i++)
        {
            a = ordem[i];
            for(j=0;j<n;j++)
            {
                if(grafo[a][j])
                {
                    grau[j]--;
                    if(!grau[j]) ordem[k++]=j;
                }
            }
        }
        printf("Teste %d\n", teste++);
        if(k != n) printf("impossivel");
        else for(i=0;i<k;i++) cout << nomes[ordem[i]] << " ";
        printf("\n\n");
    }
    return 0;
}



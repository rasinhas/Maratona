#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> adj[1010];
int art[1010];
int low[1010], prof[1010], ordem=1;
bool temarticul;

int articul(int u, int pai)
{
    int menor = low[u] = prof[u] = ordem++;
    int filhos = 0;
    int i, len, v, m;
    len = adj[u].size();
    for(i=0;i<len;i++)
    {
        v = adj[u][i];
        if(!low[v])
        {
            filhos++;
            m = articul(v, u);
            menor = min(menor, m);
            if(u != 0 && low[v] >= prof[u])
            {
                temarticul = true; 
                art[u+1] = 1;
            }
        }
        else if(v != pai) menor = min(menor,low[v]);
    }
    low[u] = menor;
    if(u == 0 && filhos > 1) 
    {
        temarticul = true;
        art[u+1] = 1;
    }
    return menor;
}

int main()
{
    int n, m, u, v, i;
    int t=0;
    while(scanf("%d %d", &n, &m) && n)
    {
        temarticul = false;
        memset(low,0,(n+1)*sizeof(int));
        memset(prof,0,(n+1)*sizeof(int));
        memset(art,0,(n+1)*sizeof(int));
        for(i=0;i<n;i++) adj[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d", &u, &v);
            u--; 
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        articul(0,-1);
        printf("Teste %d\n", ++t);
        if(!temarticul) printf("nenhum");
        else
        {
            for(i=1;i<=n;i++) if(art[i]) printf("%d ", i);
        }
        printf("\n\n");
    }
    return 0;
}


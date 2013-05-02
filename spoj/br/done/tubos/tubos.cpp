#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector <int> adj[1010];
int low[1010], ordem=1;
bool temponte;

int ponte(int u, int pai)
{
    int menor = low[u] = ordem++;
    int i, len, v, m;
    len = adj[u].size();
    for(i=0;i<len;i++)
    {
        v = adj[u][i];
        if(!low[v])
        {
            m = ponte(v, u);
            menor = min(menor, m);
            if(low[u] < m) temponte = true; 
        }
        else if(v != pai) menor = min(menor,low[v]);
    }
    low[u] = menor;
    return menor;
}

int main()
{
    int n, m, u, v, i;
    while(scanf("%d %d", &n, &m) && n)
    {
        temponte = false;
        memset(low,0,(n+1)*sizeof(int));
        for(i=0;i<n;i++) adj[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d", &u, &v);
            u--; 
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ponte(0,-1);
        if(temponte) printf("N\n");
        else printf("S\n");
    }
    return 0;
}

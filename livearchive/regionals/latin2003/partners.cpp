#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

int vis[2000], cc, quant[2000], grafo[2000][2000], grau[2000], n;
priority_queue<pair<int, int> > q;

void dfs(int u)
{
    int i;
    vis[u]=cc;
    for(i=0; i<n; i++) if(grafo[u][i] && !vis[i]) dfs(i);
}

int main()
{
    int i, j, p, k, x, y, resp;
    while(scanf("%d %d %d", &n, &p, &k) && n)
    {
        for(i=0; i<=n; i++) { vis[i]=quant[i]=grau[i]=0; }
        memset(grafo, 0, sizeof(grafo));
        while(!q.empty()) q.pop();
        for(i=0; i<p; i++)
        {
            scanf("%d %d", &x, &y);
            x--, y--;
            grafo[x][y]=grafo[y][x]=1;
        }
        for(i=0; i<n; i++) for(j=0; j<n; j++) if(grafo[i][j]) grau[i]++;
        for(i=0; i<n; i++) q.push(make_pair(-grau[i], -i));
        while(!q.empty())
        {
            x=-q.top().first;
            y=-q.top().second;
            q.pop();
            if(x>=k) break;
            for(i=0; i<n; i++)
                if(grafo[y][i])
                {
                    grafo[y][i]=grafo[i][y]=0;
                    grau[y]--;
                    grau[i]--;
                    q.push(make_pair(-grau[i], -i));
                }
        }
        cc=1;
        resp=0;
        for(i=0; i<n; i++) if(!vis[i]) { dfs(i); cc++; }
        for(i=0; i<n; i++) quant[vis[i]]++;
        for(i=1; i<cc; i++) if(quant[i]>k) resp=max(resp, quant[i]);
        printf("%d\n", resp);
    }
    return 0;
}

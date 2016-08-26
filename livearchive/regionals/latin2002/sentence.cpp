#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> grafo[2000];
int ccnt[2000], csize[2000];
int vis[2000], cc, n;

void dfs(int u)
{
    int i, v;
    vis[u]=cc;
    csize[cc]++;
    if(u < n) ccnt[cc]++;
    for(i=0; i<grafo[u].size(); i++)
    {
        v=grafo[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    int i, id, resp, f;
    char s[20], is[5], v[20];
    while(scanf("%d", &n) && n)
    {
        for(i=0; i<2*n; i++)
        {
            grafo[i].clear();
            vis[i] = 0;
            ccnt[i] = 0;
            csize[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%s %d %s %s", s, &id, is, v);
            id--;
            if(v[0]=='f')
            {
                grafo[i].push_back(n+id);
                grafo[n+id].push_back(i);
                grafo[n+i].push_back(id);
                grafo[id].push_back(n+i);
            }
            else
            {
                grafo[i].push_back(id);
                grafo[id].push_back(i);
                grafo[n+i].push_back(n+id);
                grafo[n+id].push_back(n+i);
            }
        }
        cc=1;
        for(i=0; i<2*n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cc++;
            }
        }
        f = 0;
        resp = 0;
        for(i=0;i<n;i++) if(vis[i] == vis[n+i]) { f=1; break;}
        for(i=1;i<cc;i++)
        {
            resp += max(ccnt[i],csize[i]-ccnt[i]);
        }
        if(f) printf("Inconsistent\n");
        else printf("%d\n", resp/2);
    }
    return 0;
}

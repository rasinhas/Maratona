#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> grafo[30000], ginv[30000];
int vis[30000], vinv[30000], ord[30000], q, cc;

void dfs(int u)
{
    int i, v;
    vis[u]=1;
    for(i=0; i<grafo[u].size(); i++)
    {
        v=grafo[u][i];
        if(!vis[v]) dfs(v);
    }
    ord[q++]=u;
}

void dfsinv(int u)
{
    int i, v;
    vinv[u]=cc;
    for(i=0; i<ginv[u].size(); i++)
    {
        v=ginv[u][i];
        if(!vinv[v]) dfsinv(v);
    }
}

int main()
{
    int i, c, p, x, y, s, t;
    while(scanf("%d %d", &c, &p) && c)
    {
        for(i=0; i<2*p+3; i++)
        {
            grafo[i].clear();
            ginv[i].clear();
            vis[i]=vinv[i]=0;
            ord[i]=-1;
        }
        for(i=0; i<c; i++)
        {
            scanf("%d %d %d %d", &x, &y, &s, &t);
            if(x == 0 && y != 0)
            {
                grafo[y+p+1].push_back(y);
                ginv[y].push_back(y+p+1);
            }
            else if(x != 0 && y == 0)
            {
                grafo[x+p+1].push_back(x);
                ginv[x].push_back(x+p+1);
            }
            else if(x != 0 && y != 0)
            {
                grafo[x+p+1].push_back(y);
                grafo[y+p+1].push_back(x);
                ginv[y].push_back(x+p+1);
                ginv[x].push_back(y+p+1);
            }
            if(s == 0 && t != 0)
            {
                grafo[t].push_back(t+p+1);
                ginv[t+p+1].push_back(t);
            }
            else if(s != 0 && t == 0)
            {
                grafo[s].push_back(s+p+1);
                ginv[s+p+1].push_back(s);
            }
            else if(s != 0 && t != 0)
            {
                grafo[s].push_back(t+p+1);
                grafo[t].push_back(s+p+1);
                ginv[t+p+1].push_back(s);
                ginv[s+p+1].push_back(t);
            }
        }
        int j;
        /*for(i=0; i<2*p+3; i++)
        {
            for(j=0; j<grafo[i].size(); j++)
                printf("%d ", grafo[i][j]);
            printf("\n");
        }
        printf("\n");*/
        q=0;
        cc=1;
        for(i=0; i<2*p+3; i++) if(!vis[i]) dfs(i);
        for(i=2*p+2; i>=0; i--) if(!vinv[ord[i]]) { dfsinv(ord[i]); cc++; }
        int flag=0;
        for(i=0; i<p+1; i++) if(vinv[i]==vinv[i+p+1]) { flag=1; break; }
        if(flag) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}

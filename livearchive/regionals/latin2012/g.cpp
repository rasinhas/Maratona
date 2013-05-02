#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define vertex(u,v) (u*c)+(v)+1
#define pb push_back
#define sz size()
#define nil 0
#define inf 0x3f3f3f3f

using namespace std;

int r,c;
int match[2505], dist[2505];
vector <int> adj[2505], w;
char grid[60][60];
int gridvis[60][60];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int cnt;

/*
    Hopcroft Karp
    Define o match de todos os vertices como NIL
    Divide o grafo em dois subconjuntos (branco/w = 1 e preto/b = 2)
    Seleciona um dos subconjuntos como ponto de partida (nesse caso parti de w)
    Executa um BFS para encontrar a distancia de todos os vertices a um vertice
    livres (vertice de w que não tem match) enquanto algum vértice estiver sem match
    Para cada vértice de w que não tem matching realiza um dfs que procura um matching
    se o dfs encontrar um matching, incrementa o contador de matchings
*/

bool bfs()
{
    int u, v;
    queue <int> q;
    for(int i=0;i<w.size();i++)
    {
        if(match[w[i]] == nil)
        {
            dist[w[i]] = 0;
            q.push(w[i]);
        }
        else dist[w[i]] = inf;
    }
    dist[nil] = inf;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u!=nil)
        {
            for(int i=0;i<adj[u].size();i++)
            {
                v = adj[u][i];
                if(dist[match[v]] == inf)
                {
                    dist[match[v]] = dist[u]+1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (dist[nil]!=inf);
}

bool dfs(int u)
{
    int i, v;
    if(u!=nil)
    {
        for(int i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            if(dist[match[v]] == dist[u]+1 && dfs(match[v]))
            {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        dist[u] = inf;
        return false;
    }
    return true;
}

int hopcroft_karp()
{
    int matching = 0;
    while(bfs()) for(int i=0;i<w.size();i++) if(match[w[i]] == nil && dfs(w[i])) matching++;
    return matching;
}

int in(int x, int y) { return (x>-1 && x<r && y>-1 && y<c); }

void dfsgrid(int u, int v, int g)
{
    int nu, nv;
    gridvis[u][v] = g;
    if(gridvis[u][v] == 1) w.pb(vertex(u,v));
    cnt++;
    for(int i=0;i<4;i++)
    {
        nu = u+dx[i];
        nv = v+dy[i];
        if(in(nu,nv) && grid[nu][nv] == '.')
        {
            if(gridvis[u][v] == 1) adj[vertex(u,v)].pb(vertex(nu,nv));
            if(!gridvis[nu][nv]) dfsgrid(nu,nv,1+(g%2));
        }
    }
}

// executa um Hopcroft Karp e verifica se max matching = V/2.
// Se for perfect matching -> 2 ganha. Se algum não for perfect matching -> 1 ganha.

int main()
{
    int i, j, k, f, u, v, co[2];
    while(scanf("%d%d", &r, &c) != EOF)
    {
        memset(gridvis,0,sizeof(gridvis));
        memset(match,0,sizeof(match));
        memset(dist,0,sizeof(dist));
        for(i=0; i<r*c+2; i++) adj[i].clear();
        w.clear();
        cnt = 0;
        for(i=0;i<r;i++) scanf("%s", grid[i]);
        for(i=0; i<r; i++) for(j=0; j<c; j++) if(grid[i][j]=='.' && !gridvis[i][j]) dfsgrid(i, j, 1); 
        if(cnt != 2*hopcroft_karp()) printf("1\n");
        else printf("2\n");
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[400000];
int vis[400000];

// DFS estoura a pilha.
void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++) if(!vis[adj[u][i]]) dfs(adj[u][i]);
}

void bfs(int p)
{
    int v, u;
    int i;
    queue <int> q;
    q.push(p);
    vis[p] = 1;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(i=0;i<adj[v].size();i++)
        {
            u = adj[v][i];
            if(!vis[u])
            {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
}

int main()
{
    int n;
    int i, j, cc;
    string str;
    while(scanf("%d", &n) != EOF)
    {
        for(i=0;i<(2*n)*(2*n+1);i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        // entrada
        for(i=0;i<(2*n)-1;i++)
        {
            cin >> str;
            for(j=0;j<str.size();j++)
            {
                if(str[j] == 'H')
                {
                    adj[((2*n)+1)*i+2*j+(i%2)].push_back(((2*n)+1)*i+2*j+1+(i%2)); 
                    adj[((2*n)+1)*i+2*j+1+(i%2)].push_back(((2*n)+1)*i+2*j+(i%2)); 
                    adj[((2*n)+1)*(i+1)+2*j+(i%2)].push_back(((2*n)+1)*(i+1)+2*j+1+(i%2)); 
                    adj[((2*n)+1)*(i+1)+2*j+1+(i%2)].push_back(((2*n)+1)*(i+1)+2*j+(i%2)); 
                }
                else
                {
                    adj[((2*n)+1)*i+2*j+(i%2)].push_back(((2*n)+1)*(i+1)+2*j+(i%2)); 
                    adj[((2*n)+1)*(i+1)+2*j+(i%2)].push_back(((2*n)+1)*i+2*j+(i%2)); 
                    adj[((2*n)+1)*i+2*j+1+(i%2)].push_back(((2*n)+1)*(i+1)+2*j+1+(i%2)); 
                    adj[((2*n)+1)*(i+1)+2*j+1+(i%2)].push_back(((2*n)+1)*i+2*j+1+(i%2)); 
                }
            }
        }
        // presets
        for(i=0;i<(2*n);i++)
        {
            if(i%2 == 1)
            {
                //lin0
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
                //lin2n
                adj[(2*n-1)*((2*n+1))+i].push_back((2*n-1)*((2*n)+1)+i+1);
                adj[(2*n-1)*((2*n+1))+i+1].push_back((2*n-1)*((2*n)+1)+i);
                if(i < 2*n-1)
                {
                    //col0
                    adj[((2*n)+1)*i].push_back(((2*n)+1)*(i+1));
                    adj[((2*n)+1)*(i+1)].push_back(((2*n)+1)*i);
                }
            }
            else
            {
                //col2n+1
                adj[((2*n)+1)*i+((2*n))].push_back(((2*n)+1)*(i+1)+((2*n)));
                adj[((2*n)+1)*(i+1)+((2*n))].push_back(((2*n)+1)*i+((2*n)));
            }
        }
        cc=0;
        for(i=0;i<(2*n)*(2*n+1);i++)
        {
            if(!vis[i])
            {
                bfs(i);
                cc++;
            }
        }
        printf("%d\n", cc-1);
    }
    return 0;
}

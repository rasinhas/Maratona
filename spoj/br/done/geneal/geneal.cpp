#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    string pai, filho;
    vector <string> resp;
    int n, i, cont=1, len, u, init, fin, a;
    map <string, int> id;
    map <int, string> nome;
    vector <int> adj[2010];
    queue <int> fila;
    int vis[2010], d[2010];
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
            cin >> pai >> filho;
            if(!id[pai])
            {
                id[pai] = cont;
                nome[cont++] = pai;
            }
            if(!id[filho])
            {
                id[filho] = cont;
                nome[cont++] = filho;
            }
            adj[id[pai]].push_back(id[filho]);
            adj[id[filho]].push_back(id[pai]);
    }
    memset(vis,0,cont*sizeof(int));
    fila.push(1);
    while(!fila.empty())
    {
        a = fila.front();
        fila.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        init = a;
        len = adj[a].size();
        for(i=0;i<len;i++)
        {
            u = adj[a][i];
            if(!vis[u])
            {
                fila.push(u);
            }
        }
    }
    memset(vis,0,cont*sizeof(int));
    memset(d,0,cont*sizeof(int));
    fila.push(init);
    d[init] = 0;
    while(!fila.empty())
    {
        a = fila.front();
        fila.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        fin = a;
        len = adj[a].size();
        for(i=0;i<len;i++)
        {
            u = adj[a][i];
            if(!vis[u])
            {
                fila.push(u);
                d[u] = d[a]+1;
            }
        }
    }
    resp.push_back(nome[init]);
    resp.push_back(nome[fin]);
    sort(resp.begin(),resp.end());
    cout << resp[0] << " " << resp[1] << " " << d[fin] << endl;
    return 0;
}

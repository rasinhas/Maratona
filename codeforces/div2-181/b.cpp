#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int n, m, t, a, b, k, f, p, pmax, md;
int mat[50][50];
int vis[50];
int dfv[50];
int jok[50];
int team[50][3];
int par[2];

int dfs(int u, int d)
{
    dfv[u] = d;
    for(int i=0;i<n;i++)
    {
        if(mat[u][i] == 1)
        {
            if(!dfv[i])
            {
                dfs(i,d+1);
            }
            dfv[i] = min(dfv[i],d+1);
        }
    }
}

int main()
{
    cin >> n >> m;
    f = 0;
    md = 0;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--;b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    t = 0;
    p = 0;
    for(int i=0;i<n;i++)
    {
        k = 0;
        for(int j=0;j<n;j++) if(mat[i][j] == 1) k++;
        if(k > 2)
        {
            f = 1;
            break;
        }
    }
    for(int i=0;i<n;i++) 
    {
        if(!dfv[i])
        {
            dfs(i,0);
            if(md > 1)
            {
                f = 1; 
                break;
            }
        }
    }
    if(!f) for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            k = 0;
            vis[i] = 1;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 1)
                {
                    if(vis[j] == 2)
                    {
                        f = 1;
                        break;
                    }
                    par[k] = j;
                    k++;
                }
            }
            if(k == 0) jok[p++] = i;
            if(k == 2) 
            {
                team[t][0] = i+1;
                team[t][1] = par[0]+1;
                team[t++][2] = par[1]+1;
                vis[i] = 2;
                vis[par[0]] = 2;
                vis[par[1]] = 2;
            }
        }
        if(f) break;
    }
    pmax = p;
    p = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 1)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 1)
                {
                    if(p > pmax)
                    {
                        f = 1;
                        break;
                    }
                    team[t][0] = i+1;
                    team[t][1] = j+1;
                    team[t++][2] = jok[p]+1;
                    vis[i] = 2;
                    vis[j] = 2;
                    vis[jok[p++]] = 2;
                }
            }
        }
        if(f) break;
    }
    if(!f) while(p < pmax)
    {
        team[t][0] = jok[p]+1;
        vis[jok[p++]] = 2;
        team[t][1] = jok[p]+1;
        vis[jok[p++]] = 2;
        team[t++][2] = jok[p]+1;
        vis[jok[p++]] = 2;
    }
    if(f) cout << "-1" << endl;
    else 
    {
        for(int i=0;i<t;i++) cout << team[i][0] << " " << team[i][1] << " " << team[i][2] << endl;
    }
    return 0;
}

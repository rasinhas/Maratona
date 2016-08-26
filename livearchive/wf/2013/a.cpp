#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int adj[52][52];
int vis[52];
int ok = 0;
int o;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<52;i++) 
    {
        int v = (i%2 ? i-1 : i+1);
        if(adj[u][i])
        {
            if(i == o) ok = 1;
            if(ok) return;
            if(!vis[v]) dfs(v);
        }
    }
}

int main()
{
    int n;
    string s;
    while(scanf("%d", &n) != EOF)
    {
        ok = 0;
        memset(vis,0,sizeof(vis));
        memset(adj,0,sizeof(adj));
        for(int i=0;i<n;i++)
        {
            cin >> s;
            for(int j=0;j<4;j++)
            {
                if(s[2*j] == '0') continue;
                int l = 2*(s[2*j] - 'A') + (s[2*j+1] == '+' ? 0 : 1);
                for(int k=j+1;k<4;k++)
                {
                    if(s[2*k] == '0') continue;
                    int l2 = 2*(s[2*k] - 'A') + (s[2*k+1] == '+' ? 0 : 1);
                    adj[l][l2] = adj[l2][l] = 1;
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            memset(vis,0,sizeof(vis));
            o = 2*i+1;
            dfs(2*i);
            if(ok) break;
        }
        cout << (ok ? "unbounded" : "bounded") << endl;
    }
    return 0;
}

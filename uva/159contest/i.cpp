#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int adj[33][33];
int cc[33];
int vis[33];
int cycles[33];
int c;

void build(string s)
{
    for(int i=0;i<s.size();i++) adj[i][s[i]-'A'] = 1;
}

bool dfs(int u)
{
    vis[u] = c;
    for(int i=0;i<26;i++) if(adj[u][i] && !vis[i]) dfs(i);
}

int main()
{
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        c = 1;
        int f=0;
        cin >> s;
        memset(vis,0,sizeof(vis));
        memset(cc,0,sizeof(cc));
        memset(cycles,0,sizeof(cycles));
        memset(adj,0,sizeof(adj));
        build(s);
        for(int i=0;i<26;i++) if(!vis[i]) 
        {
            dfs(i);
            c++;
        }
        for(int i=0;i<26;i++) cc[vis[i]]++;
        while(--c) cycles[cc[c]]++;
        for(int i=0;i<27;i+=2) if(cycles[i]%2) f=1;
        cout << (f ? "No" : "Yes") << endl;
    }
    return 0;
}

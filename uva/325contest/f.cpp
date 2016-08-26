#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cyc[1111], s[1111], ord[1111], vis[1111], c;

void dfs(int u, int d)
{
    vis[u] = c;
    if(!vis[cyc[u]]) dfs(cyc[u],d+1);
    else s[c] = d+1;
}

int go(int u, int d)
{
    if(d == 0) return u;
    return go(cyc[u],d-1);
}

int main()
{
    long long r;
    int n, k;
    while(scanf("%d%lld", &n, &r) != EOF)
    {
        c = 1;
        memset(s,0,sizeof(s));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            cin >> k;
            cyc[k-1] = i;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) dfs(i, 0);
            c++;
        }
        for(int i=0;i<n;i++) ord[go(i,r%s[vis[i]])] = i;
        for(int i=0;i<n;i++)
        {
            if(i > 0) cout << " ";
            cout << ord[i]+1;
        }
        cout << endl;
    }
    return 0;
}

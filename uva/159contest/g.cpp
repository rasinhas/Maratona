#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define mp make_pair
#define pb push_back

using namespace std;

vector <int> p;
int bad[11111];
vector <int> adj[11111];
int vis[111111];

bool sieve(int n)
{
    bad[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if(bad[i]) continue;
        else 
        {
            if(i > 1000) p.pb(i);
            for(int j=2*i;j<=n;j+=i) bad[j] = 1;
        }
    }
}

bool is_similar(int a, int b)
{
    int r=0;
    if(a%10 == b%10) r++;
    if((a/10)%10 == (b/10)%10) r++;
    if((a/100)%10 == (b/100)%10) r++;
    if((a/1000) == (b/1000)) r++;
    if(r == 3) return 1;
    return 0;
}

int bfs(int a, int b)
{
    queue <int> q;
    q.push(a);
    vis[a] = 1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i];
            if(!vis[u])
            {
                vis[u] = vis[v]+1;
                q.push(u);
            }
        }
        if(vis[b]) return 1;
    }
    return 1e9;
}

int main()
{
    int t;
    cin >> t;
    sieve(9999);
    for(int i=0;i<p.size();i++) 
    {
        for(int j=i;j<p.size();j++)
        {
            if(is_similar(p[i],p[j])) 
            {
                adj[p[i]].pb(p[j]); 
                adj[p[j]].pb(p[i]);
            }
        }
    }
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        memset(vis,0,sizeof(vis));
        if(bfs(a,b) != 1e9) cout << vis[b]-1 << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}

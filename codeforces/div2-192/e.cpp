#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define sz size()

using namespace std;

int valid[111111];
vector <int> adj[111111];
int v[111111];

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0;i<m;i++) 
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=0;i<n;i++) v[i] = i+1;
    int t, k;
    for(t=0;t<100;t++)
    {
        k = 0;
        random_shuffle(v,v+n);
        for(int i=0;i<n;i++) valid[i] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[v[i]].sz;j++) if(adj[v[i]][j] == v[(i+1)%n]) valid[i] = 0;
            if(valid[i]) k++;
            if(k == m) break;
        }
        if(k == m) break;
    }
    if(t == 100) cout << -1 << endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(valid[i])
            {
                cout << v[i] << " " << v[(i+1)%n] << endl;
                k--;
            }
            if(!k) break;
        }
    }
    return 0;
}

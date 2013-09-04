#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[16][16] = { {0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
                    {1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
                    {1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0},
                    {0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0},
                    {1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0},
                    {0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0},
                    {0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0},
                    {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0},
                    {0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0},
                    {0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0},
                    {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1},
                    {0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0},
                    {0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1},
                    {0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1},
                    {0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0} };

int obj = (1<<16)-(1<<8);
int best;
int vis[(1<<16)+2];

void bfs(int mask, int d)
{
    queue <pair<int,int> > q;
    q.push(make_pair(mask,d));
    while(!q.empty())
    {
        int u = q.front().first;
        int dd = q.front().second;
        vis[u] = dd;
        q.pop();
        for(int i=0;i<16;i++)
        {
            if(u&(1<<i)) for(int j=0;j<16;j++) if(adj[i][j] && !(u&(1<<j)))
            {
                int v = u - (1<<i) + (1<<j);
                if(vis[v] == -1 && dd < 3) q.push(make_pair(v,dd+1));
            }
        }
    }
}

int main()
{
    int T;
    int p, m;
    cin >> T;
    for(int i=0;i<(1<<16);i++) vis[i] = -1;
    bfs(obj,0);
    for(int t=1;t<=T;t++)
    {
        m = 0;
        for(int i=0;i<16;i++)
        {
            cin >> p;
            m += (p<<i);
        }
        printf("Case #%d: ", t);
        if(vis[m]>-1) cout << vis[m] << endl;
        else cout << "more" << endl;
    }
    return 0;
}

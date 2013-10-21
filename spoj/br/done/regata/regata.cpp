#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define EPS 1e-6
#define INF 1e9
#define xx first
#define yy second
const double PI = acos(-1);

using namespace std;

vector<pair<int, int> > pto;
vector<pair<pair<int, int>, pair<int, int> > > seg;

int mod(int a) { return a > 0 ? a : -a;}

int prod(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
}

bool intercepta(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int p1 = prod(x1, y1, x2, y2, x3, y3);
    int p2 = prod(x1, y1, x2, y2, x4, y4);
    int p3 = prod(x3, y3, x4, y4, x1, y1);
    int p4 = prod(x3, y3, x4, y4, x2, y2);
    if (p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0) return false;
    int s1 = p1 / mod(p1);
    int s2 = p2 / mod(p2);
    int s3 = p3 / mod(p3);
    int s4 = p4 / mod(p4);
    return s1 != s2 && s3 != s4;
}

double distancia(int x1, int y1, int x2, int y2)
{
    int S = seg.size();
    for(int i=0;i<S;i++) if(intercepta(x1, y1, x2, y2, seg[i].first.first, seg[i].first.second, seg[i].second.first, seg[i].second.second)) return INF;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double ds[333][333], dm[333];
int vis[333];

int main()
{
    int n, x1, x2, y1, y2;
    while(scanf("%d%d%d%d%d",&x1, &y1, &x2, &y2, &n) && (x1|x2|y1|y2|n))
    {
        vector <int> adj[333];
        memset(vis,0,sizeof(vis));
        pto.clear();
        seg.clear();
        pto.push_back(make_pair(x1,y1));
        pto.push_back(make_pair(x2,y2));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            pto.push_back(make_pair(x1,y1));
            pto.push_back(make_pair(x2,y2));
            seg.push_back(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
        }
        for(int i=0;i<2*n+2;i++) for(int j=i+1;j<2*n+2;j++) 
        {
            ds[i][j] = ds[j][i] = distancia(pto[i].xx, pto[i].yy, pto[j].xx, pto[j].yy);
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        for(int i=0;i<2*n+2;i++) dm[i] = INF;
        dm[0] = 0;
        priority_queue <pair<double,int> > q;
        q.push(make_pair(0.0,0));
        while(!q.empty())
        {
            int u = q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            if(u == 1) break;
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i];
                if(!vis[v] && dm[v] > dm[u]+ds[u][v])
                {
                    dm[v] = dm[u] + ds[u][v];
                    q.push(make_pair(-dm[v],v));
                }
            }
        }
        printf("%.2lf\n", dm[1]);
    }
    return 0;
}

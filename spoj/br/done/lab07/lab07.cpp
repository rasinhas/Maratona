#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair

using namespace std;

int dx[] = {0,0,1,-1,0};
int dy[] = {1,-1,0,0,0};
int lab[55][55];
int vis[55][55][10]; // linha / coluna / altura
int n, m;

typedef pair<int,int> pii;

bool in(pii p) {return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);}

bool cango(pii p, pii np, int r)
{
    return (((lab[p.first][p.second]+r)%10)+1 >= ((lab[np.first][np.second]+r)%10));
}

int bfs(int a, int b)
{
    //linha / coluna / rodada
    queue <pair<pair<int,int>,int> > q;
    pair <int,int> v, nv;
    int r, h;
    q.push(mp(mp(a,b),0));
    while(!q.empty())
    {
        v = q.front().first;
        r = q.front().second;
        if(v.first == n-1 && v.second == m-1) return r;
        q.pop();
        h = (lab[v.first][v.second]+r)%10;
        if(vis[v.first][v.second][h]) continue;
        vis[v.first][v.second][h] = 1;
        for(int i=0;i<5;i++)
        {
            nv = mp(v.first+dx[i], v.second+dy[i]);
            h = (lab[nv.first][nv.second]+r+1)%10;
            if(in(nv) && cango(v,nv,r) && !vis[nv.first][nv.second][h]) q.push(mp(nv,r+1));
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> lab[i][j];
    cout << bfs(0,0) << endl;
    return 0;
}
